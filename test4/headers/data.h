#ifndef DATA_H
#define DATA_H
#include <QFile>
#include <iostream>
#include <fstream>
#include <sstream>
#include <QTextStream>
#include <people.h>
#include "bus.h"
#include <stdlib.h>
#include <QMessageBox.h>
class data {

private:
//    QFile filename_student;
//    QFile filename_teacher;
//    QFile filename_teacherfamily;
public:
    //判断学生（学号number），教师（工资号number），教师家属（卡号number）是否在数据（文件名filename）中
    //如果是，将对应数据写入user
    static bool islocate(QString number, QString filename,student **user);
    static bool islocate(QString number, QString filename,teacher **user);
    static bool islocate(QString number, QString filename,teacher_family **user);
    //将user指向对象的数据存入filename的csv文件中，通过辨别码（学号，工资号，卡号）匹配
    static bool savedata(QString filename, student **user);
    static bool savedata(QString filename, teacher **user);
    static bool savedata(QString filename, teacher_family **user);
   //将时间为i的班车数据加载入bus1和bus2里
    static void loadbusdata(QString filename, int time , bus **bus1,bus **bus2);
};

#endif // DATA_H
