 /**************************************************
 *Program Filename: class_ex6_timing.cpp
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

// This program is a demonstration of the timing of the constructor and the destructor.
//

class Timer{
private:
	int m_timer;

public:
	// Constructor
	Timer(int user_in = 1)
	: m_timer(user_in)
	{
		std::cout << "Constructor of Timer "<< m_timer << " called." << std::endl;
	}
	// Destructor. This will be called when the object goes out of scope or if the object
	// 	was heap allocated and explicitly deleted using the new keyword.
	~Timer(){
		std::cout << "Destructor of Timer " << m_timer << " called." << std::endl;

	}
	// Print info to show the timing in main clearly.
	void print(){
		std::cout << "Hello I am print() from the " << m_timer << " object." << std::endl;
	}

};

int main(){

	Timer object1(1);
	// This instance of Timer was created on the heap.
	Timer*  object2 = new Timer(2);
	
	object1.print();
	// Remember object2 is a pointer.
	object2->print();
	// Note that object2's memory is freed before object1 goes out of scope.
	// The destructor of object2 will execute before object2.
	delete object2;

	return 0;
}
