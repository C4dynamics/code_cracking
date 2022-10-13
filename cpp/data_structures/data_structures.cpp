//
// data_structures.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//
// C:\Users\dp28486\Documents\Tutorials\Cracking.the.Coding.Interview.6th.Edition.pdf
// 


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

#include "pch.h"
#include "c_hash_table.h"
#include "ContactList.h"
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <stdlib.h> 
#include <algorithm> // sort()


void q1();
int* q2(int* a1, int sa1, int* a2, int sa2, int *dim);
Contact* mergeTwoLists(Contact* list1, Contact* list2);

struct ListNode {
    int val;	// value stored in this node. temperature for exmaple. 
    ListNode *next;	// pointer to next node. 
    //
    ListNode() : val(0), next(nullptr) {} // some type of default constructor?  
    ListNode(int x) : val(x), next(nullptr) {} // adding first item constructor? 
    ListNode(int x, ListNode *next) : val(x), next(next) {} // i'm not sure how this mechanism of struct works. 
};


int main()
{
	std::cout << "main \n\t";



	// hash table implementation 
	// https://www.youtube.com/watch?v=gyA7uDlazkc&t=36s
	//

	std::cout << "Hash Table: \n\t";

	// std::cout << c_hash_table::hashGroups;

	c_hash_table ht;
	if (ht.isEmpty()) {
		cout << "Correct.";
	}
	else {
		cout << "Wrong.";
	}

	ht.insertItem(206, "jim"); // <phone number, name>
	ht.insertItem(207, "BOB"); // since the lists number is ten only the last digit is significant for the positioning. 
	ht.insertItem(334, "SAli");
	ht.insertItem(151, "barb");
	ht.insertItem(102, "jony");
	ht.insertItem(940, "rob");
	ht.insertItem(173, "ezra");
	ht.insertItem(905, "shouki"); 
	ht.insertItem(905, "jimmy"); // the same key - phone with different value to see if our check for existing key works. 
	
	ht.printTable();

	ht.removeItem(151);
	ht.removeItem(100);


	if (ht.isEmpty()) {
		cout << "some error fallen in the code .";
	}
	else {
		cout << "correct.";
	}




	//
	// Contact Linked List. see
	// https://www.youtube.com/watch?v=7vZo17iv1zQ&t=409s
	// 

	std::cout << "Linked List: \n\t";

	int r1[] = { rand() % 100, rand() % 100, rand() % 100 };
	std::sort(begin(r1), end(r1));

	Contact *c1 = new Contact("Tom", r1[2]);
	Contact *c2 = new Contact("Bob", r1[1]);
	Contact *c3 = new Contact("Sally", r1[0]);

	ContactList *cl1 = new ContactList();

	cl1->addToHead(c1);
	cl1->addToHead(c2);
	cl1->addToHead(c3);

	cout << endl << "list1: " << endl;
	cl1->printList();



	int r2[] = { rand() % 100, rand() % 100, rand() % 100 };
	std::sort(begin(r2), end(r2));

	Contact* k1 = new Contact("yosi", r2[2]);
	Contact* k2 = new Contact("shmuel", r2[1]);
	Contact* k3 = new Contact("hanna", r2[0]);

	ContactList* cl2 = new ContactList();

	cl2->addToHead(k1);
	cl2->addToHead(k2);
	cl2->addToHead(k3);

	cout << endl << "list2: " << endl;
	cl2->printList();

	/*
	// 
	// some exercizes from websites:
	//
	

	// q1(); 
	int a[] = { 1, 2, 44, 5, 20 };
	int b[] = { 30, 1, 11, 44, 33, 33, 33 };
	int *c;
	int d[] = { 0 };
//	d[0] = 0;


	std::cout << "array 1 \n\t";
	for (int i = 0; i < 5; i++) {
		std::cout << std::to_string(a[i]) + "\n\t";
	}

	std::cout << "array 2 \n\t";
	for (int i = 0; i < 7; i++) {
		std::cout << std::to_string(b[i]) + "\n\t";
	}

	c = q2(a, 5, b, 7, d);

	std::cout << "out array \n\t";
	for (int i = 0; i < *d; i++) {
		std::cout << std::to_string(c[i]) + "\n\t";
	} */
	




	//
	// Contact Linked List. see
	// https://leetcode.com/problems/merge-two-sorted-lists/
	// 

	
		// int x, ListNode * next) : val(x), next(next) {} // i'm not sure how this 

	Contact* longlist = mergeTwoLists(c3, k3);

	cout << endl << "unified list: " << endl;
	while (longlist != nullptr) {
		cout << longlist->name << "   " << longlist->val << endl;
		longlist = longlist->next;
	}
}



