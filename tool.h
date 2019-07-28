#ifndef TOOL_H
#define TOOL_H

#include <QWidget>
#include <QtNetwork/QNetworkAccessManager>
#include <dialupdate.h>

const QString CURR_VERSION = "v1.4.0";
const QString UPDATE_URL = "https://api.github.com/repos/guanjialin/tool/releases/latest";

namespace Ui {
class tool;
}

class tool : public QWidget
{
    Q_OBJECT

public:
    explicit tool(QWidget *parent = nullptr);
    ~tool();

private slots:
    void on_btnBase64Enc_clicked();

    void on_btnBase64Dec_clicked();

    void on_btnMD5_clicked();

    void on_btnBase64_clicked();

    void on_btnMD5Enc_clicked();

    void on_rBtnMD5Upper_clicked();

    void on_rBtnMD5Lower_clicked();

    void update(QNetworkReply*);

    void updateTime();

    void on_btnJSONFormat_clicked();

    void on_btnTimestamp_clicked();

    void on_btnConvert2Timestamp_clicked();

    void on_btnConvert2Time_clicked();

    void on_cbWinTop_clicked(bool checked);

    void on_btnRefresh_clicked();

private:
    Ui::tool *ui;
    DialUpdate *diagUpdate;

private:
    void checkUpdate();
    void initUi();
    void initSignal();
};

#endif // TOOL_H
