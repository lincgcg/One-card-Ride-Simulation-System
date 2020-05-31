#include "identitywindow.h"
#include "ui_identitywindow.h"

IdentityWindow::IdentityWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::IdentityWindow)
{
    ui->setupUi(this);
    //初始化学生登录ui
    stu_signin = new StudentSigninDialog();
    stu_signin->setWindowTitle("学生登录");
    //初始化教师登录ui
    tea_signin = new TeacherSigninDialog();
    tea_signin->setWindowTitle("教师登录");
    //初始化教师家属登录ui
    teafam_signin = new TeacherFamilySigninDialog();
    teafam_signin->setWindowTitle("教师家属登录");

}

IdentityWindow::~IdentityWindow()
{
    delete ui;
}

//显示ui
void IdentityWindow::identitywindow_show()
{
    this->show();
}

//选择信号对应的槽函数
void IdentityWindow::link(bool islogon)
{
    if(islogon) {
        ;
    } //if
    else {
        connect(ui->id_student_button,SIGNAL(clicked()),stu_signin,SLOT(studentsignindialog_show()));
        connect(ui->id_teacher_button,SIGNAL(clicked()),tea_signin,SLOT(teachersignindialog_show()));
        connect(ui->id_teacher_family_button,SIGNAL(clicked()),teafam_signin,SLOT(teacherfamilysignindialog_show()));
    } //else
}

void IdentityWindow::on_id_student_button_clicked()
{
    this->close();
}

void IdentityWindow::on_id_teacher_button_clicked()
{
    this->close();
}

void IdentityWindow::on_id_teacher_family_button_clicked()
{
    this->close();
}
