#pragma once
using namespace std;
#include <string>
#include "Queue.h"
#include "CustomerClass.h"


void colouriser(string x); // This changes the colour of the console output;
void addCustomer(Event<Customer>& eventIn); // This allows for customers to be added to a list;
void subMenu(Event<Customer>& eventIn); // This provides the sub menu from which operations can be chosen.
void stringUpper(string& word);// This converts a string into the upper case form.
void searchCustomer(Event<Customer>& eventIn); // This checks the queue for a particular customer and returns their position. 
string validateString(string& wordIn); // This checks to see if the input is a valid string.
int validateInteger(int& intIn); // Checks to see if input is a valid integer. 