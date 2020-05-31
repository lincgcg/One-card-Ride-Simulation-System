#include "buswindow.h"
#include "ui_buswindow.h"

BusWindow::BusWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BusWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("班车信息查询");
    QString filename = "C:\\Users\\LINCGCG\\Desktop\\Qt\\test4\\data\\bus.csv";
    for(int i =0;i<11;i++)
        data::loadbusdata(filename,i+8,&(busdata[i][0]),&(busdata[i][1]));
    //ui->data_identity->addItem(tr("学生").trimmed(),STUDENT);
    ui->data_time->addItem(tr("8"),0);
    ui->data_time->addItem(tr("9"),1);
    ui->data_time->addItem(tr("10"),2);
    ui->data_time->addItem(tr("11"),3);
    ui->data_time->addItem(tr("12"),4);
    ui->data_time->addItem(tr("13"),5);
    ui->data_time->addItem(tr("14"),6);
    ui->data_time->addItem(tr("15"),7);
    ui->data_time->addItem(tr("16"),8);
    ui->data_time->addItem(tr("17"),9);
    ui->data_time->addItem(tr("18"),10);
    this->bus_choose = -1;
}

BusWindow::~BusWindow()
{
    delete ui;
}


void BusWindow::on_button_ok_clicked()
{
    //获取当前时间
    time_t tx;
    struct tm *nowtime;
    time(&tx);
    nowtime = localtime(&tx);

    int ti = ui->data_time->currentIndex();
    //姓名
    ui->data_name1->setText(QString::fromStdString(busdata[ti][0]->get_name_driver()));
    ui->data_name2->setText(QString::fromStdString(busdata[ti][1]->get_name_driver()));
    //载乘人数
    ui->data_max_number1->setText(QString::number(busdata[ti][0]->get_Max_number_passenger()));
    ui->data_max_number2->setText(QString::number(busdata[ti][1]->get_Max_number_passenger()));
    //当前人数
    ui->data_now_number1->setText(QString::number(busdata[ti][0]->get_now_number_passenger()));
    ui->data_now_number2->setText(QString::number(busdata[ti][1]->get_now_number_passenger()));
    //车牌
    ui->data_number1->setText(QString::fromStdString(busdata[ti][0]->get_number_car()));
    ui->data_number2->setText(QString::fromStdString(busdata[ti][1]->get_number_car()));
    //车型
    ui->data_model1->setText(QString::fromStdString(busdata[ti][0]->get_model_car()));
    ui->data_model2->setText(QString::fromStdString(busdata[ti][1]->get_model_car()));

    if(ti+8 != nowtime->tm_hour) {
        ui->button_sure1->setEnabled(false);
        ui->button_sure2->setEnabled(false);
    }
    else {
        if(nowtime->tm_min>10) {
            ui->button_sure1->setEnabled(false);
            ui->button_sure2->setEnabled(false);
        }
        else {
            if(busdata[ti][0]->get_Max_number_passenger()-busdata[ti][0]->get_now_number_passenger() == 0)
                ui->button_sure1->setEnabled(false);
            else
                ui->button_sure1->setEnabled(true);
            if(busdata[ti][1]->get_Max_number_passenger()-busdata[ti][1]->get_now_number_passenger() == 0)
                ui->button_sure2->setEnabled(false);
            else
                ui->button_sure2->setEnabled(true);
        }
    }
//    if(busdata[ti][0]->get_Max_number_passenger()-busdata[ti][0]->get_now_number_passenger() == 0)
//        ui->button_sure1->setEnabled(false);
//    else {

//         ui->button_sure1->setEnabled(true);
//    }



//    if(busdata[ti][1]->get_Max_number_passenger()-busdata[ti][1]->get_now_number_passenger() == 0)
//        ui->button_sure2->setEnabled(false);
//    else
//        ui->button_sure2->setEnabled(true);
}

void BusWindow::on_button_sure1_clicked()
{
    this->bus_choose = 0;
    this->close();
}

void BusWindow::on_button_sure2_clicked()
{
    this->bus_choose = 1;
    this->close();
}
