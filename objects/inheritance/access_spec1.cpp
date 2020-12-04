/* **************************************************************************************
 * Filename: access_spec1.cpp
 * Author: Wikus
 * Date: October 21, 2020
 * Description: This is used to study the inheritance chains
 * 		between the various parent and chil classes.
 * **************************************************************************************/
#include <iostream>

class A{
public:
	// The Parent class will be constructed first.
	A(int a)
	{
		std::cout << "A constructed: " << a << std::endl;
	}
	// The Parent class will be destructed last.
	~A(){
		std::cout << "A is desctructed." << std::endl;
	}

};

// B is a child of A but a parent of B.
class B: public A{
public:
	B(int a, char b)
	:A{a}
	{
		std::cout << "B is constructed: " << b << std::endl;
	}
	//
	~B(){
		std::cout << "B is destructed." << std::endl;
	}

};

class C: public B{
public:
	C(int a, char b, float c)
	// C cannot call the constructor of A. It can only call his Parent.
	: B{a, b}
	{
		std::cout << "C is constructed: " << c << std::endl;
	}
	// Ths destructor of C.
	~C(){
		std::cout << "C is destruted: " << std::endl;
	}

};
// See description of function below main.
void print_info();

int main(){
	// This print statements is used to describe to the user what the basic concepts of inheritance.
	print_info();

	std::cout << "** Start of ouput: **\n" << std::endl;
	C c{1, 'R', 23.3};
	std::cout << "\n** End of ouput: **\n" << std::endl;
	return 0;
}
/* ***************************************************************************************
 * Function name: print_info()
 * Description: This function is used to clean up main() and to inform
 * 		the user on the contruction/ destruction timing of 
 * 		inheritance relationships.
 * Parameters: -
 * Pre-conditions: -
 * Post-conditions: -
 * **************************************************************************************/
void print_info(){
	
	std::cout << "\n--------------------------------------" << std::endl;
	std::cout << "Things to notice with this ouptut:"<< std::endl;
	std::cout << "--------------------------------------\n" << std::endl;
	std::cout << "1.) A is parent of B. B is parent of C."<< std::endl;
	std::cout << "  * Most child contructed last and destructed first." << std::endl;
	std::cout << "  * Most parent contructed first and destructed larst." << std::endl;
	std::cout << "This make sense becuase you might need members from the parent to construct the child.\n" << std::endl;
	std::cout << "This make sense becuase you might need members from the parent till the end.\n" << std::endl;
	std::cout << "When the child was defined, it knew about members inside parent, but when parent is created\n"<< 
	"it does not necessarily had its children in mind."<< std::endl;
}

