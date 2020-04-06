#pragma once
#pragma once
#ifndef QUEUE_H
#define QUEUE_H
#include <string>
using namespace std;

template <class Type>
class Event
{
private:
    int queue_size; // Defines the size of waiting list. 
    int Front, Back;// Keep track of the order of the list.
    Type* Contents;// An array of objects.
    string title; // This holds the title of the object (or Event).
    int currentSize;
public:

    Event(string titleIn, int queue_size = 10); // Constructor
    ~Event();
    bool Empty() const; // Returns true if empty.
    bool Full() const; // Returns true if full.
    bool Remove(Type& front_element); // Removes item from queue and passes by reference to an output variable.
    bool Add(const Type& new_element); // Adds a new item to the back of a queue.
    void printContents(); // Prints out the items of the Event queue. 
    bool searchForElement(string name, int& output); // Searches for matching results in the queue, returns the index where it is.
    void resetList(); // Empties the list completely and prompts user to rename / re-title the queue/event. 
    void set_title(string titleIn); // Standard setter & getter for title. 
    string get_title();
    int get_currentSize(); // This function both calculates, and returns the current size of a queue. 
};

#endif



