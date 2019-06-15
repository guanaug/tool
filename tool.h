#ifndef TOOL_H
#define TOOL_H

#include <QWidget>

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

private:
    Ui::tool *ui;
};

#endif // TOOL_H
