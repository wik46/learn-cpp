// Filename: chains.cpp
// Author: Wikus
// Date: October 21, 2020
// Description: This is used to study the inheritance chains
// 		between the various parent and chil classes.

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

int main(){
	C c{1, 'R', 23.3};
	return 0;
}
