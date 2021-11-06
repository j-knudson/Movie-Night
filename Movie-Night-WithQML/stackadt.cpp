

//StackADT.cpp

//This is the implementation file for the Stack abstract data type
//For documentation see StackADT.h

//Invariant for the StackADT
/*
    1.) The member variable used holds the number of Items in the stack
    2.) The array data[] holds the Items in the Stack, in positions 0 through used-1. The top of the stack is at position used-1
*/

#include <iostream>
#include <cstdlib>

#include "stackadt.h"

void Stack::push(Item entry)		//Add an item to the stack
{
    data[used++] = entry;			//Add entry to the stack and then increment used which is counter keeping track of values in the stack
}

Stack::Item Stack::pop()
{
    return data[--used];			//Decrement the count by one to get to the top item in the stack and return it
}

Stack::Item Stack::getRandom()
{
    int selection = rand() % used+1;                              //generate a random number for the current size of the stack
    Stack temp;                                                           //create a temp stack to save movie titles
    while (used > selection) {            //pop items off the stack unitl we reach our random value selection
            temp.push(data[--used]);                   //save the values we're popping in temp
        }
    QString target = data[--used];             //save the value in the stack at our random selection
    while (temp.size() > 0) {                       //return values from temp back to the stack
        data[used++]=temp.pop();
    }

    return target;                                  //return the random value
}



