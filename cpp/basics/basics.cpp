// basics.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//
// https://www.toptal.com/c-plus-plus/interview-questions
//

//
// https://docs.microsoft.com/en-us/cpp/cpp/?view=msvc-170
//

#include "pch.h"
#include <iostream> 
#include <sstream>
#include <string>
#include <vector>

using namespace std; // P.S., avoid using namespace std whenever possible! - https://stackoverflow.com/questions/1452721/why-is-using-namespace-std-considered-bad-practice

class my_class {
public:
	my_class(string name) : cname(name) {
		/*for (int c = 1; c < 10; c++) {
			cname[c] = name[c];
		}*/
		print();
	}
	string cname;
	/*size_t size() {
		return sizeof(cname);
	}*/
	void print() {
		cout << cname + "\n\t";
	}
};

struct my_struct_t  {   // Declare my_struct_t struct type
	char name[10];
};

int  q1(void);
void q2();
void q3(void);
void q4(void);
void q4sup(void);
size_t getPtrSize(char* ptr);
void q5(int iOption);

int main() {
	/*
	C++, unlike Java, does perfectly allow for standalone (i.e.non-class) functions, i.e. is also procedural, is not purly object oriented.
	This design comes all the way from C. Compatibility with existing C code was a major design goal of C++ early on, and there was hardly any real benefit to changing the entry point convention. So they kept the C standard in place.
	So there should be no problem to define a class method called main, and to call it from the global main.
	*/
	q1();
	q2();
	q3();
	//q4sup();
	q4();
	q5(1);
}

int q1(void) { // arithmetic between different types.  
	// What will the line of the code below print out and why?
	cout << "question 1 \n\t";

	cout << 25u - 50 << endl;
	//cout << pow(2, 32) << endl;
	//cout << pow(2, 32) - 25;
	//cout << "\n";
	return 0;
	// 1 convert all to the higher type. also the result will be of the same type.  
	// 2 calculate arithmetic: 25u - 50u = -25u.
	//		but -25 in unsigned type is overflow: -25u = 25 % 2^32 = 4294967296 - 25 = 4294967271
	// 3 why not converted to char*? the function probbely knows to accept also clean number input.  

	// the operand with the lower type will be promoted to the type of the higher type. hierarchy (high to low):
		//							bytes
		// long double				8
		// double					8
		// float					?
		// unsigned long int		4	(unsigned long)
		// long int					4	(long)
		// unsigned int				4
		// int (lowest).			4 
	// char 1 byet may also be added here 
}

void q2() { // size of pointer and size of pointed object 
	// What is the error in the code below and how should it be corrected?
	cout << "question 2 \n\t";
	cout << "size of integer: " + to_string(sizeof(int)) + "\n\t";

	my_struct_t *bar;
	//
	// on pointers asterisk:
	//	int *myVariable, myVariable2; 
	//		myVariable has type int*, myVariable2 has type int.
	//  int* myVariable, myVariable2;
	//		myVariable has type int*, myVariable2 has type int.
	// THEN THE first programming style is more intuitive.
	//
	// 
	// on pointers and sizeof operators
	//  sizeof(bar)
	//		size of the pointer itself (os dependant).
	//	sizeof(*bar)
	//		size of the object (e.g. structure fields) pointed to by bar
	//  my_struct_t bar[10]; 
	//	sizeof(bar) ?the size of the pointer?
	//		
	/* on char type
		There's no dedicated "character type" in C language. char is an integer type, same as int, short and other integer types. char just happens to be the smallest integer type (8 bits). So, just like any other integer type, it can be signed or unsigned.
		It is true that char is mostly intended to be used to represent characters. But characters in C are represented by their integer "codes" (e.g. 'Z' = 91. that's probabely no more than 2^8 letters) , so there's nothing unusual in the fact that an integer type char is used to serve that purpose.
		The only general difference between char and other integer types is that plain char is not synonymous with signed char, while with other integer types the signed modifier is optional / implied.
		char = unsigned char.
		int = signed int.
	*/

	/* ... do stuff, including setting bar to point to a defined my_struct_t object ... */

	my_struct_t mst = { {{'a'},{'a'},{'a'},{'a'},{'a'},{'a'},{'a'},{'a'},{'a'},{'a'}} };
	bar = &mst;

	cout << "size of bar: " + to_string(sizeof(*bar)) + " (the size of the object that is pointed by bar) \n\t";
	cout << "the content of bar before memset: \n\t";

	for (int i = 0; i < sizeof(*bar); i++) {
		cout << bar->name[i];
		cout << "\t";
	}

	cout << "\n";


	memset(bar, 0, sizeof(*bar)); // converts the value 0 to unsigned char and copies it n times, where n is the length of the array in the in arg, the copies are then stored in the enteries of the array 'bar'.
	// char, unsigned char
	cout << "the content of bar after memset: \n\t";

	for (int i = 0; i < sizeof(*bar); i++) {
		cout << to_string(bar->name[i]);
		cout << "\t";
	}

	cout << "\n";

	// the first argument of memset must be a char type so the content can be copied to. but it was just the pointer to the array itself, without indicating the required field. 
	// or instead of defining bar as pointer it should have defined as an array. BUT IT SAYS on passing that it sets bar to point to a predefined object. 
	// then anyway sizeof() on pointer is wrong.
}

