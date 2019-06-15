#include <QCryptographicHash>
#include <iostream>
#include "tool.h"
#include "ui_tool.h"

tool::tool(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tool)
{
    ui->setupUi(this);
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
