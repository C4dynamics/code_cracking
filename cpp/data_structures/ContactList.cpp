/*
 * ContactList.cpp
 *
 *  Created on: Jul 23, 2012
 *      Author: Derek
 *
 *      Linked List Example
 * 
 * https://www.youtube.com/watch?v=7vZo17iv1zQ&t=409s
 * 
 */




#include "pch.h"
#include "ContactList.h"
using namespace std;

ContactList::ContactList() :head(NULL), size(0) // the initialization of the list. therefore for the Contact object pointer assigns null - since the list is still empty. and to the size assigns 0 - for the same reason. 
{}


void ContactList::addToHead(Contact* newOne)
{
    if (head == NULL)
    {
        head = newOne;
    }
    else
    {
        newOne->next = head;
        head = newOne;
    }

    size++;
}

void ContactList::printList() {

    Contact *nextnode = head;

    for (int i = 0; i < size; i++) {
        cout << nextnode->name << "   " << nextnode->val << endl;
        nextnode = nextnode->next;
    }
}

