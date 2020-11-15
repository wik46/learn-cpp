// Filename: friends.cpp
// Author: Wikus.
// Date: October 30, 2020.
// Description: This will be a file to store all the friend functions
// 		used by the point class. The main purpose of this file
// 		is to practise using friend functions.
//
#include "friends.h"
#include "Point.h"
#include <iostream>

/*
 * Function namme: operator<<()
 * Description: This is a friend function. It has access to the private
 * 		members of the Point instance that we pass into the function.
 * */
std::ostream& operator<<(std::ostream& stream_out, const Point& p){
	stream_out << "From the overloaded operator<<():"<< std::endl;
	stream_out << "x: " << p.m_x << std::endl;
	stream_out << "y: " << p.m_y << std::endl;
	stream_out << "z: " << p.m_z << std::endl;
	// Always remember to return the std::ostream&
	return stream_out;
	
}
