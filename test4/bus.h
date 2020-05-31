
#ifndef BUS_H
#define BUS_H

#include<string>
class bus{
    private:
        int max_number_passenger;       //最大载乘人数
        std::string number_car;         //车牌号
        std::string model_car;          //型号
        std::string name_driver;        //驾驶员姓名

        int now_number_passenger;       //当前乘客数（不包括司机）
    public:
        bus(int max_number_passenger, std::string& number_car, std::string& model_car, std::string& name_driver);
        //读：（全部）最大载乘人数，车牌号，型号，驾驶员姓名，当前乘客数
        int get_Max_number_passenger();
        
        std::string get_number_car();
        
        std::string get_model_car();
        
        std::string get_name_driver();
        
        int get_now_number_passenger();
        
        //写：当前乘客数
        void set_now_number_passenger(int number);
};
#endif //BUS_H
