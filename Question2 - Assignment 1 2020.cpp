/*
Author : Jacob Ellis
Date : 11/02/2020

This program is designed to simulate a queue management process for a company which sells tickets for events.
Included with this program are four different header files : CustomerClass.h, Functions.h, Queue.h, QueueTemplate.h
Comments for particular functions are provided in the header files, though some comments on specific elements of these
functions can be found in the function definitions. I have tried to follow the assignment brief to the best of my ability.
This program holds lists (queues) of people (objects) for particular events.
The key functions of this program are :
Add a new customer to the list (if it is not already full).
Select information for the next customer on the list and remove them (as they are first in line).
Search for a customer using their surname, and return their position in the queue.
Empty a list completely, and re-assign a particular list to a new event (rename and clear essentially).
Apologies should be made for the rudimentary interface.
Further information can be found in the accompanying report.

*/
#include <iostream>
#include "Queue.h"
#include "QueueTemplate.h"
#include "CustomerClass.h"
#include "Functions.h"
#include <string>
#include <vector>
#include <Windows.h> // These provide the changes to the console colour at different menus.
#include <conio.h>
using namespace std;
void fillEventQueues();

int option, input;
string searchName, stars = "*******************************************************************************\n";// Used to pad out the interface
Customer Temp; // A temporary object for removal and output.

Event<Customer> Event1("DEF CON", 10); // These are used to initialize some test data to test functionality. 
Event<Customer> Event2("Cliff Richard Live", 10);
Event<Customer> Event3("Donald Trump Rally", 10);
Event<Customer> Event4("Pink Freud", 10);
Event<Customer> Event5("Paint Drying Championships", 10);
Event<Customer> Event6("Mr Bean Live", 10);
Event<Customer> Event7("Breakdancing Nuns", 10);
Event<Customer> Event8("Generic Sports Event", 10);
Event<Customer> Event9("Learn To Paint Like Jackson Pollock", 10);
Event<Customer> Event10("Competitive Vegetable Growing ", 10);



int main()
{
    fillEventQueues();

    string welcome = "Welcome to the invaluable ticket order processing program!";
    colouriser(stars);
    colouriser(welcome);
    cout << endl;
    colouriser(stars);
    cout << endl;

    bool mainMenu = true;
    while (mainMenu == true) // This provides the main menu from which individual events may be chosen.
    {
        cout << endl << endl;

        cout << "A list of our current events:" << endl;
        colouriser(stars);
        cout << " Option 1) " << Event1.get_title() << "  ~~~~~~~ Number of people in list:  " << Event1.get_currentSize() << endl;
        cout << "  Option 2) " << Event2.get_title() << "  ~~~~~~~ Number of people in list:  " << Event2.get_currentSize() << endl;
        cout << "  Option 3) " << Event3.get_title() << "  ~~~~~~~ Number of people in list:  " << Event3.get_currentSize() << endl;
        cout << "  Option 4) " << Event4.get_title() << "  ~~~~~~~ Number of people in list:  " << Event4.get_currentSize() << endl;
        cout << "  Option 5) " << Event5.get_title() << "  ~~~~~~~ Number of people in list:  " << Event5.get_currentSize() << endl;
        cout << "  Option 6) " << Event6.get_title() << "  ~~~~~~~ Number of people in list:  " << Event6.get_currentSize() << endl;
        cout << "  Option 7) " << Event7.get_title() << "  ~~~~~~~ Number of people in list:  " << Event7.get_currentSize() << endl;
        cout << "  Option 8) " << Event8.get_title() << "  ~~~~~~~ Number of people in list:  " << Event8.get_currentSize() << endl;
        cout << "  Option 9) " << Event9.get_title() << "  ~~~~~~~ Number of people in list:  " << Event9.get_currentSize() << endl;
        cout << "  Option 10) " << Event10.get_title() << "~~~~~~~ Number of people in list:  " << Event10.get_currentSize() << endl;
        colouriser(stars);
        cout << "Please indicate which event you would like to access by entering the option number (followed by ENTER) : " << endl;
        cout << "(Press 0 followed by ENTER to exit the program)" << endl << endl;
        validateInteger(input);
        switch (input) // Various options for the main menu, which allow user to choose which event to access.
        {
        case 0:
            mainMenu = false; // This breaks the menu loop and exits the program. 
            break;
        case 1:
            subMenu(Event1); // Each event is passed into the sub menu which allows for operations to take place. 
            break;

        case 2:
            subMenu(Event2);
            break;

        case 3:
            subMenu(Event3);
            break;

        case 4:
            subMenu(Event4);
            break;

        case 5:
            subMenu(Event5);
            break;

        case 6:
            subMenu(Event6);
            break;

        case 7:
            subMenu(Event7);
            break;

        case 8:
            subMenu(Event8);
            break;

        case 9:
            subMenu(Event9);
            break;

        case 10:
            subMenu(Event10);
            break;

        default: // This ensures that a valid input is given. 
            cout << endl << "***** ~ Invalid input! ~ *****" << endl << "Please enter a valid option from the events list" << endl;
            break;
        }
    }

    colouriser(stars);
    cout << "*** ~ Exiting program ~ ***" << endl;
    colouriser(stars);
}




