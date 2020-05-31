#include "bus.h"

bus::bus(int max_number_passenger, std::string& number_car, std::string& model_car, std::string& name_driver) {
    this->max_number_passenger = max_number_passenger;
    this->number_car = number_car;
    this->model_car = model_car;
    this->name_driver = name_driver;
    //当前乘客数量初始化为0;
    this->now_number_passenger = 0;
}
//读：（全部）最大载乘人数，车牌号，型号，驾驶员姓名，当前乘客数
int bus::get_Max_number_passenger() {
    return this->max_number_passenger;
}
std::string bus::get_number_car() {
    return this->number_car;
}
std::string bus::get_model_car() {
    return this->model_car;
}
std::string bus::get_name_driver() {
    return this->name_driver;
}
int bus::get_now_number_passenger() {
    return this->now_number_passenger;
}
//写：当前乘客数
void bus::set_now_number_passenger(int number) {
    this->now_number_passenger = number;
}
