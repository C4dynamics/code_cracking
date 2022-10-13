//
// bits.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//
// https://aticleworld.com/interview-questions-on-bitwise-operators-in-c/
// 

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

#include "pch.h"
#include <iostream>
#include <string>

// printf converter to print in binary format?
#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c"
#define BYTE_TO_BINARY(byte) \
  (byte & 0x80 ? '1' : '0'), \
  (byte & 0x40 ? '1' : '0'), \
  (byte & 0x20 ? '1' : '0'), \
  (byte & 0x10 ? '1' : '0'), \
  (byte & 0x08 ? '1' : '0'), \
  (byte & 0x04 ? '1' : '0'), \
  (byte & 0x02 ? '1' : '0'), \
  (byte & 0x01 ? '1' : '0') 
// printf("m: "BYTE_TO_BINARY_PATTERN" "BYTE_TO_BINARY_PATTERN"\n", BYTE_TO_BINARY(m >> 8), BYTE_TO_BINARY(m));

void q1();
void q2();

int two_complement(int x) {
	return ~x + 1;
}


int main()
{
	q1();
	q2();
}

// Compute the sign of an integer
// Check if an integer is even or odd


void q1(void) { // Check if an integer is even or odd
	// In 2’s compliment encoding, the MSB still functions as a sign bit. 
	// it is always ‘1’ for a negative number, and ‘0’ for a positive number. 
	// 
	// test for 8 bit signed int: 
	//		 negative number: 11110100 (-12) -> complete to one -> 
	//						  00001011		 -> to two -> 
	//					+ 1 = 00001100	(12) 


	std::cout << "question 1 even or odd \n\t";

	int x = 1;
	// create reference odd number (1):
	int m = 1; // only msb is one. 

	while (x != 0) {

		std::cout << "enter number \n\t";
		scanf_s("%d", &x);
		std::cout << "\t";


		if (m & x) {
			std::cout << "odd \n\t";
		}
		else {
			std::cout << "even \n\t";
		}
		std::cout << "\n\t";
	}

	// the operation bbbbb & 00001 does bitwise 'and' - between each equivalent bits - since 00001 is one only in the lsb then just number that ends with 1 - negative - returns true. 
}

void q2(void) { // detect opposite signs

	std::cout << "question 2 - integer opposite signs \n\t";

	int x1 = 1, x2;
	// create reference odd number (1)
	unsigned m = 2147483648; // only msb is one. - negative integer
	bool first_is_neg, second_is_neg, both_neg, both_pos;

	while (x1 != 0) {

		std::cout << "enter first number \n\t";
		scanf_s("%d", &x1);
		std::cout << "\t";
		std::cout << "enter second number \n\t";
		scanf_s("%d", &x2);
		std::cout << "\t";

		first_is_neg = x1 & m;
		second_is_neg = x2 & m;


		both_neg = first_is_neg && second_is_neg;
		both_pos = !first_is_neg && !second_is_neg;

		if (both_neg || both_pos) {
			std::cout << "equal signs \n\t";
		}
		else {
			std::cout << "opposite signs \n\t";
		}
		std::cout << "\n\t";
	}

	// better solution 
	x1 = 1;
	int x1xorx2;

	while (x1 != 0) {

		std::cout << "enter first number \n\t";
		scanf_s("%d", &x1);
		std::cout << "\t";
		std::cout << "enter second number \n\t";
		scanf_s("%d", &x2);
		std::cout << "\t";

		x1xorx2 = x1 ^ x2;

		if (x1xorx2 >= 0) {
			std::cout << "equal signs \n\t";
		}
		else {
			std::cout << "opposite signs \n\t";
		}
		std::cout << "\n\t";
	}
	/* THE CARET SIGN IMPLEMENTS BITWISE XOR - opposite detection:
	*	a	b		xor a b
	*	0	0		0		
	*	0	1		1	
	*	1	0		1
	*	1	1		0
	 00110100
   ^ 00011111 
   = 00101011 
		
		here, since two same type variables have the same sign, then logical xor generates false in the msb.
		false, 0, msb, is possitive number. 
		if the result is positive - the two numbers have the same sign
		if the result is negative - the numbers have opposite sign. 

	 */
}










