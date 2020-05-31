#include "data.h"
#include <iostream>
#include <QDebug>
#include <QFileInfo>

bool data::islocate(QString number, QString filename,student **user){
    QFile csvFile(filename);
    QList<QStringList> data;
    if (csvFile.open(QIODevice::ReadWrite))
    {

        QTextStream stream(&csvFile);
        forever{
            QString line = stream.readLine();
            if(line.isEmpty()) {
                break;
            }
            QStringList row;
            for(const QString& cell: line.split(",")){
                row.append(cell.trimmed());
            }
            data.append(row);
        }
         csvFile.close();
    }
    for(int i=0; i<data.size(); ++i){
       QStringList s1=data.at(i);

       QString qcard = s1.at(2);

       if(!QString::compare(qcard.toLatin1().data(),number.toLatin1().data())) {

           std::string card = qcard.toStdString();
           QString qname= s1.at(0);
           std::string name = qname.toStdString();
           QString qgender = s1.at(1);
           int gender = qgender.toInt();
           QString qcollege = s1.at(3);
           std::string college = qcollege.toStdString();
           QString qbalance = s1.at(4);
           double balance = qbalance.toDouble();
           QString qnumber = s1.at(5);
           int number = qnumber.toInt();

           (*user) = new student(name,gender,0,balance,card,college);

           (*user)->set_number_bus(number);

           return true;
       }
    }
    return false;
}
bool data::islocate(QString number, QString filename,teacher **user){
    QFile csvFile(filename);
    QList<QStringList> data;
    if (csvFile.open(QIODevice::ReadWrite))
    {

        QTextStream stream(&csvFile);
        forever{
            QString line = stream.readLine();
            if(line.isEmpty()) {
                break;
            }
            QStringList row;
            for(const QString& cell: line.split(",")){
                row.append(cell.trimmed());
            }
            data.append(row);
        }
         csvFile.close();
    }
    for(int i=0; i<data.size(); ++i){
       QStringList s1=data.at(i);

       QString qcard = s1.at(2);

       if(!QString::compare(qcard.toLatin1().data(),number.toLatin1().data())) {

           std::string card = qcard.toStdString();
           QString qname= s1.at(0);
           std::string name = qname.toStdString();
           QString qgender = s1.at(1);
           int gender = qgender.toInt();
           QString qcollege = s1.at(3);
           std::string college = qcollege.toStdString();
           QString qbalance = s1.at(4);
           double balance = qbalance.toDouble();
           QString qnumber = s1.at(5);
           int number = qnumber.toInt();

           *user = new teacher(name,gender,1,balance,card,college);

           (*user)->set_number_bus(number);

           return true;
       }
    }
    return false;
}
bool data::islocate(QString number, QString filename,teacher_family **user){
    QFile csvFile(filename);
    QList<QStringList> data;
    if (csvFile.open(QIODevice::ReadWrite))
    {

        QTextStream stream(&csvFile);
        forever{
            QString line = stream.readLine();
            if(line.isEmpty()) {
                break;
            }
            QStringList row;
            for(const QString& cell: line.split(",")){
                row.append(cell.trimmed());
            }
            data.append(row);
        }
         csvFile.close();
    }
    for(int i=0; i<data.size(); ++i){
       QStringList s1=data.at(i);

       QString qcard = s1.at(2);

       if(!QString::compare(qcard.toLatin1().data(),number.toLatin1().data())) {

           std::string card = qcard.toStdString();
           QString qname= s1.at(0);
           std::string name = qname.toStdString();
           QString qgender = s1.at(1);
           int gender = qgender.toInt();
           QString qcollege = s1.at(3);
           std::string college = qcollege.toStdString();
           QString qbalance = s1.at(4);
           double balance = qbalance.toDouble();

           QString qnumber = s1.at(5);
           int number2 = qnumber.toInt();

           *user = new teacher_family(name,gender,2,balance,card,college);
           (*user)->set_number_bus(number2);
           return true;
       }
    }
    return false;
}