void q3(void) { // increment order ++i, i++
	// What will i and j equal after the code below is executed? Explain your answer.
	cout << "question 3 \n\t";

	int i = 5;
	int j = i++; // a++ (post-increment) vs. ++a (pre-increment)

	cout << "i = " + to_string(i) + ", j = " + to_string(j) + "\t\n";

	// i = 5, j = 6. no.
	// true: i = 6, j = 5; explanation:
	// the assignment j = i is performed first. then i is advanced. 
}

void q4sup(void)
{
	cout << "question 4 - accesory \n\t";

	char szHello[] = "Hello, world!";

	/*char* ptr = szHello;
	size_t ptrSize = sizeof(ptr);
	cout << "\n\t The size of the pointer a" << endl;*/


	cout << "The size of a char is: "
		<< sizeof(char)
		<< "\n\tThe length of " << szHello << " is: "
		<< sizeof szHello
		<< "\n\tThe size of the pointer is "
		<< getPtrSize(szHello) << endl;
}
size_t getPtrSize(char *ptr) {
	size_t szp = sizeof(ptr);
	cout << "\n\t The size of the pointer is " + to_string(szp) + "\t\n";
	return szp;
}

void q4(void) {
	// Assuming buf is a valid pointer \\ of what object? \\ , what is the problem in the code below? What would be an alternate way of implementing this that would avoid the problem?
	cout << "question 4 \n\t";
	cout << endl;
	//my_class mc("zzzz");
	//my_class mc[10]
	//	//my_class *buf = &mc;
	//	//int buf[2] = { 10, 20 };
	//	//int *buf = myint;


	//	size_t sz = buf->size(); // std::size_t is the unsigned integer type of the result of the sizeof operator as well as the sizeof... operator and the alignof operator (since C++11).
	//	// operator -> is a dereference. buf is a pointer to int. then both -> and (*). should do the work. 
	//	// size_t sz = sizeof(szHello);
	//while (--sz >= 0) // --sz pre decreament: first decrease sz by 1 then test the condition greater than 0. 
	//{
	//	/* do something */
	//	// the function tuns on each element in the array.

	//}

	// the operation ->size() 
	// the size of an array first has to be taken from an array object and not from a pointer to the array. 
	// second the correct syntax to invoke the number of elements in an array is sizeof and not just size. 
}

void q5(int iOption) {
	//Consider the two code snippets below for printing a vector. Is there any advantage of one vs. the other? Explain.
	cout << "question 5 \n\t";

	my_class mc("zzz");
	mc.print();

	vector<my_class> vec;
	vec.push_back(mc);
	vec.push_back(my_class("yyy"));
	vec.push_back(my_class("xxx"));

	
	cout << "option 1: \n\t";

	// if (iOption == 1) {
		/* ... .. ... */
		//cout << "option 1: itr++ (post)\n\t";
		//for (auto itr = vec.begin(); itr != vec.end(); itr++) //  a++ post-increment
		//	itr->print();


		for (int itr = 0; itr != 3; itr++) //  a++ post-increment
			cout << to_string(itr) + "\n\t"; // 
		
		int itr = 0;
		int cnt = 0;
		while (itr != 3) {
			cout << to_string(itr) + "\n\t"; // 
			cnt = itr;
			itr = cnt + 1;
		}

	/*}
	else {*/
		cout << "option 2: \n\t";
		/* ... .. ... */

		//for (auto itr = vec.begin(); itr != vec.end(); ++itr) // ++a pre-increment
		//	itr->print();

		for (int itr = 0; itr != 3; ++itr) //  ++a pre-increment
			cout << to_string(itr) + "\n\t";

		itr = 0;
		cnt = 0;
		while (itr != 3) {
			cout << to_string(itr) + "\n\t"; // 
			cnt = itr;
			itr = itr + 1;
		}

	//}
}



//	CUDA
// Compute Unified Device Architecture
// a parallel computing platform and application programming interface (API).
// CUDA allows general - purpose computing on GPUs (GPGPU): an approach in which a software uses certain types of graphics processing units (GPUs) for general purpose processing.
// CUDA is a software layer that gives direct access to the GPU's virtual instruction set and parallel computational elements, for the execution of compute kernels.[1]




