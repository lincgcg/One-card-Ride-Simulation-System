#include "logonmainwindow.h"
#include "ui_logonmainwindow.h"

LogonMainWindow::LogonMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LogonMainWindow)
{
    ui->setupUi(this);
    ui->data_gender->addItem(tr("女").trimmed(),0);
        ui->data_gender->addItem(tr("男").trimmed(),1);
    ui->data_identity->addItem(tr("学生").trimmed(),STUDENT);
    ui->data_identity->addItem(tr("教师").trimmed(),TEACHER);
    ui->data_identity->addItem(tr("教师家属").trimmed(),TEACHER_FAMILY);
}

LogonMainWindow::~LogonMainWindow()
{
    delete ui;
}

void LogonMainWindow::logonMainwindow_show() {

    ui->data_identity->setEnabled(true);

    ui->data_college->setEnabled(false);

    ui->data_gender->setEnabled(false);

    ui->data_name->setEnabled(false);
    ui->data_number->setEnabled(false);


    this->show();
}

void LogonMainWindow::on_button_identity_clicked()
{
    ui->data_identity->setEnabled(false);
    identity = ui->data_identity->currentIndex();
    if(ui->data_identity->currentIndex()==STUDENT||ui->data_identity->currentIndex()==TEACHER) {
        //学院
        ui->data_college->clear();
        ui->data_college->setEnabled(true);
        //性别
        ui->data_gender->setEnabled(true);
        //姓名
        ui->data_name->clear();
        ui->data_name->setEnabled(true);
        //号码
        ui->data_number->clear();
        ui->data_number->setEnabled(true);
    }//if(ui->data_identity->currentIndex()==STUDENT||ui->data_identity->currentIndex()==TEACHER)
    if(ui->data_identity->currentIndex() == TEACHER_FAMILY) {
        //性别
        ui->data_gender->setEnabled(true);
        //姓名
        ui->data_name->clear();
        ui->data_name->setEnabled(true);
    }//if(ui->data_identity->currentIndex()

}

void LogonMainWindow::on_button_sure_clicked()
{
    if(identity==STUDENT||identity==TEACHER) {
        if(ui->data_number->toPlainText().isEmpty()||ui->data_college->toPlainText().isEmpty()||
                ui->data_name->toPlainText().isEmpty()) {
            QMessageBox q(this);
            q.setWindowTitle("注册结果");
            q.setText("<font size = '40' color = 'red'><p align='center'>注册失败！<\p></font>"
                      "<font size = '40' color = 'red'>信息不能有空！</font>");
            q.setIcon(QMessageBox::NoIcon);
            q.setStandardButtons(QMessageBox::Ok);
            if(q.exec()==QMessageBox::Ok)
                q.close();
        }
        else {
            if(identity == STUDENT) {
                QString filename = "C:\\Users\\LINCGCG\\Desktop\\Qt\\test4\\data\\student.csv";
                std::string name = ui->data_name->toPlainText().toStdString();
                int gander = ui->data_gender->currentIndex();
                std::string card = ui->data_number->toPlainText().toStdString();
                std::string college = ui->data_college->toPlainText().toStdString();

                student *stu = new student(name,gander,STUDENT,0,card,college);
                if(data::savedata(filename, &stu)) {
                    QMessageBox q(this);
                    q.setWindowTitle("注册结果");
                    q.setText("<font size = '40' color = 'red'><p align='center'>注册失败！<\p></font>"
                              "<font size = '40' color = 'red'>用户已存在！</font>");
                    q.setIcon(QMessageBox::NoIcon);
                    q.setStandardButtons(QMessageBox::Ok);
                    if(q.exec()==QMessageBox::Ok)
                        q.close();
                }
                else {
                    QMessageBox q(this);
                    q.setWindowTitle("注册结果");
                    q.setText("<font size = '40' color = 'green'>注册成功！</font>");
                    q.setIcon(QMessageBox::NoIcon);
                    q.setStandardButtons(QMessageBox::Ok);
                    if(q.exec()==QMessageBox::Ok)
                        q.close();
                }
            }
            if(identity == TEACHER) {
                QString filename = "C:\\Users\\LINCGCG\\Desktop\\Qt\\test4\\data\\teacher.csv";
                std::string name = ui->data_name->toPlainText().toStdString();
                int gander = ui->data_gender->currentIndex();
                std::string card = ui->data_number->toPlainText().toStdString();
                std::string college = ui->data_college->toPlainText().toStdString();

                teacher *tea = new teacher(name,gander,TEACHER,0,card,college);
                if(data::savedata(filename, &tea)) {
                    QMessageBox q(this);
                    q.setWindowTitle("注册结果");
                    q.setText("<font size = '40' color = 'red'><p align='center'>注册失败！<\p></font>"
                              "<font size = '40' color = 'red'>用户已存在！</font>");
                    q.setIcon(QMessageBox::NoIcon);
                    q.setStandardButtons(QMessageBox::Ok);
                    if(q.exec()==QMessageBox::Ok)
                        q.close();
                }
                else {
                    QMessageBox q(this);
                    q.setWindowTitle("注册结果");
                    q.setText("<font size = '40' color = 'green'>注册成功！</font>");
                    q.setIcon(QMessageBox::NoIcon);
                    q.setStandardButtons(QMessageBox::Ok);
                    if(q.exec()==QMessageBox::Ok)
                        q.close();
                }
            }
        }
    }
    if(identity == TEACHER_FAMILY) {
        if(ui->data_name->toPlainText().isEmpty()) {
            QMessageBox q(this);
            q.setWindowTitle("注册结果");
            q.setText("<font size = '40' color = 'red'><p align='center'>注册失败！<\p></font>"
                      "<font size = '40' color = 'red'>信息不能有空！</font>");
            q.setIcon(QMessageBox::NoIcon);
            q.setStandardButtons(QMessageBox::Ok);
            if(q.exec()==QMessageBox::Ok)
                q.close();
        }
        else {
            if(identity == TEACHER_FAMILY) {
                QString filename = "C:\\Users\\LINCGCG\\Desktop\\Qt\\test4\\data\\teafam.csv";
                std::string name = ui->data_name->toPlainText().toStdString();
                int gander = ui->data_gender->currentIndex();
                std::string card = "\n";
                std::string college = "";
                teacher_family *teafam = new teacher_family(name,gander,TEACHER_FAMILY,0,card,college);
                if(data::savedata(filename, &teafam)) {
                    QMessageBox q(this);
                    q.setWindowTitle("注册结果");
                    q.setText("<font size = '40' color = 'red'><p align='center'>注册失败！<\p></font>"
                              "<font size = '40' color = 'red'>用户已存在！</font>");
                    q.setIcon(QMessageBox::NoIcon);
                    q.setStandardButtons(QMessageBox::Ok);
                    if(q.exec()==QMessageBox::Ok)
                        q.close();
                }
                else {
                    QMessageBox q(this);
                    q.setWindowTitle("注册结果");
                    q.setText("<font size = '40' color = 'green'>注册成功！</font>");
                    q.setIcon(QMessageBox::NoIcon);
                    q.setStandardButtons(QMessageBox::Ok);
                    if(q.exec()==QMessageBox::Ok)
                        q.close();
                }
            }
        }
    }
    this->ui->data_college->clear();
    this->ui->data_name->clear();
    this->ui->data_number->clear();
    this->close();
}
