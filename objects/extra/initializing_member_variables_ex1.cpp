/*
 * Filename: initializing_member_variables_ex1.cpp
 * Author: Wikus
 * Date: October 7, 2020
 * Description: This is a demonstration between constructor member initialized lists 
 * 		and non-static member initializing.
 *
 * */

#include <iostream>

// This class uses a constructor to initialize its member variables.
class Initializer_list{
	int m_member1;
	std::string m_member2;
public:
	Initializer_list()
	:m_member1{0}, m_member2{"default"}
	{
		std::cout << "Class Initializer_list constructor called." << std::endl;		
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
public:
	Non_static()
	// This will get precedencs over the non-static initialization.
	//:m_member1{5}, m_member2{"set by constructor"}
	{
		std::cout << "Class Non_static constructor called." << std::endl;
	}
	// Prints the members.
	void print_members(){
		std::cout << "m_member1: " << m_member1 << std::endl;
		std::cout << "m_member2: " << m_member2 << std::endl;
	}
};

int main(){

	Initializer_list list1;
	Non_static non1;

	list1.print_members();
	non1.print_members();
	return 0;
}
