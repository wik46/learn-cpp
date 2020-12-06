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
	Point p1;
	std::cout << p1 << std::endl;
	{
		std::cout << "===" << std::endl;
		// This will call the default constructor of Point ten times.
		Point* ptr = new Point[10];
		// We have not defined a default destructor so the compiler provides
		// one for us.
		delete[] ptr; // We need to explicitly delete the instance of a Point.
		
		std::cout << "===" << std::endl;
	}


	Line l1(1); // This will create an array of 5 points.
	
	{
		std::cout << "----"<< std::endl;
		Line l2 = l1; // This will call the copy constructor.
		std::cout << "----" << std::endl;
	}
	{
		std::cout << "+++"<< std::endl;
		// Note that this will not construc an intance of a Line class.
		Line* line_ptr;
		std::cout << "+++"<< std::endl;
	}
	{
		std::cout << "///"<< std::endl;
		// Note that this will construct an intance of a Line class.
		// And our destructor we need to free the memory.
		Line* line_ptr2 = new Line(4); 
		delete line_ptr2;// We need to free the memory held by the instance but
				// the destructor will free the memory used by the member variables.
		std::cout << "///"<< std::endl;
	}	
	return 0;
}; 
