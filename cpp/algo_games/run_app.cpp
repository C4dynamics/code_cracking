// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

#include <iostream>
#include <vector>

int maxArea(std::vector<int>& height);
std::vector<std::string> generateParenthesis(int n);
void backtrack(std::vector<std::string> *list, std::string str, int open, int close, int max);
void rotate(std::vector<std::vector<int>>& matrix);


void foo1(int*  arr)	  { std::cout << sizeof(arr) << '\n'; }	// out:	4
void foo2(int   arr[])	  { std::cout << sizeof(arr) << '\n'; }	//		4
void foo3(int   arr[10])  { std::cout << sizeof(arr) << '\n'; }	//		4
void foo4(int (&arr)[10]) { std::cout << sizeof(arr) << '\n'; }	//		40
void foo5(int (&arr))	  { std::cout << sizeof(arr) << '\n'; }	//		
// foo4:
//		the parameter type is reference. 
//		A reference can be bound only to an expression of the exact same type.
//		For this reason the array doesn't decay, because a reference to an array can't be bound to a pointer, it can only be bound to an array of the same type 
//		(in this case array of 10 integers) ? and foo5 is wrong when passing the same arg as for foo4. 

// arrays "decay" into pointers. 
// 1  A C++ array declared as int numbers [5] cannot be re-pointed, i.e. you can't say numbers = 0x5a5aff23. 
// 2  More importantly the term decay signifies loss of type and dimension; numbers decay into int* by losing the dimension information (count 5) and the type is not int [5] any more. 
// 




int main()
{
	std::cout << "main \n\t";


	/// <summary>
	///			maxArea()
	/// </summary>
	/// <returns></returns>
	/// 
	std::vector<int> v1 = { 1, 1 };// { 1, 8, 6, 2, 5, 4, 8, 3, 7 };
	

	std::cout << "v1 = ";
	for (auto &v : v1) { // deduce the type from its initialization. here, int. 
		std::cout << v << " ";
	}
	std::cout << std::endl;

	int maxa = maxArea(v1);
	std::cout << maxa << std::endl;
	std::cout << std::endl << std::endl;

	/// <summary>
	///			generateParenthesis()
	/// </summary>
	/// <returns></returns>
	/// 
	std::vector<std::string> ls = generateParenthesis(4);
	for (auto s : ls)
		std::cout << s;

	std::cout << std::endl << std::endl;

	/// <summary>
	///			rotate()
	/// </summary>
	/// <returns></returns>
	/// 
	std::vector<std::vector<int>> mat;
	int n = 4;
	int num;
	for (int c = 0; c < n; c++) // columns
	{
		mat.push_back({});
		for (int r = 0; r < n; r++) {// rows
			num = n * r + c + 1;
			mat[c].push_back(num);
			std::cout << num << " "; //  std::endl;
		}
		std::cout << std::endl;
	}

	for (auto it1 : mat) {

		for (auto it2 : it1)
			std::cout << it2 << " ";

		std::cout << std::endl;
	}
	std::cout << std::endl << std::endl;

	 rotate(mat); // why thus? if rotate accepts an address and mat is generated by value (no through the new keyword) then the delivery of mat itself should contradict the argument of rotate.
	// stack overflow:
	// In C++, things are passed by value unless you specify otherwise using the &-operator (note that this operator is also used as the 'address-of' operator, but in a different context). This is all well documented, but I'll re-iterate anyway:
	 // void rotate(std::vector<std::vector<int>>& matrix) is like 
	 //		void foo4(int (&arr)[10]) 
	 //		namely it accepts and expects reference to a known type. that's the reason that the array arr doesnt decay and appears with its size explicitly. 
	 // an alias to the value is generated. 


	
		int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
		foo1(arr);
		foo2(arr);
		foo3(arr);
		foo4(arr);
		// foo5(arr); // a reference type -- the argument of foo5() -- cannot be initializied with a value of type int[10]


}


