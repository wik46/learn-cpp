/*
 * Filename: Line.h
 * Author: Wikus
 * Date: October 9, 2020
 * Description: This is the headerfile for the Line class. The goal of the 
 * 		program is to study the 'const' and 'static' keywoard in c++.
 * */

#ifndef LINE_H
#define LINE_H

#include "Point.h"
#include <iostream>

// 
// A line is represented by two point.
//

class Line{
	unsigned int m_num_points;
	Point* m_set;
	static int count;	
public:
	// The default constructor.
	Line();
	// 2nd constructor.
	Line(int);
	// #1. The Big Three: Destructor.
	~Line();
	// This is used with the copy constructor and assignment operator overloaing.
	void deep_copy(const Line&);
	// #2. The Big Three: Copy Constructor.
	Line(const Line&);
	// #3. The Big Three: Assignment Operator Overloading.
	// This is an assignments operator overloading.
	// You need to accept a reference to the object and return a reference to the object.
	// This is created so that you do not shallow copy.
	Line& operator= (const Line&);
	// This function gives me access to a point.
	// You enter the index of the point on the set of points.
	// I want to change the point.
	Point* get_point(unsigned int index);

	// This is a function that prints the two points of the line.
	// Note that it is a totally constant function. It cannot change the value of
	// 	member variables.
	void print() const;
	// This function gives me access to the static variable count.
	static int get_count();	
	// Mutator for count.
	static void set_count(int);
};

#endif
