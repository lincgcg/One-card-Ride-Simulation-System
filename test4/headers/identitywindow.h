#ifndef IDENTITYWINDOW_H
#define IDENTITYWINDOW_H

#include <QMainWindow>
#include <studentsignindialog.h>
#include <teachersignindialog.h>
#include <teacherfamilysignindialog.h>
namespace Ui {
class IdentityWindow;
}
//用户点击登录or注册后选择身份界面
class IdentityWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit IdentityWindow(QWidget *parent = 0);
    ~IdentityWindow();
    //建立信号和槽的连接
    void link(bool islogon);

private slots:
    void on_id_student_button_clicked();

    void identitywindow_show();

    void on_id_teacher_button_clicked();

    void on_id_teacher_family_button_clicked();

private:
    //ui为选择身份界面
    Ui::IdentityWindow *ui;
    //学生登录界面
    StudentSigninDialog *stu_signin;
    //教师登录界面
    TeacherSigninDialog *tea_signin;
    //教师家属登录界面
    TeacherFamilySigninDialog *teafam_signin;

};

#endif // IDENTITYWINDOW_H
