/* ***************************************************************************************
 * Function name: big_three_part1.cpp
 * Author: Wikus Jansen van Rensburg.
 * Description: This is programs that were taken from GeeksforGeeks
 * 		to study inheritance of classes for a CS class during college.
 * Date: December 3, 2020
 * **************************************************************************************/

#include <iostream>

// =================================================
// Assignment operator overload and inheritance 
// =================================================

/*
	This program will desribe and illustrate what happens to the big three
	during inheritance relationships.
	Part 1: Will focus on the assignment operator overload.
	Part 2: Will focus on the copy constructor.
	Part 3: Will focus on the destructors.
	 
 */
// See function purpose below.
void print_d();

// Question 1: Function overriding (not using pointers or references.)
// Class 1.
class Base{
public:
	// Constructor
	Base(){
		std::cout << "[Base] default constructor"<< std::endl;
	}
	// The big three.
	
	// 1. Assignment operator overload.
	Base& operator=( const Base& b){
		/* Note that this is not the correct definition, and only used for
 			determining when it is called. */
		std::cout << "[Base] overloaded assignment operator."<< std::endl;
		return *this;	
	}
	// 2. Copy constructor.
	// 3. Destructor.
	~Base(){
		std::cout << "[Base] default destructor"<< std::endl;
	}
	
	// 1. Member function	
	void print(){
		std::cout << "[Base]: print() called" << std::endl;
	}
};
// Class 2, derived from Base.
class Derived_A: public Base{
public:
	

	// Constructor
	Derived_A(){
		// This class uses dynamic memory.
		std::cout << "[Derived_A] default constructor" << std::endl;
	}
	// NB! The assignment operator overload does not get inhereted.
	// 	Instead what happens is that the compiler creates a default
	// 	Derived& operator=(const Derived&); that calls the Base::operator=()
	// 	for you.
	//
	// You do not inherit a 'Derived& operator=(const Base&); '
	// See 'https://stackoverflow.com/questions/9161512/assignment-operator-inheritance'
	// 	for complete explanation.
	
	// Version 1: Assignment operator overload.
	Derived_A& operator=(const Derived_A& b){
		std::cout << "[Derived_A] Assignment operator: 'const Derived&' version."<< std::endl;
		std::cout << "** Note that the base assignment operator" <<
		" is not called anymore,\ntherefore ensure that all base members get"
		<<" copied correctly.**"<< std::endl;
	}
	
	// Version 2: Assignment operator overload.
	Derived_A& operator=(const Base& b){
		std::cout << "[Derived_A] Assignment operator: 'const Base&' version."<< std::endl;
	}
	// Destructor
	~Derived_A(){
		// This memory needs to be freed by the destructor.
		std::cout << "[Derived_A] default destructor"<< std::endl;
	}
	// Extra member funciton
	void print(){
		std::cout << "[Derived_A]: print() called" << std::endl;
	}	

};

int main(){
	// This functino prints the purpose of the program.
	print_d();
	std::cout << std::endl << std::endl;
	// -------------------------
	// Case 1: No problems here.
	// -------------------------
	std::cout << "Construction of Base:"<< std::endl;
	std::cout << "-----------------------"<< std::endl;
	{
		// Creating inside scope because I want to partition the example.
		Base b1;
		Base b2;
		// No calling the assignment operator for the base class.
		b1 = b2;
	}
	// -------------------------
	// Case 2: No problems here.
	// -------------------------
	
	std::cout << "-----------------------\n"<< std::endl;
	std::cout << "Construction of Derived_A:"<< std::endl;
	std::cout << "-----------------------"<< std::endl;
	{
		// Creating two derived instances.
		std::cout << std::endl;
		Derived_A d1;	
		std::cout << std::endl;
		Derived_A d2;	
		std::cout << std::endl;
		// Calling the assignment operator overload.
		d1 = d2;
		std::cout << std::endl;
	}




	// -----------------------------
	// Case 3: Just another example.
	// -----------------------------
	std::cout << "---------------------------\n"<< std::endl;
	std::cout << "Showcasing another example:"<< std::endl;
	std::cout << "---------------------------"<< std::endl;
	{
		// This is never applicable to my knowlegde.
		std::cout << std::endl;
		Base b1;
		std::cout << std::endl;
		Derived_A d1;
		std::cout << std::endl;
		// Calling the version 2 assignment operator.
		d1 = b1;
		std::cout << std::endl;
	}

	return 0;
}

/// This function only prints the description of the program.
void print_d(){
	std::cout << "\n--------------------------"<< std::endl;
	std::cout << "Program 1"<< std::endl;
	std::cout << "--------------------------"<< std::endl;
	std::cout << "This program show how the assignment operator acts with" <<
	" inherited classes.\nThe assignment operator does not get inherited. What happens" 
	<< " is that if you do not\ndefine one for the child, then the compiler will provide a default one\n"<<
	"for you. This default one will call the base assignement operator overload to handle\n" 
	<< "all the base class members, but a shallow copy will be performed if you don't "<< 
	" define\nan overloaded assignement operator for your child."<< std::endl;
	std::cout << "** Side note: friends of the base class are not friend of the child**"
	<< std::endl<< std::endl;
}
