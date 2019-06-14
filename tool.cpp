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

void tool::on_btnMD5_clicked()
{
    ui->widgetBase64->hide();
}
