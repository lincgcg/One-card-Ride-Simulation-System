#include "rechargewindows.h"
#include "ui_rechargewindows.h"

RechargeWindows::RechargeWindows(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RechargeWindows)
{
    ui->setupUi(this);
    this->recharge_money = 0;
    this->setWindowTitle("充值界面");
}

RechargeWindows::~RechargeWindows()
{
    delete ui;
}

void RechargeWindows::loadpicture() {
    QPixmap pic1("C:\\Users\\LINCGCG\\Desktop\\Qt\\test4\\pic\\alipay2.jpg");
    QPixmap pic2("C:\\Users\\LINCGCG\\Desktop\\Qt\\test4\\pic\\wechat2.jpg");
    QPixmap dest1 = pic1.scaled(ui->picture1->size(), Qt::KeepAspectRatio);
    QPixmap dest2 = pic2.scaled(ui->picture2->size(), Qt::KeepAspectRatio);

    ui->picture1->setPixmap(dest1);
    ui->picture2->setPixmap(dest2);
}

double RechargeWindows::get_money() {
    double x = this->recharge_money;
    this->recharge_money = 0;
    return x;
}

void RechargeWindows::on_buttonBox_accepted()
{
     QString money = ui->recharge_number->toPlainText();
     this->recharge_money = money.toDouble();
     ui->recharge_number->clear();
     QMessageBox q(this);
     q.setWindowTitle("充值结果");
     q.setText("<font size = '40' color = 'green'>充值成功！</font>");
     q.setIcon(QMessageBox::NoIcon);
     q.setStandardButtons(QMessageBox::Ok);
     if(q.exec()==QMessageBox::Ok)
         q.close();
     q.show();
}
