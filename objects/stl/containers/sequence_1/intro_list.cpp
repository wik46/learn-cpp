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
// 1. Used inside remove_if().
bool is_12(int);

int main(){
	// I Methods of contruction:
	// ============================
	std::cout << "\nI Methods of construction: " << std::endl;	
	std::cout << "===========================" << std::endl;	
	// 1. Default constructor. (empty list)
	std::list<int> empty_list;
	// 2. Fill the constructor with n elements, each containing a copy value provided.
	int n = 10, value = 12;
	std::list<int> int_list(n,value);
	// 3. Linked list of chars.
	char value2 = 'a';
	std::list<char> char_list(n,value2 );

	// II: Manipulation of data.
	
	// There is no random access with a doubly-linked list.
	/* std::cout << copied_list[0] << std::endl; */
	// ------------------
	// A. Element access.
	// ------------------
	std::cout << "\nII Element access: " << std::endl;	
	std::cout << "===========================" << std::endl;	
	// 1. .front(): returns a reference to the first element in the list. 
	// 	We can return the first element in the list.
	int_list.front() = 20;
	std::cout << "\nFirst element: " << int_list.front() << std::endl;	
	// 2. .back(): returns a reference to the last element in the list.
	int_list.back() = -20;
	std::cout << "Last element: " << int_list.back() << std::endl;	
	

	// --------------------------
	// B. State of the container.
	// --------------------------
	std::cout << "\nIII State of the container: " << std::endl;	
	std::cout << "==============================" << std::endl;	
	// 1. .empty() returns true if size = 0, else returns false.
	std::cout << "\nempty_list.empty() : (true/false) " <<empty_list.empty() << std::endl;
	std::cout << "int_list.empty() : (true/false) " << int_list.empty() << std::endl;
	// 2. Returns the number of elements in the container.
	std::cout << "empty_list.size() : " <<empty_list.size() << std::endl;
	std::cout << "int_list.size() : " << int_list.size() << std::endl;
	// ----------------------------------
	// C. Changing data in the container.
	// ----------------------------------
	std::cout << "\nIV Manipulation of data: " << std::endl;	
	std::cout << "==============================" << std::endl;	
	// 1. push_front(): Adds in element in the begining.
	int_list.push_front(-10);
	// 2. push_back(): Adds in element at the end.
	int_list.push_back(10);
	std::cout << "\nAfter .push_back(10), .push_front(-10): first element, " 
	<< int_list.front() << " and last element, " << int_list.back() << std::endl;	
	// 3. pop_front(): removes an element from the front.	
	int_list.pop_front();
	// 4. pop_back(): removes an element from the back.	
	int_list.pop_back();
	// New output.
	std::cout << "\nAfter .pop_back, .pop_front(): first element, " 
	<< int_list.front() << " and last element, " << int_list.back() << std::endl;	
	
	// -------------------------
	// D. Additional operations.
	// -------------------------
	std::cout << "\nV Additional functionality: " << std::endl;	
	std::cout << "==============================" << std::endl;	
	// ** Note: For each loops make use of iterators in the background.
	// 	    For more information on iterators, see the iterator directory.
	std::cout << "\nList before operations: "<< std::endl;
	std::cout << "\nInt list: "<< std::endl;
	// This is an example of a for-each loop.
	for(int i : int_list){
		std::cout << i << std::endl;
	}
	// 2. Printing out char list
	std::cout << "\nChar list: "<< std::endl;
	for(char a: char_list){
		std::cout << a << std::endl;
	}	
	// 3. remove_if(): Removes all elements fullfilling the condition.
	std::cout << "\nUsing remove_if(): Function removes all elements that fulfill "
	<< "the condition. (conditions is to remove all the 12's)"<< std::endl;
	// Removing all the elements that are equal to 12.
	int_list.remove_if( is_12 );
	// See definition of pred below.
	std::cout << "\nList after operations: "<< std::endl;
	for(int i: int_list){
		std::cout << i << std::endl;
	}
	
	
	std::cout << "\n Char list after clear(): "<< std::endl;
	char_list.clear();
	// This will not print any elements because all the elements are removed
	// by .clear()
	for(char a: char_list){
		std::cout << a << std::endl;
	}
	
	std::cout << std::endl << "*** End of std::list demonstration ***"
	<< std::endl << std::endl;
	return 0;
}


// Used inside remove_if()
/* This is a trivial function, but it demonstrates how to use a predicate function inside
   remove_if() */
/* ***************************************************************************************
 * Function name: is_12()
 * Description: This function may only take in the data type that is in the container
 * 		and must return a boolean value. It is used inside remove_if().
 * 		The method is that any value passed as argument to this function
 * 		inside remove_if() that makes pred() evaluate true, will
 * 		be remove from the list.
 * Parameters: Same data type that is stored in the container.
 * Pre-conditions: This function must only accept the data that is in the container, and
 * 		   must return a boolean value.
 * Post-conditions: The element will be removed if it lets the functino evaluate true.
 * **************************************************************************************/
bool is_12(int val){
	// This will lead to the function remove_if() removing the specific data point
	// from the container.
	// This first statement is only used to see when the function gets called.
	//std::cout << "[is_12()]: called from within remove_if()."<< std::endl;
	if( val == 12){
		return true;
	}else{
		return false;
	}
}
