#include "studentsignindialog.h"
#include "ui_studentsignindialog.h"
#include <iostream>
#include "data.h"
#include <qmessagebox.h>

StudentSigninDialog::StudentSigninDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StudentSigninDialog)
{
    ui->setupUi(this);
    //初始化功能选择界面
    fs = new FunctionSelectionWindow();
    fs->bi = new BusWindow();
    fs->user_id = STUDENT;
    fs->setWindowTitle("功能选择");
}

StudentSigninDialog::~StudentSigninDialog()
{
    delete ui;
}
//显示ui
void StudentSigninDialog::studentsignindialog_show()
{
    this->show();
    //connect(ui->buttonBox,SIGNAL(accepted()),fs,SLOT(functionselectionwindow_show()));
}

//点击“确定”获取文本框中信息
void StudentSigninDialog::on_buttonBox_accepted()
{
    QString Q = ui->student_number_text->toPlainText();
    QString filename = "C:\\Users\\LINCGCG\\Desktop\\Qt\\test4\\data\\student.csv";
    ui->student_number_text->clear();
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
    //std::cout<<fs->stu_user->get_Student_number()<<std::endl;
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
