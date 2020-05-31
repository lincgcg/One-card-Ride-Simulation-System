#include "people.h"
#include <iostream>

//      people

void people::initpeople(std::string name, int gander, int identity, double balance ) {
    this->name = name;
    this->gander = gander;
    this->identity = identity;
    this->balance = balance;
    this->number_bus = 0;
}
//读：身份，姓名，性别，余额，乘车次数
int people::get_Identity() {
    return this->identity;
}
int people::get_gander(){
    return this->gander;
}
double people::get_Balance() {
    return this->balance;
}
int people::get_Number_bus() {
    return this->number_bus;
}
std::string people::get_name(){
    return this->name;
}

//写：余额,乘车次数,性别
//若是性别gander为-1，表示一卡通已被注销
void people::set_Balance(double balance) {
    this->balance = balance;
}
void people::set_number_bus(int number) {
    this->number_bus = number;
}
void people::set_gander(int gander) {
    this->gander = gander;
}

//乘车次数+1
void people::Add_numner_bus() {
    this->number_bus +=1;
}
//余额充值
void people::Recharge(int add_money) {
    this->set_Balance(add_money+this->get_Balance());
}

bool people::Consume_Bus(){
    //std::cout<<"people_Comsume_Bus"<<std::endl;
    return false;
}

//      teacher

teacher::teacher(std::string& name,int gander, int identity, double balance, std::string& salary_number,
        std::string& college):people() {
    initpeople(name,gander,identity,balance);
    this->salary_number = salary_number;
    this->college = college;
}
//读：工资号，学院
std::string teacher::get_Salary_number() {
    return this->salary_number;
}
std::string teacher::get_college() {
    return this->college;
}

bool teacher::Consume_Bus(){
    this->set_number_bus(this->get_Number_bus()+1);
    return true;
}

//      student

student::student(std::string& name,int gander, int identity, double balance,
        std::string& student_number,std::string& college):people() {
    initpeople(name,gander,identity,balance);
    this->student_number = student_number;
    this->college = college;
}
//读：学号，学院
std::string student::get_Student_number() {
    return this->student_number;
}
std::string student::get_college() {
    return this->college;
}

//学生乘车一次俩块钱
//如果余额足够，扣钱，返回true;
//如果余额<2,返回false
bool student::Consume_Bus() {
    if(this->get_Balance()<1.99) {
        return false;
    }
    else {
        this->set_Balance(this->get_Balance() - 2);
        this->set_number_bus(this->get_Number_bus()+1);
        return true;
    }
}

//      teacher_family

teacher_family::teacher_family(std::string& name,int gander, int identity, double balance,
        std::string& card_number,std::string& college):people() {
    initpeople(name,gander,identity,balance);
    this->card_number = card_number;        //外部实现

}
//读，卡号
std::string teacher_family::get_card_number() {
    return this->card_number;
}

//教师家属乘车
//如果剩余免费乘车次数>1，那么返回1 ，
//如果乘车后免费次数为0，那么返回2
//如果通过余额支付，返回3
//否则 返回0

int teacher_family::Comsume_Bus() {
    if((20-this->get_Number_bus())>0) {
        this->set_number_bus(this->get_Number_bus()+1);
        if(this->get_Number_bus() == 20)
            return 2;
        else return 1;
    }
    else{
        if(this->get_Balance()>1.99) {
            this->set_number_bus(this->get_Number_bus()+1);
            this->set_Balance(this->get_Balance() - 2);
            return 3;
        }
        else
            return 0;
    }
}
