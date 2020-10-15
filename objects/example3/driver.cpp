/*
 * Filename: driver.cpp
 * Author: Wikus
 * Date: October 11, 2020
 * Description: The driver file for my program that implements a point and a line class.
 * 		The purpose of the program is to study how constructors work.
 */

#include "Line.h"
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

	Line l1(1,1,1,1,2,2);
	Line l2, l3, l4;
	l1.print();
	std::cout << "Set the value of the static variable count: ";
	int input;
	std::cin >> input;
	Line::set_count(input);
	std::cout << "It was stored inside l2.count and now I print l4.count." << std::endl;
	std::cout << "Remember that a static function has no this* pointer." <<
		"It makes sense because a this pointer is associated with a specific object."
		<< "Where a static function is not." << std::endl;
	// count is a static variable. Therefore all the instances of Line will see
	// 	it as the same variable.
	std::cout << Line::get_count() << std::endl;
	return 0;
}; 
