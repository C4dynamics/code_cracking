
/*
 * Contact.h
 *
 *  Created on: Jul 21, 2012
 *      Author: Derek
 *
 *      Contact Node for a Linked List Example
 */
 // https://www.youtube.com/watch?v=7vZo17iv1zQ&t=409s
#pragma once

#ifndef CONTACT_H_
#define CONTACT_H_

#include <iostream>
#include <string>

class Contact
{
    friend std::ostream& operator<<(std::ostream& os, const Contact& c);

    public:

      Contact(std::string name, int val); // = "none"

    // private:
      std::string name;
      int val;
      Contact *next;
};


#endif /* CONTACT_H_ */