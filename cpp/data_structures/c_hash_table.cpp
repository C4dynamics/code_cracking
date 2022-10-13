#include "pch.h"
#include "c_hash_table.h"
#include <iostream>
#include <list>
#include <cstring>

using namespace std;
// 
// https://www.youtube.com/watch?v=2_3fR-k-LzI
// 

//
// the c_hash_table data structure implements a hash table of seperate chaining type. meaning when a collision between hashs occurs, the key will occupy a distinct key seperate from the other key that resulted in the same hash, using linked lists to deal with collisions. 
// 

bool c_hash_table::isEmpty() const {
	// if the cumolative size of all the lists is zero the table is empty. 
	// the scope resolution :: operator is used when class members are defined outside the classs  


	int sum{}; // ***  
	for (int i{}; i < hashGroups; i++) {
		sum += table[i].size(); // size returns the number of elements in the list. 
	}

	if (!sum) { // zero. 
		return true;
	}
	return false; // 
}

int c_hash_table::hashFunction(int key) {
	// since the no. of lists is 10 all the keys are divided into one of these 10 sectors. the selected key is moduled to one of these. 
	return key % hashGroups;
}

void c_hash_table::insertItem(int key, string value) {
	// cell: the list that the pair is going to be put into. 
	//		this is actually the table in the given index. 

	int hashValue = hashFunction(key);
	auto& cell = table[hashValue];
	// auto:
	//		Deduces the type of a declared variable from its initialization expression.
	// auto:		a value type (like int or char).
	// const auto:	a const type. 
	// auto&:		a reference type. 

	auto bItr = begin(cell);// iterator to the beginning of the list. 
	// let's assume the key doesnt exist. 
	bool keyExists = false;
	// let's confirm it:
	for (; bItr != end(cell); bItr++) {
		if (bItr->first == key) {
			keyExists = true;
			bItr->second = value;
			cout << "[WARNING] Key exists. Value replaced. " << endl;
			break; // every key is distnictive and appears only once.  
		}
	}
	// if doesnt exist:
	if (!keyExists) {
		// the cell is actually the list the we are intrested in. 
		cell.emplace_back(key, value); // emplace: to put into position
	}

	return;
}

void c_hash_table::removeItem(int key) {
	// find the list of interst by hashing value the key:
	int hashValue = hashFunction(key);
	auto& cell = table[hashValue]; // then cell is the intersting list. 
	auto bItr = begin(cell);	// initiate an iterator to the beginning of the list. 
	bool keyExists = false;	// once again assume the key does not exist. 
	// but if does exist, remove:
	for (; bItr != end(cell); bItr++) {
		if (bItr->first == key) {
			// exist, let's expunge
			keyExists = true;
			string value = bItr->second;
			// list remove vs erase:
			// erase(): which erases elements by their position (using an iterator)
			// remove():removes elements by their value.
			cell.erase(bItr); // an iterator returns iterator to the next iterator. 
			cout << "[INFO] Item removed. " << endl;
			break; // every key is distnictive and appears only once.  
		}
	}
	if (!keyExists) {
		cout << "[WARNING] Item not found. " << endl;
	}

	return;
}

void c_hash_table::printTable() {
	for (int i{}; i < hashGroups; i++) {
		if (table[i].size() == 0) continue;

		auto bItr = table[i].begin();
		for (; bItr != table[i].end(); bItr++) {
			cout << "[INFO]] Key: " << bItr->first << " Value: " << bItr->second << endl;
		}
	}
	return;
}



