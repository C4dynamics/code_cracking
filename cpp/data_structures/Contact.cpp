/*
 * Contact.cpp
 *
 *  Created on: Jul 21, 2012
 *      Author: Derek
 *
 *      Contact Node for a Linked List Example
 */
 // https://www.youtube.com/watch?v=7vZo17iv1zQ&t=409s


#include "pch.h"
#include "Contact.h"

using namespace std;

Contact::Contact(string n, int v): name(n), val(v), next(NULL)
{}

ostream& operator<<(ostream& os, const Contact& c)
{
    return os << "Name: " << c.name;
}