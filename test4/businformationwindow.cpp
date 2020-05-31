#include "businformationwindow.h"
#include "ui_businformationwindow.h"

BusInformationWindow::BusInformationWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BusInformationWindow)
{
    ui->setupUi(this);
    QString filename = "C:\\Users\\LINCGCG\\Desktop\\Qt\\test4\\data\\bus.csv";
    for(int i =0;i<11;i++)
        data::loadbusdata(filename,i+8,&(busdata[i][0]),&(busdata[i][1]));
    for(int i=0;i<11;i++)
        std::cout<<(busdata[i][0])->get_model_car()<<std::endl;
}

BusInformationWindow::~BusInformationWindow()
{
    delete ui;
}
