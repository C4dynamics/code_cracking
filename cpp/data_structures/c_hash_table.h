#pragma once

#include <iostream>
#include <list>
#include <cstring>
using namespace std;

//
// https://www.youtube.com/watch?v=gyA7uDlazkc&t=36s
//

class c_hash_table 
{
public:
	bool isEmpty() const; // *** 
	int hashFunction(int key);
	void insertItem(int key, string value);
	void removeItem(int key); // each key is distinct and appears once. 
	string searchTable(int key);
	void printTable();
	// static const int hashGroups = 10;

private:
	// for the seperate chaining method the number of groups to use must be known:
	 static const int hashGroups = 10; 
	//	'static': specifying the storage lifetime beyond the scope of the containing module. 
	// if for instance, we want to use the member, an instance of the class, an object, has to be generated first. 
	// but, to use it as index or value for other members in the class, like here in the definitions stage, then the member cannot belong to a specified isntance of the class, but rather to the whole class, and this is done by its specification as static. 
	// in matlab its equivalent to marking it under propertis (const). 
	//	'const': qualifying the type so that will not be able to change. 

	list<pair<int, string>> table[c_hash_table::hashGroups]; // array of list. every list is pair of int and string. 
		// list 1, index0. list 2, index 1.. 



};


