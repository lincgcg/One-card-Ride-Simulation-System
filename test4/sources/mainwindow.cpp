#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<iostream>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //注：先初始化I的化，islogon无论如何就都为false，所以得把槽和信号之间的连接单独设置一个函数，
    //并且得在点击“登录”，“注册”，“退出”其中一个时访问
    ui->setupUi(this);
    this->setWindowTitle("主界面");
    this->setFixedSize(this->width(),this->height());
    I = new IdentityWindow();
    I->setWindowTitle("身份确定");
    I->setFixedSize(I->width(),I->height());
    logon = new LogonMainWindow();
    logon->setWindowTitle("注册界面");

    connect(ui->signin_button,SIGNAL(clicked()),I,SLOT(identitywindow_show()));
    connect(ui->logon_button,SIGNAL(clicked()),logon,SLOT(logonMainwindow_show()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_signin_button_clicked()
{
    I->link(false);
}

void MainWindow::on_signout_button_clicked()
{
    this->close();
}

void MainWindow::on_logon_button_clicked()
{

}