int maxArea(std::vector<int>& height) {
	//
	//  Container With Most Water
	// 
	// https://leetcode.com/problems/container-with-most-water/
	// 
	// You are given an integer array height of length n.There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
	// Find two lines that together with the x - axis form a container, such that the container contains the most water.
	// Return the maximum amount of water a container can store.
	// Notice that you may not slant the container.
	// 
	// solution:
	//	1 calculate the matrix of amounts for each pair of columns.
	//		find the max element in the matrix. huge amount of memory. huge amount of time. how much? order of complexity? 
	//	2 treat it like sorting. the two elements that make the highest amount are preceded	to the top. 
	// 	   but how would we know if the current pair is the best? it should be marked in a matrix. solution 1. 
	// 	3 prepare a variable that stores the best indices so far and the amount. 
	//		this one is still of O(n^2) but consumes much smaller memory. 
	//		but we dont need to start the next loop from the beginning as we already tested the i=1,j=1 pair and compared it to the other values of j. then for i=2 we can start with j=2. then the complexity reduced to O(n*(n/2)) which is still O(n^2)
	//	4 maybe the same method as quick sort can help here. divide the length by two. take it as pivot. scan to the left. scan to the right. wont work. there are maybe columns pair at the two sides of the pivot. 
	// 
	// 	   hint:
	// 	   Start with the maximum width container and go to a shorter width container if there is a vertical line longer than the current containers shorter line. This way we are compromising on the width but we are looking forward to a longer length container.

	// 	   5 more efficient solution:
	// 	   start with the two widest columns. 
	// 	   for the left column: look for higher column to the right, if this column area with the right column is greater, then mark this as the left column. 
	// what happans when i am looking for a higher column in the right of the left column? doesnt it mean that i miss the option to take the second as the right column?
	// let's say that from the left it's thus: 8 9 0 2 1 3
	// [8		3]
	// [ 9		3] 
	// 	   immediately lose a possible solution [8 9]
	//		but it's useless to look for a higher column from the already higher one because the shorter determins the capacity. 
	// 	   then:
	// 	   start with most width contatiner. 
	// 	   find the shorter column. let's say it's the left one. 
	// 	   look for a higher column in the right. 
	// 	   if the new container is grater than the previous, mark this as the left column. 
	// 	   now find again the shorter column, let's say it's now the rihght one. 
	// 	   look for higher in the left. 
	// 	   shoud i start the search in the current left column or in the left beginning of the container?
	// 	   if the left whould be possilbe to have bigger ammount then the prevous search wouldnt end succesfuly in new clumn. 
	// 
	// This algorithm goes through each array element only once to find the result, so the time complexity of this algorithm is O(n).
		//


	std::vector<int>::iterator h1, h2, cl, cr;
	h1 = cl = height.begin();
	h2 = cr = height.end() - 1;

	std::cout << "c1 c2 dx dy m amnt" << std::endl;

	int dx, dy, dh1, dh2, amnt;
	bool leftshorter;
	//for (; h1 != height.end(); h1++) {
		dh1 = std::distance(height.begin(), h1);
	//	for (h2 = h1; h2 != height.end(); h2++) {
		dh2 = std::distance(height.begin(), h2);
		dx = std::distance(h1, h2);
		dy = std::min(*h1, *h2);
		amnt = dx * dy;
		int pts[3]{ dh1, dh2, amnt }; // add indices for debug. 

		while (h1 != h2) {
			leftshorter = *h1 <= *h2;

			if (leftshorter) {
				h1++;
				dh1 = std::distance(height.begin(), h1);
			}
			else {
				h2--;
				dh2 = std::distance(height.begin(), h2);
			}
			dx = std::distance(h1, h2);
			dy = std::min(*h1, *h2);
			amnt = dx * dy;

			std::cout << dh1 << "  " << dh2 << "  " << dx << "  " << dy << "  " << amnt << "  " << pts[2] << std::endl;
			if (amnt > pts[2]) {

				pts[0] = dh1;
				pts[1] = dh2;
				pts[2] = amnt;
				cl = h1; // if the right was shorter so in anyway h1 didnt change. 
				cr = h2;
			}


			//	}
			//}
		}
	return pts[2];

}




std::vector<std::string> generateParenthesis(int n) {
	/* 
	Given n pairs of parentheses, write a function to generate all combinations of well - formed parentheses.
	
	https://leetcode.com/problems/generate-parentheses/

	Example 1:
	Input: n = 3
	Output : ["((()))", "(()())", "(())()", "()(())", "()()()"]
	
	Example 2 :
	Input : n = 1
	Output : ["()"]
	
	Constraints :
	1 <= n <= 8

	Examples 
		n = 0
			--
		n = 1
			()
		n = 2
			(())
			()()
		n = 3
			()()()
			()(())
			(()())
			(())()
			((()))
			or wrt n = 2:
			()() ()
			( ()() )
			() (())
			(()) ()
			( (()) )
		n = 4

			(((( ))))		
			((() ))()		
			((() )())
			((() ()))
			(() (()))
			(() ())()
			(() )(())
			(() )

			(() ..
			() ..
	algo.:
		n = 0:			--
		n = 1:
						()
		n = 2:
						(n=1)
						()n=1
								n=1()
		n = 3:			(n=2)
						()n=2
								n=2()
		n = 4:			(n=3)
						()n=3
								n=3()


	*/ 

	std::vector<std::string> list;
	backtrack(&list, "", 0, 0, n); // while in java list can be transfered itself in c++ objects that are not generated by the new keyword are created also on the stack and are transfered by value. to transfer them by reference the ampersend keyword needs to be used. 
	return list;
}


void backtrack(std::vector<std::string> *list, std::string str, int open, int close, int max) {

	if (str.length() == 2 * max) {
		(*list).push_back(str);
	}

	if (open < max)
		backtrack(list, str + "(", open + 1, close, max);
	if (close < open)
		backtrack(list, str + ")", open, close + 1, max);
}




