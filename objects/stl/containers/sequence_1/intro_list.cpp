/* ***************************************************************************************
 * Filename: intro_list.cpp
 * Author: Lodewyk Jansen van Rensburg
 * Date: December 1, 2020.
 * Description: This is a program to demostrate the use of the std::list template
 * 		class defined inside the C++ Standard Template Library.
 * **************************************************************************************/

// Lives inside this header file.
#include <list>

#include <iostream> /* To perform basic console input and ouput*/
// What is it?
/*
	std::list is a secquence container defined in the STL library.
	It is an implementation of a double-linked list data structure.
	A linked-list is a linear data structure like an array but the data points are not 
		store in one block of memory one after the other.
	A doubly-linked list is a collection of nodes that are linked to one another.
	Doubly-linked: A node is ussualy a struct with 3 data members.
		- 1. Value: A member to store the data point that are of interest.
		- 2. Next: This is a pointer to the next element in the list.
			   - If Next = NULL, then the node is the last node in the list.
		- 3. Prev: This is a pointer pointing to the previous node in the list.
			   - If Prev = NULL, then you are at the first element of the list.
	Lastly: The program only maintains a one variable to store the head (first node) of
		the list. If you have access to the first node you can gain access to any of 
		the other nodes by walking along the list untill the desired node is found. 
	
	Unlike an array a list provides no random access.
		(This is important to know the type of iterators available for the container.)
*/

int main(){
	// I Methods of contruction:
	// ============================
	// 1. Default constructor. (empty list)
	std::list<int> empty_list;
	// 2. Fill the constructor with n elements, each containing a copy value provided.
	int n = 10, value;
	std::list<int> copied_list(n,value);
	
	return 0;
}
