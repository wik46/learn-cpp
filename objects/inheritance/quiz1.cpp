/* ***************************************************************************************
 * Function name: quiz1.cpp
 * Author: Wikus Jansen van Rensburg.
 * Description: This is programs that were taken from GeeksforGeeks
 * 		to study inheritance of classes for a CS class during college.
 * Date: December 3, 2020
 * **************************************************************************************/

#include <iostream>

// Question 1: Function overriding (not using pointers or references.)
// Class 1.
class Base{
public:	
	void print(){
		std::cout << "[Base]: print() called" << std::endl;
	}
};
// Class 2, derived from Base.
class Derived_A: public Base{
public:
	void print(){
		std::cout << "[Derived_A]: print() called" << std::endl;
	}	

};
// Class 3, derived from Base.
class Derived_B: public Derived_A{
public:
	void print(){
		std::cout << "[Derived_B]: print() called" << std::endl;
	}	

};
// Class 2, derived from Base.
class Final: public Derived_B{
public:
	// Empty class.
};


int main(){
	// Predict the ouput.
	Base b;
	Derived_A d_a;
	Derived_B d_b;
	Final f;	

	// 1. When I call the print function from Derived_A?
	std::cout << "Question 1: -----------"<< std::endl;
	b.print(); // As expected.
	std::cout << "-----------------------\n"<< std::endl;
	// 2. When I call the print function from Derived_B?
	std::cout << "Question 2: -----------"<< std::endl;
	d_b.print(); // We overide the functionality of print.
	std::cout << "-----------------------\n"<< std::endl;
	// 3. When I call the print function from Final?
	std::cout << "Question 3: -----------"<< std::endl;
	f.print(); // The last overiddent definition of print was inside Derived_B
	std::cout << "-----------------------\n"<< std::endl;
	


	return 0;
}
