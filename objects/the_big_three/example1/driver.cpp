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
	Line l1(5);
	
	Point* p1 = l1.get_point(3);
	p1->set_point(1,2,3);
	p1->print_point();
	// This should be the point (1,2,3) because get_point returns a reference to a point.
	l1.get_point(3)->print_point();
	 
	Line l2;
	l2 = l1;
	l2.get_point(3)->print_point();
	
	return 0;
}; 
