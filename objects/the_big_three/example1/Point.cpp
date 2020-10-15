/*
 * Filename: Point.cpp
 * Author: Wikus Jansen van Rensburg.
 * Date: October 11, 2020.
 * Description: This is a program that displays the usage of constructors.
 */
// This is the header file for my Point class.

#include "Point.h"
#include <iostream>

// Default constructor.	
Point::Point(): m_x{0}, m_y{0}, m_z{0}
{}
// Constructor 1
Point::Point(int x, int y, int z): m_x{x}, m_y{y}, m_z{z}
{}
// Accessor functions. "getters"
//
// Const member functions:
// A member function that is not const cannot be used when the object is const.
int Point::get_x() const { // This is how to make a member function const.
	return m_x;
}
int Point::get_y() const {
	return m_y;
}
int Point::get_z() const {
	return m_z;
}
// Mutator function. "setter"
void Point::set_point(int x, int y, int z)
{
	// This is an implicit const pointer pointing to the object.
	// You cannot change the address that a const pointer is pointing to,
	// but you can change the value at that address.
	this->m_x = x;
	this->m_y = y;
	this->m_z = z;
}
// This function prints the value of the point.
void Point::print_point() const{
	std::cout << "x: " << m_x << std::endl;
	std::cout << "y: " << m_y << std::endl;
	std::cout << "z: " << m_z << std::endl;
}