bool data::savedata(QString filename, student **user) {
    QFile csvFile(filename);
    QList<QStringList> data;
    //将文件数据保存在data中
    if (csvFile.open(QIODevice::ReadOnly))
    {
        QTextStream stream(&csvFile);
        forever{
            QString line = stream.readLine();
            if(line.isEmpty()) {
                break;
            }
            QStringList row;
            for(const QString& cell: line.split(",")){
                row.append(cell.trimmed());
            }
            data.append(row);
        }
         csvFile.close();
    }

    QString findata;
    //通过学号找到用户
    bool finded = false;
    for(int i=0; i<data.size(); ++i){
       QStringList s1=data.at(i);
       //姓名
       QString qname= s1.at(0);
       //性别
       QString qgender = s1.at(1);
       //号码
       QString qcard = s1.at(2);
       //学院
       QString qcollege = s1.at(3);
       //余额
       QString qbalance = s1.at(4);
       //乘车次数
       QString qnumber = s1.at(5);

       if(!QString::compare(qcard.toLatin1().data(),QString::fromStdString((*user)->get_Student_number()))) {
           //如果相等
           finded = true;
           findata = findata +
                     qname + QString(',').toLatin1() +
                     QString::number((*user)->get_gander()) + QString(',').toLatin1() +
                     qcard + QString(',').toLatin1() +
                     qcollege + QString(',').toLatin1() +
                     QString::number((*user)->get_Balance(),10,4) + QString(',').toLatin1() +
                     QString::number((*user)->get_Number_bus()) + QString(',').toLatin1() +
                     QString('\n').toLatin1();
       }
       else {
           //如果不相等
           findata = findata +
                     qname + QString(',').toLatin1() +
                     qgender + QString(',').toLatin1() +
                     qcard + QString(',').toLatin1() +
                     qcollege + QString(',').toLatin1() +
                     qbalance + QString(',').toLatin1() +
                     qnumber + QString(',').toLatin1() +
                     QString('\n').toLatin1();
       }
    }
    if(!finded){
        findata = findata +
                QString::fromStdString((*user)->get_name()) + QString(',').toLatin1() +
                QString::number((*user)->get_gander()) + QString(',').toLatin1() +
                QString::fromStdString((*user)->get_Student_number()) + QString(',').toLatin1() +
                QString::fromStdString((*user)->get_college()) + QString(',').toLatin1() +
                QString("0") + QString(',').toLatin1() +
                QString("0") + QString(',').toLatin1() +
                QString('\n').toLatin1();
    }
    csvFile.close();
    if (csvFile.open(QIODevice::WriteOnly)) {
        QTextStream in(&csvFile);
        in <<findata;
        csvFile.close();
    }
    return finded;
}
bool data::savedata(QString filename, teacher **user) {
    QFile csvFile(filename);
    QList<QStringList> data;
    //将文件数据保存在data中
    if (csvFile.open(QIODevice::ReadOnly))
    {
        QTextStream stream(&csvFile);
        forever{
            QString line = stream.readLine();
            if(line.isEmpty()) {
                break;
            }
            QStringList row;
            for(const QString& cell: line.split(",")){
                row.append(cell.trimmed());
            }
            data.append(row);
        }
         csvFile.close();
    }

    QString findata;
    //通过工资号找到用户
    bool finded = false;
    for(int i=0; i<data.size(); ++i){
       QStringList s1=data.at(i);
       //姓名
       QString qname= s1.at(0);
       //性别
       QString qgender = s1.at(1);
       //号码
       QString qcard = s1.at(2);
       //学院
       QString qcollege = s1.at(3);
       //余额
       QString qbalance = s1.at(4);
       //乘车次数
       QString qnumber = s1.at(5);

       if(!QString::compare(qcard.toLatin1().data(),QString::fromStdString((*user)->get_Salary_number()))) {
           //如果相等
           finded = true;
           findata = findata +
                     qname + QString(',').toLatin1() +
                     QString::number((*user)->get_gander()) + QString(',').toLatin1() +
                     qcard + QString(',').toLatin1() +
                     qcollege + QString(',').toLatin1() +
                     QString::number((*user)->get_Balance(),10,4) + QString(',').toLatin1() +
                     QString::number((*user)->get_Number_bus()) + QString(',').toLatin1() +
                     QString('\n').toLatin1();
       }
       else {
           //如果不相等
           findata = findata +
                     qname + QString(',').toLatin1() +
                     qgender + QString(',').toLatin1() +
                     qcard + QString(',').toLatin1() +
                     qcollege + QString(',').toLatin1() +
                     qbalance + QString(',').toLatin1() +
                     qnumber + QString(',').toLatin1() +
                     QString('\n').toLatin1();
       }
    }
    if(!finded){
        findata = findata +
                QString::fromStdString((*user)->get_name()) + QString(',').toLatin1() +
                QString::number((*user)->get_gander()) + QString(',').toLatin1() +
                QString::fromStdString((*user)->get_Salary_number()) + QString(',').toLatin1() +
                QString::fromStdString((*user)->get_college()) + QString(',').toLatin1() +
                QString("0") + QString(',').toLatin1() +
                QString("0") + QString(',').toLatin1() +
                QString('\n').toLatin1();
    }
    csvFile.close();
    if (csvFile.open(QIODevice::WriteOnly)) {
        QTextStream in(&csvFile);
        in <<findata;
        csvFile.close();
    }
    return finded;
}
bool data::savedata(QString filename, teacher_family **user) {
    QFile csvFile(filename);
    QList<QStringList> data;
    //将文件数据保存在data中
    if (csvFile.open(QIODevice::ReadOnly))
    {
        QTextStream stream(&csvFile);
        forever{
            QString line = stream.readLine();
            if(line.isEmpty()) {
                break;
            }
            QStringList row;
            for(const QString& cell: line.split(",")){
                row.append(cell.trimmed());
            }
            data.append(row);
        }
         csvFile.close();
    }

    QString findata;
    //通过卡号找到用户
    bool finded = false;
    for(int i=0; i<data.size(); ++i){
       QStringList s1=data.at(i);
       //姓名
       QString qname= s1.at(0);
       //性别
       QString qgender = s1.at(1);
       //号码
       QString qcard = s1.at(2);
       //学院
       QString qcollege = s1.at(3);
       //余额
       QString qbalance = s1.at(4);
       //乘车次数
       QString qnumber = s1.at(5);

       if(!QString::compare(qcard.toLatin1().data(),QString::fromStdString((*user)->get_card_number()))) {
           //如果相等
           finded = true;
           findata = findata +
                     qname + QString(',').toLatin1() +
                     QString::number((*user)->get_gander()) + QString(',').toLatin1() +
                     qcard + QString(',').toLatin1() +
                     qcollege + QString(',').toLatin1() +
                     QString::number((*user)->get_Balance(),10,4) + QString(',').toLatin1() +
                     QString::number((*user)->get_Number_bus()) + QString(',').toLatin1() +
                     QString('\n').toLatin1();
       }
       else {
           //如果不相等
           findata = findata +
                     qname + QString(',').toLatin1() +
                     qgender + QString(',').toLatin1() +
                     qcard + QString(',').toLatin1() +
                     qcollege + QString(',').toLatin1() +
                     qbalance + QString(',').toLatin1() +
                     qnumber + QString(',').toLatin1() +
                     QString('\n').toLatin1();
       }
    }
    if(!finded){
        QString card_number = QString("%1").arg(data.size()+1, 5, 10, QLatin1Char('0'));
        findata = findata +
                QString::fromStdString((*user)->get_name()) + QString(',').toLatin1() +
                QString::number((*user)->get_gander()) + QString(',').toLatin1() +
                card_number + QString(',').toLatin1() +
                QString("") + QString(',').toLatin1() +
                QString("0") + QString(',').toLatin1() +
                QString("0") + QString(',').toLatin1() +
                QString('\n').toLatin1();
        QMessageBox *q = new QMessageBox();
        q->setWindowTitle("卡号结果");
        q->setText(QString("<font size='20'color='green'>您的卡号为：</font>"
                  "<font size='20'color='green'>%1</font>").arg(card_number));
        q->setIcon(QMessageBox::Warning);
        q->setStandardButtons(QMessageBox::Ok);
        if(q->exec()==QMessageBox::Ok)
             q->close();
    }
    csvFile.close();
    if (csvFile.open(QIODevice::WriteOnly)) {
        QTextStream in(&csvFile);
        in <<findata;
        csvFile.close();
    }
    return finded;
}

