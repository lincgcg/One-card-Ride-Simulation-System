#ifndef RECHARGEWINDOWS_H
#define RECHARGEWINDOWS_H

#include <QDialog>
#include <QImage>
#include <iostream>
#include <QMessageBox>

namespace Ui {
class RechargeWindows;
}

class RechargeWindows : public QDialog
{
    Q_OBJECT

public:
    explicit RechargeWindows(QWidget *parent = 0);
    ~RechargeWindows();
    void loadpicture();
    double get_money();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::RechargeWindows *ui;
    double recharge_money;
};

#endif // RECHARGEWINDOWS_H
