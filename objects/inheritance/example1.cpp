// Author: Wikus
// Learning Resource: Learn cpp 11.4
// Date: October 19, 2020.
// This file is used to study the role of the
// constructor in initializing derived classes.

#include <iostream>

// Note that this is an example of public inheritance.
class Base{
public:
	// This is to show that members can only be initialized in their own class.
	int m_base;	

	// The default constructor.
	Base(): m_base(0){
		std::cout << "Base default constructor called."<< std::endl;
	}
	// I will explicitly call this constructor from my derived.
	Base(const char* name_of_con){
		std::cout << "The " << name_of_con << " constructor was called."<< std::endl;
	}
};

class Derived1: public Base{
public:
	// Member variables.
	int m_derived;
	
	// Default constructor.
	Derived1(): Base("Explicit"),m_derived(7) /*, m_base(2)*/{ // This will be an error.
				
		std::cout << "Derived default constructor called." << std::endl;
	}
};

int main(){
	Derived1 child;
	return 0;
}