void q1(void) { // generate a class that suggests generation of hash table objects.
				// use an array of linked lists and a hash code function.
				// evaluate the time and space consumption of the search. 

	std::cout << "question 1 - hash table \n\t";

	class hash_t {
	public:

		int data;
		hash_t *next = nullptr;

		hash_t(int d) {
			data = d;
			//std::cout << this->data + this->next "\n\t";
		}

		hash_t(const hash_t &ohash) {
			data = ohash.data;
			next = ohash.next;
		}

		void append_to_tail(int d) {

			hash_t end(d);
			
			hash_t *n = this; // if (&Object != this) { .. }
								// -> do not execute in cases of self-reference. 
								// if the address of object is different than the address 'this'. 
								// *this is not an address, it is the value in the address 'this'. 
			
			while (n->next != nullptr) {
				std::cout << "data: " + std::to_string(n->data) + "\n\t";
				n = n->next;
			}

			n->next = & end;
		}

		void print_list() {
			hash_t *n = this;
			while (1) {
				std::cout << "data: " + std::to_string(n->data) + "\n\t"; //+ ", next address: " + std::to_string((int)&n->next) + "\n\t";
				
				if (n->next != nullptr) {
					n = n->next;
					continue;
				}
				else
					break;
			} 
			
		}
 	};

	hash_t h1(1);
	hash_t &h2 = h1;
	h2.print_list();
	h2.append_to_tail(2);
	h2.print_list();
	h2.append_to_tail(8);
	h2.append_to_tail(5);

	
	//
	// comments
	//
	// const: 
	//		Whenever const keyword is attached with any method(), variable, pointer variable, and with the object of a class, it prevents that specific object/method()/variable to modify its data items value.
	//	java vs c++
	/*
	Yes, it's doable in C++. But the syntax would be a little different:
			1) this->instead of this.
			2) private: / public: instead of private / public per member
			3) remember to have; at the end of the class
			4) A* as member(or std::uniqe_ptr<A> or std::shared_ptr<A> or std::weak_ptr<A>).
		Items 1 - 3 are merely syntax. 
		Item 4 is an essential difference between Java and C++:
		In Java an object variable is a reference to the object while in C++ an object variable is a value.This is why you can't hold in C++ a direct member of yourself, as is, the size of the object would be infinite (A holding an actual value of A, holding an actual value of A, ... recursively).
		In Java when A holds an A, it just holds a reference to the other A (yes, you can still access recursively the referenced A, but it is not part of your size, you just hold a reference to it, it is stored elsewhere in memory.The addition to your size is just the size of a reference).
		You can achieve similar semantics in C++ with reference variables or pointers, by adding & for a reference or *for a pointer :
			A &a2 = a1; // a2 is a reference to A, assigned with a reference to a1
						// note that a1 above is assumed to be also of type A&
			A *a2 = a1; // a2 is a pointer to A, assigned with the address stored in a1
						// note that a1 above is assumed to be also of type A*
		Java Garbage Collector reclaims unused memory while in C++ the programmer needs to handle that, possibly with C++ tools such as smart pointers.
		Java Garbage Collector reclaims unused memory via Trace by Reachability, C++ smart pointers are based on scope lifetime. Additionally, C++ shared_ptr is based on reference counting which has its advantages, but is subject to reference cycles possible leak of memory, which should be avoided with proper design of your code.
		*/ 

	//
	// results
	//
}


int* q2(int* a1, int sa1, int* a2, int sa2, int *dim) { // this function implements intel interview question: 
			// given two arrays, return the common members with no multiplicity. 

	
	std::cout << "question 2 - return common members \n\t";
	std::unordered_map<int, int> umap;

	for (int i = 0; i < sa1; i++) 
		umap[a1[i]] = 1;

	int cnt = 0;
	for (int i = 0; i < sa2; i++) 
		if (umap.find(a2[i]) != umap.end()) { // if exists
			umap[a2[i]] = 2;
			cnt++;
		}

	static int *aout = new int(cnt);
	int cnt2 = 0;

	for (std::unordered_map<int, int>::iterator it = umap.begin(); it != umap.end(); ++it) {
		if (it->second == 2) {
			aout[cnt2] = it->first;
			cnt2++;
		}
	}

	dim[0] = cnt;
	return aout;

}


//ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
Contact* mergeTwoLists(Contact * list1, Contact * list2) {
	// https://leetcode.com/problems/merge-two-sorted-lists/
	/* You are given the heads of two sorted linked lists list1 and list2.
		Merge the two lists in a one sorted list.
		The list should be made by splicing \\ joining \\ together the nodes of the first two lists.
		Return the head of the merged linked list.

		Constraints:
		The number of nodes in both lists is in the range [0, 50]. // no more than 50 elements in each list?
		-100 <= Node.val <= 100 // means that if for example the linked list is of temperature measures then each node is a measure that cannot exceed -100, 100. 
		Both list1 and list2 are sorted in non-decreasing order.
		*/

	/*
	*
	 * Definition for singly-linked list. 
	 * I think it's sort of extremly thin implementation of linked list. 
	 see the files Contact.cpp and ContactList.cpp for complete implementation of contacts linked list 
	 */

	  //struct ListNode {
	  //    int val;	// value stored in this node. temperature for exmaple. 
	  //    ListNode *next;	// pointer to next node. 
		 // //
	  //    ListNode() : val(0), next(nullptr) {} // some type of default constructor?  
	  //    ListNode(int x) : val(x), next(nullptr) {} // adding first item constructor? 
	  //    ListNode(int x, ListNode *next) : val(x), next(next) {} // i'm not sure how this mechanism of struct works. 
	  //};
	 /**/


	//class Solution {
	//public:
		//mergeTwoLists() {
		// 
		// 
		// 
			// find the list with the smaller first node. 
			// save the node of the header to return later.
			// manage two lists: one is the leading list. we process in the nodes of this list therefore its header we saved earlier. 
			// second list is the one which is going and decreasing.  
			// 
			// what's the leading list?
			//	use list1 always: swap if not true. 
			//	mark boolean if not 1. make if for each one of the cases. 
			//	define new object that will serve as the leading object current position. 
			// 
			// now, find the node with the next smaller value. 
			// if the next smaller is on the leading list, then advacne the primary link header to the next node, if it's not, then override the secondary list header with the next node (of the leading list), and pass to the current node the link to the node with the smaller value. 


	if (list1 == nullptr) {
		return list2;
	}

	if (list2 == nullptr) {
		return list1;
	}



	cout << endl << "before:" << endl << "first list: " << endl;




	Contact* temppt1 = list1;
	while (temppt1 != NULL) {
		cout << temppt1->val << " ";
		temppt1 = temppt1->next;
	}

	cout << endl << "second list: " << endl;
	temppt1 = list2;
	while (temppt1 != NULL) {
		cout << temppt1->val << " ";
		temppt1 = temppt1->next;
	}



	bool list1leading;
	Contact *listHeader;

	if (list1->val <= list2->val) {
		list1leading = true;
		listHeader = list1; 
	}
	else {
		list1leading = false;
		listHeader = list2;
	}
	Contact* tempadress;

//	while ((list1->next != nullptr) & (list2->next != nullptr)) {
	while (((list1leading) & (list2 != nullptr)) | ((!list1leading) & (list1 != nullptr))) {

		if (list1leading) {

			if (list1->next == nullptr) {
				// this must be the last transition to list2, since list2 is not empty - by the while condition - and this list is over - by this condition. 
				list1leading = false;
				list1->next = list2;
				list1 = nullptr; 
			}
			else if (list1->next->val > list2->val) {
				list1leading = false;
				tempadress = list1->next;
				list1->next = list2;
				list1 = tempadress; // now list 2 ls leading and the head of list 1 becomes the next one that was detached from the series. 
			}
			else {
				list1 = list1->next;
			}


		}
		else { // list 2 is the leading. 

			if (list2->next == nullptr) {
				list1leading = true;
				list2->next = list1;
				list2 = nullptr; // list 2 is over. 
			}
			else if (list2->next->val > list1->val) {
					// if list2 is leading and its next node is empty then the next node must be in the second list. 
				// or if list 2 is leading and its next item is bigger than the item in the sencod list then also the list should be serialized to there. 

				list1leading = true;
				tempadress = list2->next;
				list2->next = list1;
				list2 = tempadress;
			}
			else {
				list2 = list2->next;
			}
			


		}

	}


	cout << endl << endl << "after:" << endl << "leading list: " << endl;

	temppt1 = listHeader;
	while (temppt1 != NULL) {
		cout << temppt1->val << " ";
		temppt1 = temppt1->next;
	}
	cout << endl << "secondary list: " << endl;
	if (list1leading) {
		temppt1 = list2;
	} 
	else {
		temppt1 = list1;
	}


	while (temppt1 != NULL) {
		cout << temppt1->val << " ";
		temppt1 = temppt1->next;
	}

	cout << endl << endl;

	return listHeader;

}


