#include "functionselectionwindow.h"
#include "ui_functionselectionwindow.h"
#include <iostream>
FunctionSelectionWindow::FunctionSelectionWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FunctionSelectionWindow)
{
    ui->setupUi(this);
    re = new RechargeWindows();
    re->loadpicture();
    bi = new BusWindow();
}

FunctionSelectionWindow::~FunctionSelectionWindow()
{
    delete ui;
}

//“乘车”按钮
void FunctionSelectionWindow::on_ride_button_clicked()
{
    if(bi->bus_choose == -1) {
        QMessageBox q(this);
        q.setWindowTitle("乘车结果");
        q.setText("<font size='20'color='red'>  您此时不能乘车！<br></br></font>"
                  "<font size = '20' color = 'red'>有以下几种可能原因<br></br></font>"
                  "<font size = '20' color = 'red'>1.您未选择班车<br></br></font>"
                  "<font size = '20' color = 'red'>2.您所选时间没有班车<br></br></font>"
                  "<font size = '20' color = 'red'>3.班车达到载乘人数<br></br></font>");
        q.setIcon(QMessageBox::Warning);
        q.setStandardButtons(QMessageBox::Ok);
        if(q.exec()==QMessageBox::Ok)
            q.close();
        return;
    }
    //this->stu_user->set_Balance(stu_user->get_Balance()+this->re->get_money());
    bool islogout = false;
    bool unride = false;
    switch(this->user_id){
        case STUDENT: {
            if(this->stu_user->get_gander() == -1) {
                unride = true;
                islogout = true;
                break;
            }
            this->stu_user->set_Balance(stu_user->get_Balance()+this->re->get_money());
            if(this->stu_user->Consume_Bus()){
                if(this->stu_user->get_Balance()>5) {
                    QMessageBox q(this);
                    q.setWindowTitle("乘车结果");
                    q.setText(QString("<font size = '40' color = 'green'><p align='center'>乘车成功!<\p></font>"
                                      "<font size = '20' color = 'black'>姓名 : %1<br></br></font>"
                                      "<font size = '20' color = 'black'>余额 : %2<br></br></font>"
                                      "<font size = '20' color = 'black'><p align='center'>本月乘车次数 : %3<\p></font>"
                                      "").arg(QString::fromStdString(this->stu_user->get_name()),QString::number(this->stu_user->get_Balance(),'f',2),QString::number(stu_user->get_Number_bus())));
                    q.setIcon(QMessageBox::NoIcon);
                    q.setStandardButtons(QMessageBox::Ok);
                    if(q.exec()==QMessageBox::Ok)
                        q.close();
                } //if(this->stu_user->get_Balance()>5)
                else {
                    QMessageBox q(this);
                    q.setWindowTitle("乘车结果");
                    q.setText(QString("<font size = '40' color = 'green'><p align='center'>乘车成功!<\p></font>"
                                      "<font size = '20' color = 'black'><p align='center'>姓名 : %1<\p></font>"
                                      "<font size = '20' color = 'black'><p align='center'>余额 : %2<\p></font>"
                                      "<font size = '20' color = 'black'><p align='center'>本月乘车次数 : %3<\p></font>"
                                      "<font size = '40' color = 'red'><p align='center'>余额过低，请及时充值！<\p></font>"
                                      "").arg(QString::fromStdString(this->stu_user->get_name()),QString::number(this->stu_user->get_Balance(),'f',2),QString::number(stu_user->get_Number_bus())));
                    q.setIcon(QMessageBox::NoIcon);
                    q.setStandardButtons(QMessageBox::Ok);
                    if(q.exec()==QMessageBox::Ok)
                        q.close();
                } //else
            } //if(this->stu_user->Consume_Bus())
            else
                unride = true;
            break;
        } //case STUDENT:
        case TEACHER: {
            if(this->tea_user->get_gander() == -1) {
                unride = true;
                islogout = true;
                break;
            }
            this->tea_user->set_Balance(tea_user->get_Balance()+this->re->get_money());
            if(this->tea_user->Consume_Bus()){
                if(this->tea_user->get_Balance()>5) {
                    QMessageBox q(this);
                    q.setWindowTitle("乘车结果");
                    q.setText(QString("<font size = '40' color = 'green'><p align='center'>乘车成功!<\p></font>"
                                      "<font size = '20' color = 'black'>姓名 : %1<br></br></font>"
                                      "<font size = '20' color = 'black'>余额 : %2<br></br></font>"
                                      "<font size = '20' color = 'black'><p align='center'>本月乘车次数 : %3<\p></font>"
                                      "").arg(QString::fromStdString(this->tea_user->get_name()),QString::number(this->tea_user->get_Balance(),'f',2),QString::number(tea_user->get_Number_bus())));
                    q.setIcon(QMessageBox::NoIcon);
                    q.setStandardButtons(QMessageBox::Ok);
                    if(q.exec()==QMessageBox::Ok)
                        q.close();
                } //if(this->tea_user->get_Balance()>5)
                else {
                    QMessageBox q(this);
                    q.setWindowTitle("乘车结果");
                    q.setText(QString("<font size = '40' color = 'green'><p align='center'>乘车成功!<\p></font>"
                                      "<font size = '20' color = 'black'><p align='center'>姓名 : %1<\p></font>"
                                      "<font size = '20' color = 'black'><p align='center'>余额 : %2<\p></font>"
                                      "<font size = '20' color = 'black'><p align='center'>本月乘车次数 : %3<\p></font>"
                                      "<font size = '40' color = 'red'><p align='center'>余额过低，请及时充值！<\p></font>"
                                      "").arg(QString::fromStdString(this->tea_user->get_name()),QString::number(this->tea_user->get_Balance(),'f',2),QString::number(tea_user->get_Number_bus())));
                    q.setIcon(QMessageBox::NoIcon);
                    q.setStandardButtons(QMessageBox::Ok);
                    if(q.exec()==QMessageBox::Ok)
                        q.close();
                }//else
            } //if(this->tea_user->Consume_Bus())
            else
                unride = true;
            break;
        }//case TEACHER:
        case TEACHER_FAMILY: {
            if(this->teafam_user->get_gander() == -1) {
                unride = true;
                islogout = true;
                break;
            }
            this->teafam_user->set_Balance(teafam_user->get_Balance()+this->re->get_money());
            int result = this->teafam_user->Comsume_Bus();
            switch(result) {
                case 0: {
                    unride = true;
                    break;
                }//case 0:
                case 1: {
                    if(this->teafam_user->get_Balance()>5) {
                        QMessageBox q(this);
                        q.setWindowTitle("乘车结果");
                        q.setText(QString("<font size = '40' color = 'green'><p align='center'>乘车成功!<\p></font>"
                                          "<font size = '20' color = 'black'>姓名 : %1<br></br></font>"
                                          "<font size = '20' color = 'black'>余额 : %2<br></br></font>"
                                          "<font size = '20' color = 'black'><p align='center'>本月乘车次数 : %3<\p></font>"
                                          "").arg(QString::fromStdString(this->teafam_user->get_name()),QString::number(this->teafam_user->get_Balance(),'f',2),QString::number(teafam_user->get_Number_bus())));
                        q.setIcon(QMessageBox::NoIcon);
                        q.setStandardButtons(QMessageBox::Ok);
                        if(q.exec()==QMessageBox::Ok)
                            q.close();
                    }
                    else {
                        QMessageBox q(this);
                        q.setWindowTitle("乘车结果");
                        q.setText(QString("<font size = '40' color = 'green'><p align='center'>乘车成功!<\p></font>"
                                          "<font size = '20' color = 'black'><p align='center'>姓名 : %1<\p></font>"
                                          "<font size = '20' color = 'black'><p align='center'>余额 : %2<\p></font>"
                                          "<font size = '20' color = 'black'><p align='center'>本月乘车次数 : %3<\p></font>"
                                          "<font size = '40' color = 'red'><p align='center'>余额过低，请及时充值！<\p></font>"
                                          "").arg(QString::fromStdString(this->teafam_user->get_name()),QString::number(this->teafam_user->get_Balance(),'f',2),QString::number(teafam_user->get_Number_bus())));
                        q.setIcon(QMessageBox::NoIcon);
                        q.setStandardButtons(QMessageBox::Ok);
                        if(q.exec()==QMessageBox::Ok)
                            q.close();
                    }
                    break;
                }//case 1:
                case 2:{
                    if(this->teafam_user->get_Balance()>5) {
                        QMessageBox q(this);
                        q.setWindowTitle("乘车结果");
                        q.setText(QString("<font size = '40' color = 'green'><p align='center'>乘车成功!<\p></font>"
                                          "<font size = '40' color = 'red'><p align='center'>此次为本月最后一次免费乘车!<\p></font>"
                                          "<font size = '20' color = 'black'>姓名 : %1<br></br></font>"
                                          "<font size = '20' color = 'black'>余额 : %2<br></br></font>"
                                          "<font size = '20' color = 'black'><p align='center'>本月乘车次数 : %3<\p></font>"
                                          "").arg(QString::fromStdString(this->teafam_user->get_name()),QString::number(this->teafam_user->get_Balance(),'f',2),QString::number(teafam_user->get_Number_bus())));
                        q.setIcon(QMessageBox::NoIcon);
                        q.setStandardButtons(QMessageBox::Ok);
                        if(q.exec()==QMessageBox::Ok)
                            q.close();
                    }
                    else {
                        QMessageBox q(this);
                        q.setWindowTitle("乘车结果");
                        q.setText(QString("<font size = '40' color = 'green'><p align='center'>乘车成功!<\p></font>"
                                          "<font size = '40' color = 'red'><p align='center'>此次为本月最后一次免费乘车!<\p></font>"
                                          "<font size = '20' color = 'black'><p align='center'>姓名 : %1<\p></font>"
                                          "<font size = '20' color = 'black'><p align='center'>余额 : %2<\p></font>"
                                          "<font size = '20' color = 'black'><p align='center'>本月乘车次数 : %3<\p></font>"
                                          "<font size = '40' color = 'red'><p align='center'>余额过低，请及时充值！<\p></font>"
                                          "").arg(QString::fromStdString(this->teafam_user->get_name()),QString::number(this->teafam_user->get_Balance(),'f',2),QString::number(teafam_user->get_Number_bus())));
                        q.setIcon(QMessageBox::NoIcon);
                        q.setStandardButtons(QMessageBox::Ok);
                        if(q.exec()==QMessageBox::Ok)
                            q.close();
                    }
                    break;
                } //case 2:
                case 3: {
                    if(this->teafam_user->get_Balance()>5) {
                        QMessageBox q(this);
                        q.setWindowTitle("乘车结果");
                        q.setText(QString("<font size = '40' color = 'green'><p align='center'>乘车成功!<\p></font>"
                                          "<font size = '20' color = 'black'>姓名 : %1<br></br></font>"
                                          "<font size = '20' color = 'black'>余额 : %2<br></br></font>"
                                          "<font size = '20' color = 'black'><p align='center'>本月乘车次数 : %3<\p></font>"
                                          "").arg(QString::fromStdString(this->teafam_user->get_name()),QString::number(this->teafam_user->get_Balance(),'f',2),QString::number(teafam_user->get_Number_bus())));
                        q.setIcon(QMessageBox::NoIcon);
                        q.setStandardButtons(QMessageBox::Ok);
                        if(q.exec()==QMessageBox::Ok)
                            q.close();
                    }
                    else {
                        QMessageBox q(this);
                        q.setWindowTitle("乘车结果");
                        q.setText(QString("<font size = '40' color = 'green'><p align='center'>乘车成功!<\p></font>"
                                          "<font size = '20' color = 'black'><p align='center'>姓名 : %1<\p></font>"
                                          "<font size = '20' color = 'black'><p align='center'>余额 : %2<\p></font>"
                                          "<font size = '20' color = 'black'><p align='center'>本月乘车次数 : %3<\p></font>"
                                          "<font size = '40' color = 'red'><p align='center'>余额过低，请及时充值！<\p></font>"
                                          "").arg(QString::fromStdString(this->teafam_user->get_name()),QString::number(this->teafam_user->get_Balance(),'f',2),QString::number(teafam_user->get_Number_bus())));
                        q.setIcon(QMessageBox::NoIcon);
                        q.setStandardButtons(QMessageBox::Ok);
                        if(q.exec()==QMessageBox::Ok)
                            q.close();
                    }
                    break;
                }//case 3:
            }//switch(result)
        }//case TEACHER_FAMILY:
    }//switch(this->user_id)

    if(unride) {
       if(islogout) {
               //如果身份为-1，表示一卡通被注销
               QMessageBox q(this);
               q.setWindowTitle("乘车结果");
               q.setText("<font size='20'color='red'>一卡通已被注销！</font>");
               q.setIcon(QMessageBox::Warning);
               q.setStandardButtons(QMessageBox::Ok);
               if(q.exec()==QMessageBox::Ok)
                   q.close();
        } //if(this->stu_user->get_name().empty())
        else {
           QMessageBox q(this);
           q.setWindowTitle("乘车结果");
           q.setText("<font size='20'color='red'>余额不足！</font>");
           q.setIcon(QMessageBox::Warning);
           q.setStandardButtons(QMessageBox::Ok);
           if(q.exec()==QMessageBox::Ok)
               q.close();
       }
     }

}//void

