#ifndef DIALUPDATE_H
#define DIALUPDATE_H

#include <QDialog>

namespace Ui {
class DialUpdate;
}

class DialUpdate : public QDialog
{
    Q_OBJECT

public:
    friend class tool;
    explicit DialUpdate(QWidget *parent = nullptr);
    ~DialUpdate();

private slots:
    void on_buttonBox_rejected();

    void on_buttonBox_accepted();

private:
    Ui::DialUpdate *ui;
    QString assetUrl;
};

#endif // DIALUPDATE_H
