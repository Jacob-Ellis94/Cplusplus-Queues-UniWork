#include "Functions.h"
#include <Windows.h> // This provides the changes to the console colour.
#include <conio.h>
#include <iostream>
#include "Queue.h"
#include <string>
#include "CustomerClass.h"
using namespace std;

void colouriser(string x) // Changes the colour of string passed in to rainbow colours (Code found from Stack Overflow).
{
    int colour = 2;
    for (int i = 0; i <= x.size(); i++)
    {
        if (colour == 16) // Limits the number of colours to desired range. 
        {
            colour = 2;
        }
        else
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colour);// Beyond my comprehension, but it works. 
        cout << x[i];
        colour++;
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
}


void addCustomer(Event<Customer>& eventIn)
{
    if (eventIn.Full()) // Checks to see if the event is full or not. If not message displayed. 
    {
        cout << endl << endl;
        cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
        cout << "*** Warning! *** : List is full. Please remove a customer before proceeding to add new ones. " << endl;
        cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
    }
    else
    {
        string nameIn, numberIn;
        bool invalidNum = true;
        bool invalidName;

        do
        {
            cout << endl << "Please enter a valid name for the customer you would like to add: " << endl << endl;
            cin.clear();
            cin.ignore(100, '\n');
            getline(cin, nameIn); // Takes in customer name, including spaces if needed.
            
            invalidName = false;
            for (int i = 0; i < nameIn.length(); i++)
            {
                //if (nameIn[i] > 65 || nameIn[i] < 122) // This checks if the characters are within the ACII code range.
                //{
                //    invalidName = false;
                //    break;
                //}
                if ((nameIn[i] < 65) || (nameIn[i] > 122))// Similar inverse check.
                {
                    invalidName = true;
                    break;
                }
                //break;
            }

        } while (invalidName == true);

        while (invalidNum == true) // Integer data type was not big enough to save a phone number - string used instead. 
        {
            cout << endl << endl << "Please enter a valid phone number for the new customer (Must be 11 digits to be recognised) : " << endl << endl;
            validateString(numberIn);
            for (int i = 0; i < numberIn.length(); i++)
            {
                if ((numberIn[i] < 47) || (numberIn[i] > 58) || !(numberIn.length() == 11)) // This checks if it is only integers entered. 
                {
                    invalidNum = true;
                }
                else
                    invalidNum = false;
            }


        }
        Customer TempCustomer(nameIn, numberIn); // This provides a temporary object for adding to queue. 
        eventIn.Add(TempCustomer);
        cout << endl << endl;
        cout << "*******************************************************" << endl;
        cout << "New customer successfully added!" << endl;
        cout << "*******************************************************" << endl;
    }
}

void stringUpper(string& word) // This converts a string to the upper case version so that comparisons can be made. 
{
    for (int i = 0; i < word.size(); i++)
    {
        word[i] = toupper(word[i]);
    }
}

string validateString(string& wordIn)
{
    while (!(cin >> wordIn) || (wordIn.length() > 20))
    {
        // This loop validates the user input and explains the error.
        cout << endl << "!!!<<<Invalid input>>>!!!" << endl << "*** Enter a valid name (under 20 characters)***" << endl << endl;
        // This clears the previous answer.
        cin.clear();
        cin.ignore(100, '\n'); // This determines when the loop breaks/loops again. 
    }
    return wordIn;
}

int validateInteger(int& intIn)
{
    while (!(cin >> intIn))
    {
        // This loop validates the user input and explains the error.
        cout << endl << "!!!<<<Invalid input>>>!!!" << endl << "" << endl << endl;
        // This clears the previous answer.
        cin.clear();
        cin.ignore(100, '\n'); // This determines when the loop breaks/loops again. 
    }
    return intIn;

}