//“余额充值按钮”
void FunctionSelectionWindow::on_recharge_button_clicked()
{
    this->re->show();

}//void

//“退出”按钮
void FunctionSelectionWindow::on_quit_button_clicked()
{
    switch(this->user_id) {
        case STUDENT: {
            this->stu_user->set_Balance(stu_user->get_Balance()+re->get_money());
            QString fname = "C:\\Users\\LINCGCG\\Desktop\\Qt\\test4\\data\\student.csv";
            data::savedata(fname,&(this->stu_user));
            this->bi->bus_choose = -1;
            break;
        }
        case TEACHER: {
            this->tea_user->set_Balance((tea_user->get_Balance()+re->get_money()));
            QString fname = "C:\\Users\\LINCGCG\\Desktop\\Qt\\test4\\data\\teacher.csv";
            data::savedata(fname,&(this->tea_user));
            this->bi->bus_choose = -1;
            break;
        }
        case TEACHER_FAMILY: {
            this->teafam_user->set_Balance(teafam_user->get_Balance()+re->get_money());
            QString fname = "C:\\Users\\LINCGCG\\Desktop\\Qt\\test4\\data\\teafam.csv";
            data::savedata(fname,&(this->teafam_user));
            this->bi->bus_choose = -1;
            break;
        }
    }
    this->close();
}

//注销按钮
void FunctionSelectionWindow::on_logout_button_clicked()
{
    switch(this->user_id) {
        case STUDENT: {
            this->stu_user->set_gander(-1);
            QString fname = "C:\\Users\\LINCGCG\\Desktop\\Qt\\test4\\data\\student.csv";
            data::savedata(fname,&(this->stu_user));
            break;
        }
        case TEACHER: {
            this->tea_user->set_gander(-1);
            QString fname = "C:\\Users\\LINCGCG\\Desktop\\Qt\\test4\\data\\teacher.csv";
            data::savedata(fname,&(this->tea_user));
            break;
        }
        case TEACHER_FAMILY: {
            this->teafam_user->set_gander(-1);
            QString fname = "C:\\Users\\LINCGCG\\Desktop\\Qt\\test4\\data\\teafam.csv";
            data::savedata(fname,&(this->teafam_user));
            break;
        }
    }
    QMessageBox q(this);
    q.setWindowTitle("注销结果");
    q.setText("<font size='20'color='red'>您的账户已被注销！</font>");
    q.setIcon(QMessageBox::Warning);
    q.setStandardButtons(QMessageBox::Ok);
    if(q.exec()==QMessageBox::Ok)
        q.close();
    this->close();
}
