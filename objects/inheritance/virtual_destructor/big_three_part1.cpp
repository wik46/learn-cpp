/* ***************************************************************************************
 * Function name: big_three_part1.cpp
 * Author: Wikus Jansen van Rensburg.
 * Description: This is programs that were taken from GeeksforGeeks
 * 		to study inheritance of classes for a CS class during college.
 * Date: December 3, 2020
 * **************************************************************************************/

#include <iostream>

// =================================================
// Why you need virtual destructors: Part I: Problem
// =================================================

/*
 	This is the program that demonstrates the problem with storing
	child pointers inside base pointers. C++ will think that the object
	is of type base and only call the base destructor. We need it 
	to call the child constructor as well, because our child
	allocated dynamic memory.

	Solution to this problem is in big_three_part2.cpp
 
 */
// Question 1: Function overriding (not using pointers or references.)
// Class 1.
class Base{
public:
	// Constructor
	Base(){
		std::cout << "[Base] default constructor"<< std::endl;
	}
	// Destructor
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
	// Member to store dynamic memory.
	int* m_array;
public:
	// Constructor
	Derived_A(){
		// This class uses dynamic memory.
		m_array = new int[10];
		std::cout << "[Derived_A] default constructor"<< std::endl;
	}
	// Destructor
	~Derived_A(){
		// This memory needs to be freed by the destructor.
		delete[] m_array;
		std::cout << "[Derived_A] default destructor"<< std::endl;
	}
	void print(){
		std::cout << "[Derived_A]: print() called" << std::endl;
	}	

};

int main(){
	// -------------------------
	// Case 1: No problems here.
	// -------------------------
	std::cout << "Construction of Base:"<< std::endl;
	std::cout << "-----------------------"<< std::endl;
	Base* base = new Base();
	delete base;
	// -------------------------
	// Case 2: No problems here.
	// -------------------------
	std::cout << "-----------------------\n"<< std::endl;
	std::cout << "Construction of Derived_A:"<< std::endl;
	std::cout << "-----------------------"<< std::endl;
	Derived_A* derived = new Derived_A();
	delete derived;
	// -------------------------
	// Case 3: Problem here.
	// -------------------------
	std::cout << "-----------------------\n"<< std::endl;
	std::cout << "Problem is when storing a Derive_A object inside a Base.:"<< std::endl;
	std::cout << "---------------------------------------------------------"<< std::endl;
	// The problem is that the ~Derived_A constructor will not be called.
	// We nee to call it because the Derived_A constructor allocated
	// 	dynamic memory and the destructor needs to delete it.
	Base* polymorph = new Derived_A(); 
	delete polymorph; /* Because the destructor is not virtual, the only the 
				base class destructor will get called. */
	std::cout << "** Notice that the Derived_A destructor was not called."<< std::endl;
	std::cout << "-----------------------\n"<< std::endl;

/*
	// 1. When I call the print function from Derived_A?
	std::cout << "Question 1: -----------"<< std::endl;
	std::cout << "-----------------------\n"<< std::endl;
	// 2. When I call the print function from Derived_B?
	std::cout << "Question 2: -----------"<< std::endl;
	d_b.print(); // We overide the functionality of print.
	std::cout << "-----------------------\n"<< std::endl;
	// 3. When I call the print function from Final?
	std::cout << "Question 3: -----------"<< std::endl;
	f.print(); // The last overiddent definition of print was inside Derived_B
	std::cout << "-----------------------\n"<< std::endl;
*/	


	return 0;
}
