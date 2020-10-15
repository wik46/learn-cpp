/*
 * Filename: driver.cpp
 * Author: Wikus
 * Date: October 11, 2020
 * Description: The driver file for my program that implements a point and a line class.
 * 		The purpose of the program is to study how constructors work.
 */

#include "Point.h"
#include <iostream>

int main(){
	// Called using the default constructor.
	const Point p1;
	// Called using constructor 1.
	Point p2(-3,4,-2);
	// Point p1 is a const Point. Therefore I cannot change its member variables using a setter.
	// p1.set_point(1,1,1);
	// Using the member function print_point.
	p1.print_point();
	p2.print_point();

	return 0;
}; 
