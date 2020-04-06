#pragma once
#include <string>
using namespace std;

class Customer
{
private:
    string name;
    string phoneNumber;
public:
    Customer();
    Customer(string nameIn, string phoneNum);
    void set_name(string nameIn);
    string get_name();
    void set_phoneNum(string phoneNum);
    string get_phoneNum();
};