/*
	vector vs list


	C++ List
memory continuity: List in C++ stores the elements at the non-contiguous memory location. It is considered a doubly linked list internally.	
Insertion and deletion of elements in List at any position take constant time as it involves the use of pointers and their swapping.
List does not have any fixed size or a default size as it is a doubly-linked list and can be resized upon insertion or deletion.
Memory required to store the elements in the List is comparatively large as it holds the element as well as the pointers for the next and previous nodes.
Random access of elements in the List is not possible as it is implemented as the doubly linked list. Programmers need to access the elements by traversing through the pointers.
In case of List, iterators remain valid even if the elements are inserted or deleted from it.

	C++ Vector
memory continuity: A vector in C++ stores the elements at the contiguous memory location. It is considered to be a type of dynamic array internally.
Insertion and deletion of elements at the last take constant time but insertion and deletion elsewhere (in the starting or middle) takes a lot of time as the array needs to be traversed.
Vector is a dynamic array and has the default size.
Memory required to store the elements in the Vector is lesser than List as it uses memory for the element only.
As the elements in Vector are stored sequentially like an array, so the elements can be accessed randomly by providing the index number only.
Iterators become invalid when the elements are deleted or inserted from it.
Vector declaration:		vector<type> name;
Vector initialization:	vector<type> name = {values};
access:					at() Returns a reference to the element at a specified location in the						vector.


	C++ Array (vs vector)
Array is index based.
As array is fixed size, once initialized can’t be resized.
Array is memory efficient data structure.
Array access elements in constant time irrespective of their location as elements are arranged in a contiguous memory allocation
Array declaration:		type name[size];
Array initialization:	type name[size] = {values};

*/



/*
* 
*		stack, heap, c++, java, c#		
* 
how to create / instantiate objects in c++
https://www.youtube.com/watch?v=Ks97R1knQDY&list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb&index=37
00:08:00

c#, java: always allocate on the heap. in c# struct on the stack but in java everything is on the heap. 
c++: provides the option to allocate on the stack. and this when not using the new keyword. 
reasons for not allocaing on the stack: big variable, lifetime out of current scope.
reasons for not allocaing on the heap: memory management, speed.

\\ does that mean classes in c++ (which are not instantiated with new keyword) are actually always passed by value? \\

c++ example:
Entity entity; \\ invoke default constructor. it's not null pointer. 
\\ if we call:
std::cout << entity.GetName() << endl;
the system prints 'unkown'.
\\ also option to not use the default constructor:
Entity entity = Entity("Cherno") \\ equivalent to:
Entity entity("Cherno")
\\ still on the stack.
Entity* entity = new Entity("Cherno")
\\ this less desired. it's on the heap. but it will be available outside the scope of the function. 
scope mut not be just function it may even be empty scope, as in the empty bracket:
Empty* e; {
	Entity entity("Cherno")
	e = &entity
{
Cherno is not available here. 

where Entity is:
*/
class Entity {
	using String = std::string;

private:
	String m_Name;
public:
	Entity() : m_Name("unknown") {}
	Entity(const String& name) : m_Name(name) {}

	const String& GetName() const { return m_Name; }
};






/*
		by value, by reference, c++, java 


The reference type in C++ is different than the reference type in Java. In 
Java:
	value:		primitive data types - byte, short, int, long, float, double, boolean, char.
	reference:	All other variable types.
				(i.e. String is a reference type, but Strings in Java are immutable so a new object will be created in the heap when attempting to modify a String).
c++:
	value:		anything that is not generated with the new keyword.
	reference:	an address of a variable.



	https://levelup.gitconnected.com/c-c-pointer-vs-c-reference-vs-java-reference-facc037eb2a5
  Java References are like C or C++ pointers. not like the C++ reference type. 

  The biggest difference is that Java references always point to objects, where C and C++ pointers can point to anything. 

When a reference variable is passed as an argument, the memory address of the object in heap is passed and the modifications are done directly on the object itself. For example:


*/






