/*
 * ContactList.h
 *
 *  Created on: Jul 23, 2012
 *      Author: Derek
 *
 *      Linked List Example
 */
 // https://www.youtube.com/watch?v=7vZo17iv1zQ&t=409s
#pragma once


#ifndef CONTACTLIST_H_
#define CONTACTLIST_H_

#include "Contact.h"

class ContactList
{
public:
    ContactList();
    void addToHead(Contact *newOne);
    void printList();

private:
    Contact *head;
    int size;
};


#endif /* CONTACTLIST_H_ */