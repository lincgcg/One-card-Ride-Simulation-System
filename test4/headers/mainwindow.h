#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <identitywindow.h>
#include <logonmainwindow.h>

#include "people.h"
#include "bus.h"
namespace Ui {
class MainWindow;
}
//主界面
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_signin_button_clicked();

    void on_logon_button_clicked();

    void on_signout_button_clicked();

private:
    Ui::MainWindow *ui;
    IdentityWindow *I;
    //注册界面
    LogonMainWindow *logon;

};

#endif // MAINWINDOW_H