void data::loadbusdata(QString filename, int time, bus **bus1, bus **bus2) {
    QFile csvFile(filename);
    QList<QStringList> data;
    //将文件数据保存在data中
    if (csvFile.open(QIODevice::ReadOnly))
    {
        QTextStream stream(&csvFile);
        forever{
            QString line = stream.readLine();
            if(line.isEmpty()) {
                break;
            }
            QStringList row;
            for(const QString& cell: line.split(",")){
                row.append(cell.trimmed());
            }
            data.append(row);
        }
         csvFile.close();
    }
    for(int i =0;i<(data.size()-1);i++) {
        QStringList s1=data.at(i);
        QStringList s2=data.at(i+1);
        //班车时间
        QString qtime = s1.at(0);
        int qqtime = qtime.toInt();

        if(time == qqtime) {
            //车一
            //姓名
            QString qname1= s1.at(1);
            std::string name1 = qname1.toStdString();
            //车牌
            QString qnumber1= s1.at(2);
            std::string number1 = qnumber1.toStdString();
            //型号
            QString qmodel1 = s1.at(3);
            std::string model1 = qmodel1.toStdString();

            //车二
            //姓名
            QString qname2= s2.at(1);
            std::string name2 = qname2.toStdString();
            //车牌
            QString qnumber2= s2.at(2);
            std::string number2 = qnumber2.toStdString();
            //型号
            QString qmodel2 = s2.at(3);
            std::string model2 = qmodel2.toStdString();
            int max_number1 = 30 + 20*(rand()%2);
            int max_number2 = 30 + 20*(rand()%2);

            int now_number1 = rand()%(max_number1+1);
            int now_number2 = rand()%(max_number2+1);

            *bus1 = new bus(max_number1,number1,model1,name1);
            (*bus1)->set_now_number_passenger(now_number1);

            *bus2 = new bus(max_number2,number2,model2,name2);
            (*bus2)->set_now_number_passenger(now_number2);

            break;
        }
    }
}











