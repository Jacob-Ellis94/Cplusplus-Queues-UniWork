#pragma once
#ifndef QUEUETEMPLATE_H
#define QUEUETEMPLATE_H
#include <iostream>
#include "Queue.h"
#include "Functions.h"
#include <string>
using namespace std;

// Constructor
template <class Type>
Event<Type> ::Event(string titleIn, int queue_size) : title(titleIn), queue_size(queue_size), Contents(new Type[queue_size + 1]), Front(0), Back(0)
{}

// Destructor
template <class Type>
Event<Type> :: ~Event()
{
    delete[] Contents;
}
// Tests
template <class Type>
bool Event<Type> ::Empty() const
{
    return (Front == Back);
}

template <class Type>
bool Event<Type> ::Full() const
{
    return ((1 + Back) % (queue_size + 1) == Front);
}

// Remove and Add
template <class Type>
bool Event<Type> ::Remove(Type& front_element)
{
    if (Empty()) return false;
    else
    {
        front_element = Contents[Front];
        Front = (Front + 1) % (queue_size + 1);
        return true;
    }
}

template <class Type>
bool Event<Type> ::Add(const Type& new_element)
{
    if (Full()) return false;

    Contents[Back] = new_element;
    Back = (Back + 1) % (queue_size + 1);
    return true;
}

template <class Type>
void Event<Type>::printContents()
{


    for (int i = Front; i != Back; i = (i + 1) % (queue_size + 1))
    {
        cout << Contents[i].get_name() << ", " << Contents[i].get_phoneNum() << endl;

    }

}

template <class Type>
bool Event<Type>::searchForElement(string name, int& output)
{
    bool found = false;
    int counter = 0;
    for (int i = Front; i != Back; i = (i + 1) % (queue_size + 1))
    {
        string element = Contents[i].get_name();
        string copyForOutput;

        stringUpper(element); // This converts customer name to upper case for comparisons.
        if (element == name)
        {
            found = true;
            break;
        }
        counter++; // This holds and outputs the position of the customer in the queue.
    }
    output = counter;
    return found;
}

template <class Type>
void Event<Type>::resetList()
{
    string YesOrNo; // Holds a user option for following question.
    cout << endl << "Are you sure you would like to delete this list and re-assign to a new event?" << endl << endl;
    cout << "(Y = Yes / N = No )" << endl;
    cin >> YesOrNo;
    stringUpper(YesOrNo); // This converts the user input to the upper case form, before comparisons are made. 
    while ((YesOrNo != "Y" && YesOrNo != "N"))//Input validation for the question above.
    {
        cout << "!!!<<<Invalid input>>>!!!" << endl << "Please enter (Y) or (N) to indicate if you would like to delete this list and re-assign the title to a new event." << endl << endl;
        cin >> YesOrNo;
        stringUpper(YesOrNo);
        cin.clear();
        cin.ignore(100, '\n');
    }
    if (YesOrNo == "Y")
    {
        cin.clear();
        cin.ignore(100, '\n');
        string newTitle;
        Front = 0;
        Back = 0;

        cout << "Please enter a new title for the event list : " << endl;
        getline(cin, newTitle); // Takes in title, including spaces if needed. 
        title = newTitle;
        cout << endl << endl << endl << "****** List emptied, new event title is: " << title << " ******" << endl;
    }
    else
        cout << endl << "******* ~ Action aborted ~ *******" << endl;
}

template <class Type>
void Event<Type> ::set_title(string titleIn)
{
    title = titleIn;
}
template <class Type>
string Event<Type>::get_title()
{
    return title;
}

template <class Type>
int Event<Type> ::get_currentSize()
{
    int counter = 0;
    for (int i = Front; i != Back; i = (i + 1) % (queue_size + 1)) // This algorithm is used to find the current size of a queue.
    {
        counter++;
    }
    currentSize = counter;
    return currentSize;
}

#endif