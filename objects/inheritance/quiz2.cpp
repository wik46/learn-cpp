/* ***************************************************************************************
 * Function name: quiz2.cpp
 * Author: Wikus Jansen van Rensburg.
 * Description: This is programs that were taken from GeeksforGeeks
 * 		to study inheritance of classes for a CS class during college.
 * Date: December 3, 2020
 * **************************************************************************************/

#include <iostream>

// See function definition below main().
void print_desc();

// Question 1: Function overriding (not using pointers or references.)
// Class 1.
class Base{
	// Emtty class
};
// Class 2, derived from Base.
class Derived: public Base{
	// Empty class
};

int main(){
	// This is to print the purpose of the quiz2.cpp file
	print_desc();

	// Will this program compile?
	/* -------------------------- */
	// This program will compile for assignment 1, but not
	// 	if you uncommnet assignement 2.

	// Assignment 1: You can store a child pointer as a parent pointer.
	// ** Becuase the object that the parent pointer is pointing
	// 	it a child of the parent, it is gaurenteed to have all the functionality
	// 	that the parent has. 
	Base* base_ptr = new Derived;
	delete base_ptr;
	// Assignment 2: You cannot store a parent pointer inside a child pointer.
	// ** This will lead to a compilation error if it is uncommented.
	// 	The reason being that there there is a possibilty
	// 	of extra members defined inside the child that the
	// 	parent does not know about. Therefore we need to prevent the
	// 	occurance of for example calling a size member that is newly defined inside
	// 	the child, but not inside the parent.
	/* 
 
 	Child* child_ptr = new Base;
 
	*/
	return 0;
}


/* ***************************************************************************************
 * Function name: print_desc()
 * Description: This function is used to print the purpose and the
 * 		description of quiz2.cpp
 * Parameters: -
 * Pre-conditions: -
 * Post-conditions: -
 * **************************************************************************************/
void print_desc(){	
	std::cout << " Will this program compile? " << std::endl;
	std::cout << " -------------------------- "<< std::endl;
	std::cout << "This program will compile for assignment 1, but not\n"
	<< " 	if you uncommnet assignement 2. \n\n"

	<< "Assignment 1: You can store a child pointer as a parent pointer.\n"
	<< "** Becuase the object that the parent pointer is pointing" 
	<< "\n 	it a child of the parent, it is gaurenteed to have all the functionality"
	<< "\n 	that the parent has." << std::endl; 
	std::cout << 
	   " Assignment 2: You cannot store a parent pointer inside a child pointer.\n"
	<< " ** This will lead to a compilation error if it is uncommented.\n"
	<< " 	The reason being that there there is a possibilty\n"
	<< " 	of extra members defined inside the child that the\n"
	<< " 	parent does not know about. Therefore we need to prevent the\n"
	<< " 	occurance of for example calling a size member that is newly defined inside\n"
	<< " 	the child, but not inside the parent. " << std::endl;
}
