/*
 * Filename: constructor_and_destructor_timing_ex1.cpp
 * Author: Wikus Jansen van Rensburg
 * Date: October 11, 2020
 * Description: This program is used to study when constructors and
 * 		destructors are called.
 */

// ## You need to compile this program with the flag -std=c++11

#include <iostream>
// This class uses a constructor to initialize its member variables.
class Initializer_list{
	int m_member1;
	std::string m_member2;
	std::string* m_member3;
public:
	// Default constructor.
	Initializer_list()
	:m_member1{0}, m_member2{"default"}, m_member3{NULL}
	{
		std::cout << "Class Initializer_list constructor called." << std::endl;		
	}
	// Destructor.
	~Initializer_list(){
		std::cout << "Class Initializer_list destructor called." << std::endl;			
		if(m_member3 != NULL){
			delete[] m_member3;
		}
	}
	// This creates an array to store strings.
	void create_array(int size){
		m_member3 = new std::string[size];
	}
	// Prints the members.
	void print_members(){
		std::cout << "m_member1: " << m_member1 << std::endl;
		std::cout << "m_member2: " << m_member2 << std::endl;
	}

};

// This class uses non-static member initialization.
class Non_static{
	int m_member1{0};
	std::string m_member2{"default"};
	std::string* m_member3{NULL};
public:
	Non_static()
	// This will get precedencs over the non-static initialization.
	//:m_member1{5}, m_member2{"set by constructor"}
	{
		std::cout << "Class Non_static constructor called." << std::endl;
	}
	// Destructor.
	~Non_static(){
		std::cout << "Class Non_static destructor called." << std::endl;			
		if(m_member3 != NULL){
			delete[] m_member3;
		}
	}
	// This creates an array to store strings.
	void create_array(int size){
		m_member3 = new std::string[size];
	}
	// Prints the members.
	void print_members(){
		std::cout << "m_member1: " << m_member1 << std::endl;
		std::cout << "m_member2: " << m_member2 << std::endl;
	}
};

int main(){
	// Examples shocasting constructore and destructor timing.
	{
		// Example1
		std::cout << "Example 1: Note that non1 is created after list1. Therefore is higher up on the stack"
			<< " and will be destroyed first." << std::endl;
		Initializer_list list1;
		Non_static non1;
	}
		std::cout << std::endl << std::endl;

	{
		// Example2
		std::cout << "Example 2: Now list2 is declared in an inner scope and will first be destroyed before"
		<< " the object non2 is declared."  << std::endl;
		{
			Initializer_list list2;
		}
			Non_static non2;
		
		
	}


	return 0;
}
