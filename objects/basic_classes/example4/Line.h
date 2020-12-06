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
#include <cassert>
// 
// A line is represented by two point.
//

class Line{
	Point m_p1;
	Point m_p2;
	static int count;	
	// This is an array of points.
	Point* points_ar;
	int n_points;

public:
	// The default constructor.
	Line();
	// The constructor that initializes the two points of the line.
	Line(int, int, int, int, int, int);
	Line(int);

	// The destructor.
	~Line();
	// The copy constructor. (Doing deep copy)
	// We can assume that the new instance of a Line's member points_ar is NULL.
	Line(const Line&);
	// The overloaded assignments operator.
	Line& operator=(const Line& r_instance);

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
