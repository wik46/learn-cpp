/*
 * Filename: Line.cpp
 * Author: Wikus
 * Date: October 9, 2020.
 * Description: This is the implementation file for my Line object.
 *
 * */

#include "Line.h"
#include "Point.h"

#include <iostream>

// The default constructor.
Line::Line(){
	std::cout << "A line was constructed." << std::endl;
}
	// The constructor that initializes the two points of the line.
Line::Line(int x_0, int y_0, int z_0,int x_1, int y_1, int z_1){
	m_p1.set_point(x_0, y_0, z_0);
	m_p2.set_point(x_1, y_1, z_1);
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

