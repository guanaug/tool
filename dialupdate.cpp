#include <QDesktopServices>
#include <QtDebug>
#include "dialupdate.h"
#include "ui_dialupdate.h"

DialUpdate::DialUpdate(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialUpdate)
{
    ui->setupUi(this);
}

DialUpdate::~DialUpdate()
{
    delete ui;
}

void DialUpdate::on_buttonBox_rejected()
{
    this->hide();
}

void DialUpdate::on_buttonBox_accepted()
{
    qDebug() << assetUrl;
    QDesktopServices::openUrl(QUrl(assetUrl));
}
