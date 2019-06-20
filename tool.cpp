#include <QCryptographicHash>
#include <QtNetwork/QNetworkReply>
#include <QJsonParseError>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <iostream>
#include "tool.h"
#include "ui_tool.h"
#include "dialupdate.h"
#include "ui_dialupdate.h"

tool::tool(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tool)
{
    ui->setupUi(this);
    checkUpdate();
}

tool::~tool()
{
    delete ui;
}

void tool::on_btnBase64Enc_clicked()
{
    QString strPlain = ui->txtBase64Input->toPlainText().trimmed();
    ui->txtBase64Show->setText(strPlain.toLocal8Bit().toBase64());
}

void tool::on_btnBase64Dec_clicked()
{
    QString strEnc = ui->txtBase64Input->toPlainText().trimmed();
    ui->txtBase64Show->setText(QByteArray::fromBase64(strEnc.toLocal8Bit()));
}

void tool::on_btnBase64_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->pageBase64);
}

void tool::on_btnMD5_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->pageMD5);
}

void tool::on_btnMD5Enc_clicked()
{
    QByteArray byteMD5;
    QCryptographicHash hash(QCryptographicHash::Md5);
    QString strPlain = ui->txtMD5Input->toPlainText().trimmed();

    hash.addData(strPlain.toLocal8Bit());
    byteMD5 = hash.result().toHex();

    if (ui->rBtnMD5Upper->isChecked()) {
        ui->txtMD5Show->setText(QString::fromStdString(byteMD5.toUpper().toStdString()));
    } else if (ui->rBtnMD5Lower->isChecked()) {
        ui->txtMD5Show->setText(QString::fromStdString(byteMD5.toLower().toStdString()));
    }
}

void tool::on_rBtnMD5Upper_clicked()
{
    QString str = ui->txtMD5Show->toPlainText().trimmed();
    ui->txtMD5Show->setText(str.toUpper());
}

void tool::on_rBtnMD5Lower_clicked()
{
    QString str = ui->txtMD5Show->toPlainText().trimmed();
    ui->txtMD5Show->setText(str.toLower());
}

void tool::update(QNetworkReply *reply)
{
    if (reply->error() != QNetworkReply::NoError) {
        std::cout << "update error" << std::endl;
        return;
    }

    QByteArray resp =  reply->readAll();
    QJsonParseError error;
    QJsonDocument doc = QJsonDocument::fromJson(resp, &error);
    if (error.error != QJsonParseError::NoError) {
        std::cout << "parse json error" << std::endl;
        return;
    }

    QJsonObject rootObj = doc.object();
    QString version = rootObj.value("tag_name").toString();
    if (version == CURR_VERSION) {
        return;
    }

    QJsonArray assets = rootObj.value("assets").toArray();
    QString assetUrl = assets[0].toObject().value("browser_download_url").toString();
    QString descript = rootObj.value("body").toString();

    diagUpdate = new DialUpdate;
    diagUpdate->assetUrl = assetUrl;
    diagUpdate->ui->labDiagUpdateVersion->setText(version);
    diagUpdate->ui->txtDialUpdateDescript->setText(descript);
    diagUpdate->show();
}

void tool::checkUpdate()
{
    QNetworkAccessManager *networkManager = new QNetworkAccessManager();
    QObject::connect(networkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(update(QNetworkReply*)));

    networkManager->get(QNetworkRequest(QUrl(UPDATE_URL)));
}
