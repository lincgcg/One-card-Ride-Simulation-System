#ifndef PEOPLE_H
#define PEOPLE_H

#include<string>
class people{
    private:
        std::string name;    //姓名
        int gander;          //男为1，女为0
        int identity;        //教师为0，学生为1，教师家属为2
        double balance;      //余额
        int number_bus;      //乘车次数
    public:
        void initpeople(std::string name, int gander, int identity, double balance );
        //读：姓名，性别，身份，余额，乘车次数
        int get_Identity() ;

        int get_gander();

        double get_Balance();

        int get_Number_bus();

        std::string get_name();

        //写：余额,乘车次数,性别
        void set_Balance(double balance);

        void set_number_bus(int number);

        void set_gander(int gander);
        //乘车次数+1
        void Add_numner_bus();

        //余额充值
        void Recharge(int add_money);

        bool Consume_Bus();

};
class teacher:public people{
    private:
        std::string salary_number;  //工资号
        std::string college;        //所属学院

    public:
        teacher(std::string& name,int gander, int identity, double balance, std::string& salary_number,
                std::string& cpllege);
        //读：工资号，学院
        std::string get_Salary_number();
        std::string get_college();
        //教师免费乘车，直接返回true
        bool Consume_Bus();

};
class student:public people{
    private:
        std::string student_number;     //学号
        std::string college;            //所属学院

    public:
        student(std::string& name,int gander, int identity, double balance,
                std::string& student_number,std::string& college);
        //读：学号，学院
        std::string get_Student_number();

        std::string get_college();
        //学生乘车一次俩块钱
        //如果余额足够，扣钱，返回true;
        //如果余额<2,返回false
        bool Consume_Bus();
};
class teacher_family:public people{
    private:
        std::string card_number;        //卡号
    public:
        teacher_family(std::string& name,int gander, int identity, double balance,
                std::string& card_number,std::string& college);

        //教师家属乘车
        //如果剩余免费成册次数>0，那么-1，返回0
        //否者如果余额>2，扣钱，返回true
        //否则 返回false
        int Comsume_Bus();
        std::string get_card_number();
};

#endif //PEOPLE_H
