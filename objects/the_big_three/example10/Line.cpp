/*
 * Filename: Line.cpp
 * Author: Wikus
 * Date: October 9, 2020.
 * Description: This is the implementation file for my Line object.
 *
 * */

#include "Line.h"
#include "Point.h"

#include <cassert>
#include <iostream>

// The default constructor.
Line::Line():m_num_points{0}, m_set{NULL} {
	std::cout << "A line was constructed." << std::endl;
	std::cout << "Your line is the empty set." << std::endl;
	std::cout << "You need to create memory for you array to be able to use the line.\n";
}
	// The constructor that initializes the two points of the line.
Line::Line(int num_points): m_num_points{num_points}, m_set{NULL}
{
	assert(m_num_points > 0);
	m_set = new Point[m_num_points];
}

// It is used in my copy constructor and assignment overloading.
// This function will do a deep copy.
void Line::deep_copy(const Line& old_object){
	// First determine if the pointer contains data.
	// (That is first determine if m_set was initialized.)
	if(m_set != NULL){
		delete [] m_set;
	}
	// Now we can set the size of dynamic memory for the variable.
	// m_num_points is not a pointer so we can do a shallow copy.
	m_num_points = old_object.m_num_points;
	assert(m_num_points > 0);
	if(old_object.m_set != NULL){
		// createing space for memory.
		m_set = new Point[m_num_points];
		// Saving the data.
		for(int i = 0; i < m_num_points; i++){
			m_set[i] = old_object.m_set[i];
		}
		
	}else{
		std::cout << "problem" << std::endl;
		m_set = NULL;
	}	
	
}
	
// #1 of the Big Three: 
Line::~Line(){
	// The program will abbort if the condition returns false.
	if(m_set != NULL){
		delete[] m_set;
	}
}
// #2 of the big three.
// The copy constructor.
Line::Line(const Line& old_line){
	deep_copy(old_line);	
}

// #3 of the Big Three: "If you need one you need all of them."
// This is assignment operator overloading.

// Three differences between th copy constructor and assignment operator overloading.
// 1. We added the self-check assignment.
// 2. We return *this so that we can chain the assignment operator.
// 3. 

// If you dont do this the default assignments operator will shallow copy
// all your members.
// This implicit object is the one receiving the data and the one that has access to all
// 	member variables. The this pointer points to the imlpicit object and no the
// 	one passed as an argument to the function.
Line& Line::operator= (const Line& old_line){

	// We will do the deep copy if the it was not a self-assignment.
	// A self assignmnet is something like: "same_instance = same_instance"
	if(this != &old_line){
		deep_copy(old_line);
	}
	// Remeber with assignment operator overloading you need
	// to return the objet for chaining.
	return *this;
}
// This gives me access to a point in the line.

Point* Line::get_point(unsigned int index){
	assert(m_set != NULL);
	return &m_set[index];
}

// This is static variable for the Line class.
// We need to declare it inside the classe definition, but because it can be used before
// 	any instance of the class is created we also need to define it outside of the class.
// Always put your static member variables in the implementation file and not in the header file.
// Because multiple inclusions of the header file will lead to a duplicate definition error.
// This is a private static member variable.
int Line::count{0};


// Static member function.
// This is a static member function. It can only operate on static member variables.
// It is used so that we don't have to initialize and instance of a class before
// having access to a private static member variable.

// Note that we don't use static here.
int Line::get_count(){
	return Line::count;
}
// This is a mutator function for the count variable.
void Line::set_count(int input){
	Line::count = input;
}
// This is a function that prints the two points of the line.
// Note that it is a totally constant function. It cannot change the value of
// 	member variables.
/*
void Line::print() const{
	std::cout << "Point p1." << std::endl;
	std::cout << "x: " << m_p1.get_x() << std::endl;
	std::cout << "y: " << m_p1.get_y() << std::endl;
	std::cout << "z: " << m_p1.get_z() << std::endl;
	std::cout << "Point p2." << std::endl;
	std::cout << "x: " << m_p2.get_x() << std::endl;
	std::cout << "y: " << m_p2.get_y() << std::endl;
	std::cout << "z: " << m_p2.get_z() << std::endl;
	std::cout << std::endl;
}
*/
