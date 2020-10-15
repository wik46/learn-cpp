/*
 * Filename: Point.h
 * Author: Wikus Jansen van Rensburg.
 * Date: October 11, 2020.
 * Description: This is a program that displays the usage of constructors.
 */

#ifndef POINT_H
#define POINT_H

// Headerfile for my Point class.
// This is a point in three dimensional space.

class Point{
	int m_x;
	int m_y;
	int m_z;
public:
	// Default constructor.	
	Point();
	// Constructor 1
	Point(int x, int y, int z);
	// Accessor function. "getters"
	// It is good practise to make all member functions that do no change 
	// member variables value constant.
	int get_x()const ; 
	int get_y()const ;
	int get_z()const ;
	// Mutator function. "setter"
	void set_point(int, int, int);
	// This function prints the values of the point.
	void print_point() const;
};

#endif