void rotate(std::vector<std::vector<int>>& matrix) {
	/*
 You are given an n x n 2D matrix representing an image, 
 rotate the image by 90 degrees (clockwise).

 You have to rotate the image in - place, which means you have to modify the input 2D matrix directly.
 
 DO NOT allocate another 2D matrix and do the rotation.

	example:

	1 2 3	 7 4 1 	
	4 5 6 -> 8 5 2 
	7 8 9	 9 6 3 

	Constraints:
	n == matrix.length == matrix[i].length,		squared matrix.
	1 <= n <= 20								no more then 20x20
	-1000 <= matrix[i][j] <= 1000				no entry is larger than 1000.


	solutions:

	1 anothe matrix is not allowed but an axualray variable may indeed be used to free position (i, j) and insert another number there:

			 2 3   7 2 3   7 2 1   7 2 1 
		   4 5 6   4 5 6   4 5 6   4 5 6 
		   7 8 9     8 9   9 8	   9 8 3 

		   7 2 1   7 4 1   7 4 1   7 4 1 
		     5 6   8 5 6   8 5	   8 5 2 
		   9 8 3   9   3   9 6 3   9 6 3 


			1  2  3  4					13 9  5  1
			5  6  7  8					14 10 6  2 
			9  10 11 12					15 11 7  3
			13 14 15 16					16 12 8  4

													
													k = 1
			   2  3  4			1					(k, 1)
			5  6  7  8
			9  10 11 12
			13 14 15 16

			13 2  3  4			1	13				(n, k)
			5  6  7  8
			9  10 11 12
			   14 15 16

			13 2  3  4			1	16				(n, n)
			5  6  7  8
			9  10 11 12
			16 14 15 

			13 2  3  			1	4				(k, n)
			5  6  7  8
			9  10 11 12
			16 14 15 4

			13 2  3  1			1					(k, n)
			5  6  7  8
			9  10 11 12
			16 14 15 4

			---
													k = 2
			13 2  3  1			5					(k, 1)
			   6  7  8
			9  10 11 12
			16 14 15 4

			13 2  3  1			5	14				(n, k)
			14 6  7  8
			9  10 11 12
			16    15 4

			13 2  3  1			5	12				(n-k+1, n)
			14 6  7  8
			9  10 11  
			16 12 15 4

			13 2     1			5	3				(1, n+k-1)
			14 6  7  8
			9  10 11 3
			16 12 15 4

			13 2  5  1			5					(1, n+k-1)
			14 6  7  8
			9  10 11 3
			16 12 15 4

			---
													k = 3
			13 2  5  1			9					(k, 1)
			14 6  7  8
			   10 11 3
			16 12 15 4

			13 2  5  1			9	15				(n, k)
			14 6  7  8
			15 10 11 3
			16 12    4

			13 2  5  1			9	8				(n-k+1, n)
			14 6  7   
			15 10 11 3
			16 12 8  4

			13    5  1			9					(1, n-k+1)
			14 6  7	 2
			15 10 11 3
			16 12 8  4

			13 9  5  1								(1, n-k+1)
			14 6  7	 2
			15 10 11 3
			16 12 8  4

			---

			13 9  5  1
			14    7	 2		6
			15 10 11 3
			16 12 8  4

			13 9  5  1		6 7 11 10
			14 10 6	 2		
			15 11 7  3
			16 12 8  4


			
			*/

// the no. of env. to process is n - 2.


	int nenv = matrix.size() - 2;
	int itemtemp;

	std::vector<std::vector<int>>::iterator it1; // this iterator handles the outer vector. for each element in it another iterator may be defined. 
	// let's assume the outer vector is row and any vector in it holds a column.


	/*h1 = cl = height.begin();
	h2 = cr = height.end() - 1;
*/

	for (int e = 0; e < nenv; e++) { // number of envelopes to process. for n = 3, only once. 

		//for (it1 = matrix.begin(); it1 != matrix.end(); it1++) {

		// take out first element 
		int n = matrix.size() - 2 * e; // every env add 2 elemetns in row\col. 
		//int r = 0; // row
		//int c = 0; // column
		//int rem, mod;

		//rem = r / n;
		//mod = r % n;
		int itemtemp;


		//itemtemp = matrix.at(0).at(0);
				// matrix.at(it1);
				//matrix.at(0).at(j);
			//matrix.at(0).emplace(j, itemtemp);



		//}
		std::cout << " e = " << e << ", n = " << n << std::endl;

		std::cout << " row | col " << std::endl;

		for (int r = 0; r < n; r++) {

			std::cout << std::endl << " r = " << r << std::endl;

			itemtemp = matrix[e + r][e + r];
			std::cout << " " << r << " | " << e << std::endl;

			matrix[e + r][e + r] = matrix[n - e - 1][e + r];
			std::cout << " " << n - e - 1 << 
				
				
				" | " << e + r << std::endl;

			matrix[n - r - 1][e + r] = matrix[n - r - 1][n - e - 1];
			std::cout << " " << n - r - 1 << " | " << n - e - 1 << std::endl;

			matrix[n - r - 1][n - e - 1] = matrix[e][n - e - 1];
			std::cout << " " << e << " | " << n - e - 1 << std::endl;

			matrix[e][n - e - 1] = itemtemp;
			// std::cout << " " << e << " | " << n - e - 1 << std::endl;

		}

	}


}




















































