/* ***************************************************************************************
 * Function name: quiz3.cpp
 * Author: Wikus Jansen van Rensburg.
 * Description: This is programs that were taken from GeeksforGeeks
 * 		to study inheritance of classes for a CS class during college.
 * Date: December 3, 2020
 * Learninf resource: GeeksforGeeks.
 * **************************************************************************************/

// ===================================================================
// All base class functions with the same name if defined inside Child
// ===================================================================

#include <iostream>

// See function definition below main().
void print_desc();

// Question 1: Function overriding (not using pointers or references.)
// Class 1.
class Base{
public: 
	// Function 1.
	void print(){
		std::cout << "Base::print() called "<< std::endl;
	}	
	// Function 2.
	void print(int x){
		std::cout << "Base::print( int ) called: " << x << std::endl;
	}
};
// Class 2, derived from Base.
class Derived: public Base{
public:
	// We only redefine print() and not print(int)
	/* But all the functions inside Base with the name print, will
	   be hidden and if we try to call one that is not defined inside
	   the child, it will lead to a compilation error. 
	*/
	// Function 1: Redefinition.
	void print(){
		std::cout << "Derived::print() called"<< std::endl;
	}
	// Function 2: We provide no definition. You cannot called print(int)
	// 		from a Derived object.
};

int main(){
	// This prints out the purpose of the program.
	print_desc();	
 	// Creating instances of Base and Derived to used during
 	// 	demonstration.
	Base b;
	Derived d;

	// We can call both function using a base object.
 	std::cout << "Functions called from a Base object." << std::endl;
	std::cout << " -------------------------- "<< std::endl;
	b.print();
	b.print( 10 ); // We have defined this inside Base
	std::cout << " -------------------------- "<< std::endl;
 	
	// We can only call print() from a Derived object.
	std::cout << "\n\nFunctions called from a Derived object." << std::endl;
	std::cout << " -------------------------- "<< std::endl;
	d.print(); // Defined inside Derived so we can use it again.
/*	d.print(10 );*/ // This will lead to a compile error because all versions
			// of print() are hidden and we can only use them
			// if they are defined in the Derived class again.
	std::cout << " -------------------------- "<< std::endl;
	
	return 0;
}


/* ***************************************************************************************
 * Function name: print_desc()
 * Description: This function is used to print the purpose and the
 * 		description of quiz3.cpp
 * Parameters: -
 * Pre-conditions: -
 * Post-conditions: -
 * **************************************************************************************/
void print_desc(){	
	std::cout << " Will this program compile? " << std::endl;
	std::cout << " -------------------------- "<< std::endl;
	std::cout << "We define 2 classes, a base class an a class that derives from base\n"
	<< " Base has two function called print() and print(int) \n\n"

	<< "We only define print() inside the derived class, not print(int).\n"
	<< "** Because we redefine a function in the child, all the functions with the same" 
	<< "\n 	inside the parent will be hidden and we need to define them in child to use them"
	<< "\n"<< std::endl; 
	
}
