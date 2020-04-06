#include "CustomerClass.h"
#include <iostream>
using namespace std;

Customer::Customer() : name("Empty"), phoneNumber("0")
{}

Customer::Customer(string nameIn, string phoneIn) : name(nameIn), phoneNumber(phoneIn)
{}

void Customer::set_name(string nameIn)
{
	name = nameIn;
}
string Customer::get_name()
{
	return name;
}
void Customer::set_phoneNum(string phoneNum)
{
	phoneNumber = phoneNum;
}
string Customer::get_phoneNum()
{
	return phoneNumber;
}