void subMenu(Event<Customer>& eventIn)
{
    bool keepSubMenu = true;
    while (keepSubMenu == true)
    {
        colouriser(stars);
        cout << "****** ~ " << eventIn.get_title() << " ~ ******" << " ~~~~~~ Number of people on list: " << eventIn.get_currentSize() << endl;
        colouriser(stars);
        cout << " ~~~~~ Current list of customers for this event : ~~~~~~" << endl;
        if (eventIn.Empty())
            cout << "LIST EMPTY! - There are no customers currently on the list." << endl;
        eventIn.printContents();
        cout << endl << "Please select an option from the following: " << endl;
        cout << "1) Add a new customer to the waiting list" << endl;
        cout << "2) Select information for the next person on the waiting list (Caution: this will remove the customer from list) " << endl;
        cout << "3) Search for a customer using their details (Surname)" << endl;
        cout << "4) Reset this list and assign this waiting list to a new event" << endl;
        cout << "5) *** Return to main menu ***" << endl;
        int option;
        validateInteger(option);// Input validation.

        switch (option)
        {
        case 1:
            addCustomer(eventIn);
            break;
        case 2:
            if (eventIn.Empty())
            {
                cout << "***** List is empty! *****" << endl;
                break;
            }
            else
            {
                eventIn.Remove(Temp);
                cout << endl << endl;
                colouriser(stars);
                cout << "The next customer in line is : " << Temp.get_name() << ". Phone Number: " << Temp.get_phoneNum() << endl;
                colouriser(stars);
                cout << endl << endl;
                break;
            }
        case 3:
            searchCustomer(eventIn);
            break;
        case 4:
            eventIn.resetList();
            break;
        case 5:
            keepSubMenu = false;
            break;
        default:
            cout << endl << endl;
            cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
            cout << "This is an invalid input. Please enter a number from the options provided. " << endl;
            cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl << endl;
        }
    }
}


void searchCustomer(Event<Customer>& eventIn)
{
    cout << "Please enter the name you would like to search for : " << endl << endl;
    validateString(searchName); // This makes sure the input is a string variable.
    string copyName = searchName; // This creates a copy of the input string for outputting to screen.
    stringUpper(searchName); // This converts the input string to upper case before comparisons are made. 
    int index; // Used to keep track of the customer's position in the queue.
    eventIn.searchForElement(searchName, index); // This searches for the name against items in the queue. 
    bool result = eventIn.searchForElement(searchName, index);// This provides a boolean for if the name has been found. 
    index += 1; // takes index and adds 1 to get position in queue. 
    cout << endl << endl;
    if (result == true)
    {
        colouriser(stars);
        cout << copyName << " is at position: " << index << " in the queue." << endl;
        colouriser(stars);
        cout << endl << endl;
    }
    else if (result == false)
    {
        cout << "*************************************************************************************" << endl;
        cout << endl << "*****Customer not found on list. Please select another operation from the list. *****" << endl << endl;
        cout << "*************************************************************************************" << endl;
    }
}

void fillEventQueues()
{


    for (int i = 0; i < 7; i++)
    {
        Event1.Add(Customer("Ghandi", "0800132456"));
        Event2.Add(Customer("Papodopolous", "99978984652"));
        Event3.Add(Customer("Gerald", "93949039090"));
        Event4.Add(Customer("Goldstein", "574737574574"));
        Event5.Add(Customer("McDoot", "0777554654654"));
        Event6.Add(Customer("Froot", "38384843848383"));
        Event7.Add(Customer("Zoot", "38384843848383"));
        Event8.Add(Customer("Zimmerman", "38384843848383"));
        Event9.Add(Customer("Bowie", "38384843848383"));
        Event10.Add(Customer("Marley", "38384843848383"));
    }

}