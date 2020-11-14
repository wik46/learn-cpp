 /**************************************************
 *Program Filename: class_ex5.cpp
 *Author: Wikus
 *Date: 22 August 2020
 *Description: Learning how to use th create a log function to print types of errors
 *Input
 *Output
 *************************************************/



// The constructor serves two purposes.
// 1. Firstly it is use to create and instance of a class called an object.
// 2. The programmer can use it to instantiate its member variables.
// - Remeber that a member variable that is a class, this class will be created before the body of the
// 	outer class executes. The inner class member's constructor will be call first.

// Member initializer list.
// ========================
// You cannot assign value to const or reference members in the body of the constructor.
// You need to instantiate them.
//


#include <iostream>
#include <assert.h>

class A {
// A is going to be a member of B.
private:
	int m_integer;

public:
	A(int y = 7)
	: m_integer(y * 10) 
	{
		std::cout << "The constructor of A." << std::endl;
		std::cout << "The value of m_integer: " << m_integer << std::endl;
	}
	// The destructor of A
	~A(){
		std::cout << "The destructor of A." << std::endl;
	}
	// This class is used to return the private member of A.
	int GetValueA(){
		return m_integer;
	}
};

class B {
private:
	// A member of B is of type A.
	A m_a;	
	int m_b;
public:
	B(int k = 5)
	// The order in wich you initialize your members should correspond the the order in which you declare
	// 	your members.
	: m_a(k), m_b(k)
	{
		std::cout << "The constructor of B." << std::endl;
		std::cout << "The value of m_b: " << m_b << std::endl;
	}
	// The destructor of B
	~B(){
		std::cout << "The destructor of B." << std::endl;
	}
	// This function is to access the member in A.
	int  GetValueB(){
		return m_b;
	}
	// This is to access the member m_a.
	// I am returning the class m_a.
	A GetClassA(){
		return m_a;
	}

};

class Member_init_list{
private:
// The problem is that a const or reference must be instatiated.
// A constructor declares the member variables and sets the value of them in the next step.
// 	It does not instantiate the member.
	std::string str_1;
	std::string str_2;
	const char* char_star;
	B m_from_b;
public:
	Member_init_list(std::string user1 = "default1", std::string user2 = "default2", const char* user3 = "default3", int value = 10)
	: str_1(user1), str_2(user2), char_star(user3), m_from_b(value) 
	{
		std::cout << "The Constructor of Member_init_list. "  << std::endl;
		std::cout << "1. " << str_1 << "\n2. " << str_2 << "\n3. "<< char_star << 
		// Notice that the member in A is private, therfore I need GetValueA()
		// Then the member of type A is private inside class B. Therefore I need class B.
		"\n4. m_from_b:  " << m_from_b.GetValueB() << " and " << m_from_b.GetClassA().GetValueA() << std::endl;	
	}		

	// Why we need to instantiate member variables.
	//Member_init_list(){
	//	m_const = 10;
	//}
	// This code is the same as.
	// const in m_const; // invalid
	// m_const = 10;
	
	// Destructor of Member_init_list
	~Member_init_list(){
		std::cout << "Destructor of Member_init_list." << std::endl;
	}
};

int main(){
	// The constructor of A executes before B because B want to use A and therefore A must be
	// 	constructed first.
	//B b(25);

	// Example 2
	Member_init_list class_1("Hello", "How are you", "doing?", 10);
	return 0;
}

