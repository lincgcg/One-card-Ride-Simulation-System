#include "teachersignindialog.h"
#include "ui_teachersignindialog.h"
#include <iostream>
#include "data.h"
#include <qmessagebox.h>

TeacherSigninDialog::TeacherSigninDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TeacherSigninDialog)
{
    ui->setupUi(this);
    //初始化功能选择界面
    fs = new FunctionSelectionWindow();
    fs->bi = new BusWindow();
    fs->user_id = TEACHER;
    fs->setWindowTitle("功能选择");
}

TeacherSigninDialog::~TeacherSigninDialog()
{
    delete ui;
}
//显示ui
void TeacherSigninDialog::teachersignindialog_show()
{
    this->show();
    //connect(ui->buttonBox,SIGNAL(accepted()),fs,SLOT(functionselectionwindow_show()));
}

//点击“确定”获取文本框中信息
void TeacherSigninDialog::on_buttonBox_accepted()
{
    QString Q = ui->salary_number_text->toPlainText();
    QString filename = "C:\\Users\\LINCGCG\\Desktop\\Qt\\test4\\data\\teacher.csv";
    ui->salary_number_text->clear();
    bool unfinded = false;
    switch(fs->user_id){
        case STUDENT:
            if(data::islocate(Q,filename,&(fs->stu_user))) {
                fs->show();
                fs->bi->show();
            }
            else
                unfinded = true;
            break;
        case TEACHER:
            if(data::islocate(Q,filename,&(fs->tea_user))) {
               fs->show();
               fs->bi->show();
            }
            else
               unfinded = true;
            break;
        case TEACHER_FAMILY:
            if(data::islocate(Q,filename,&(fs->teafam_user))) {
                fs->show();
                fs->bi->show();
            }
            else
                unfinded = true;
            break;
    }
    //std::cout<<fs->tea_user->get_Number_bus()<<std::endl;
    if(unfinded) {
        QMessageBox *q;
        q = new QMessageBox("教师登录",
                            "登录失败",
                            QMessageBox::Critical,
                            QMessageBox::Ok | QMessageBox::Default,
                            QMessageBox::Cancel | QMessageBox::Escape,
                            0);
        q->show();
    }
}
