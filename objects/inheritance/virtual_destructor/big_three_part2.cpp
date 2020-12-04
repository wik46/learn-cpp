/* ***************************************************************************************
 * Function name: big_three_part2.cpp
 * Author: Wikus Jansen van Rensburg.
 * Description: This is programs that were taken from GeeksforGeeks
 * 		to study inheritance of classes for a CS class during college.
 * Date: December 3, 2020
 * **************************************************************************************/

#include <iostream>

// ===================================================
// Why you need virtual destructors: Part II: Solution
// ===================================================

/*
	The problem is demonstrated inside the big_three_part1.cpp
	file. 

	The solution is to declare the base constructor virtual.
	Unlike other member functions that get overriden if you declare
	their base version virtual, the destructor of base will
	still get called. The only difference is that all the children's
	destructors will also get called.

	** Side note: Remember that a virtual destructor always
			needs a function body. Otherwise you will
			get a linking error.
 
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
	virtual ~Base(){
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
	// ----------------------------
	// Case 3: Problem here solved.
	// -----------------------------
	std::cout << "-----------------------\n"<< std::endl;
	std::cout << "Problem Solved with virtual destructor:"<< std::endl;
	std::cout << "---------------------------------------------------------"<< std::endl;
	// The problem is that the ~Derived_A constructor will not be called.
	// We nee to call it because the Derived_A constructor allocated
	// 	dynamic memory and the destructor needs to delete it.
	// Solution: Declare the parent class destructor base so that both
	// 	the parent and the child destructor get's called.
	Base* polymorph = new Derived_A(); 
	delete polymorph; /* Because the destructor is virtual, both the 
				base class destructor and the child class. */
	std::cout << "** Notice that the Derived_A destructor "<<
	"was called becuase it is virtual ."<< std::endl;
	std::cout << "-----------------------\n"<< std::endl;


	return 0;
}
