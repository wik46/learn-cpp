/* ***************************************************************************************
 * Function name: big_three_part2_1.cpp
 * Author: Wikus Jansen van Rensburg.
 * Description: This is programs that were taken from GeeksforGeeks
 * 		to study inheritance of classes for a CS class during college.
 * Date: December 3, 2020
 * **************************************************************************************/

#include <iostream>

// =================================================
// Copy constructor and inheritance: Part 2.1 
// =================================================

// Part 2.1: No copy constructor inside the derived class.

/* COPY CONSTRUCTORS DO NOT GET INHERITED.
 	The base copy constructor takes care of the base portion
	and the child gets a compiler/default provided copy	
	constructor that does shallow/ memberwize copying if
	no one is provided.
*/

/*
	This program will desribe and illustrate what happens to the big three
	during inheritance relationships.
	Part 1: Will focus on the assignment operator overload.
	Part 2: Will focus on the copy constructor.
	Part 3: Will focus on the destructors.
	 
 */
// See function purpose below main().
void print_d();

// Question 1: Function overriding (not using pointers or references.)
// Class 1.
class Base{
	// This will tell me the ID of the member.
	const char* id;
public:
	// Accessor.
	const char* get_id(){ return id;}
	// Constructor
	Base(): id{"BASE_MEMBER"}
	{	
		std::cout << "[Base] default constructor"<< std::endl;
	}
	// The big three.
	
	// 1. Assignment operator overload.
	// 2. Copy constructor.
	Base(const Base& b){
		std::cout << "[Base] Copy constructor."<< std::endl;

	}
	// 3. Destructor.
	~Base(){
		std::cout << "[Base] default destructor"<< std::endl;
	}
	
	// 1. Member function	
	void print(){
		std::cout << "[Base]: print() called and id is " << id 
		<< std::endl;
	}
};

// Class 2, derived from Base.
class Derived_A: public Base{
	// This is an additional member not inside the base class.
	const char* extra;
public:
	// Accessor.
	const char* get_extra(){ return extra;}

	// Constructor
	Derived_A(): extra{"DERIVED_A_EXTRA"}
	{
		// This class uses dynamic memory.
		std::cout << "[Derived_A] default constructor" << std::endl;
	}
	// The copy constructor does not get inherited.
	// Think about it, the parent does not know
	// 	what members are inside the child classes that derive from	
	// 	it. Therefore what happens is that the base copyconstructor
	// 	takes care of the base portion and the compiler provides
	// 	us with a default one for the rest of the members
	// 	inside the parent. (Memberwise/ shallow copy.)

	
	// The big three.
	
	// Version 1: Assignment operator overload.
	
	// Destructor
	~Derived_A(){
		// This memory needs to be freed by the destructor.
		std::cout << "[Derived_A] default destructor"<< std::endl;
	}
	// Extra member funciton
	void print(){
		std::cout << "[Derived_A]: print() called and id: " << get_id() 
		<< " and extra: " << get_extra() << std::endl;
	}	

};

// =======================================================================================
// =======================================================================================
// =======================================================================================

int main(){
	// This function prints out the purpose of the program.
	print_d();
	
	// -------------------------
	// Case 1: No problems here.
	// -------------------------
	std::cout << "Construction of Base:"<< std::endl;
	std::cout << "-----------------------"<< std::endl;
	{
		// Creating inside scope because I want to partition the example.
		Base b1;
		// No calling the Copy constructor for the base class.
		std::cout << std::endl;
		Base b2 = b1;
		std::cout << std::endl;
	}
	// -------------------------
	// Case 2: No problems here.
	// -------------------------
	
	std::cout << "--------------------------\n"<< std::endl;
	std::cout << "Construction of Derived_A:"<< std::endl;
	std::cout << "--------------------------"<< std::endl;
	{
		// Creating two derived instances.
		std::cout << std::endl;
		Derived_A d1;	
		std::cout << std::endl;
		// Calling the copy constructor.
		// 	Note that there is no one defined for the child class
		// 	What will happen is the Base portion of the class
		// 	will use the base copy constructor, and the rest of the 
		// 	members defined inside the derived class will get copied
		// 	using the default copy constructor provided from the parent.
		Derived_A d2 = d1;	
		std::cout << std::endl;
		std::cout << std::endl;
	}
	return 0;
}


/// This function only prints the description of the program.
void print_d(){
	std::cout << "\n--------------------------"<< std::endl;
	std::cout << "Program 2_1"<< std::endl;
	std::cout << "--------------------------"<< std::endl;
	std::cout << "This program shows that the copy constructor "
	<< "is not inherted from the parent to the child.\nAll that happens "
	<< "is that the copy constructor will copy the base part of the child class\n"
	<< "and then the compiler will provide a default copy constructor for the child\n"
	<< "since no copy constructor is defined for the child." << std::endl;
	std::cout << "** In 2_2 we define a copy constructor "
	<<"for the child. **\n" << std::endl;
}
