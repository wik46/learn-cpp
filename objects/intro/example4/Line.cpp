/*
 * Filename: Line.cpp
 * Author: Wikus
 * Date: October 9, 2020.
 * Description: This is the implementation file for my Line object.
 *
 * */

#include "Line.h"
#include "Point.h"

#include <cassert>
#include <iostream>

// The default constructor.
Line::Line(): m_p1(0,0,0), m_p2(0,0,0), points_ar(NULL), n_points(0)
{
	std::cout << "A line was constructed." << std::endl;
	std::cout << "All member variables are initialized to 0 or NULL." << std::endl;
}
	// The constructor that initializes the two points of the line.
Line::Line(int x_0, int y_0, int z_0,int x_1, int y_1, int z_1){
	m_p1.set_point(x_0, y_0, z_0);
	m_p2.set_point(x_1, y_1, z_1);
	std::cout << "Line was constructed with two end points." << std::endl;
}
// This constructor will create an array of points of the given size.
Line::Line(int n = 0): m_p1(0,0,0), m_p2(0,0,0), points_ar(NULL), n_points(n)
{
	assert(n_points > 0);
	// The default Point constructor will be called n_points number of times.
	points_ar = new Point[n_points]; 
	for(int i = 0; i < n_points; i++){
		// This is the line x - y = 0 in 3D.
		points_ar[i].set_point(i, i, i);	
	}
	std::cout << "The Line constructor that creates an array of points was called." 
	<< std::endl;
}

// The destructor.
Line::~Line(){
	if(points_ar != NULL){
		delete[] points_ar;
	}
	std::cout << "The destructor of Line is called." << std::endl;
}
// The copy constructor. (Doing deep copy)
// We can assume that the new instance of a Line's member points_ar is NULL.
Line::Line(const Line& old_instance): m_p1(0,0,0), m_p2(0,0,0)
{
	this->n_points = old_instance.n_points;
	if(this->n_points > 0){
		this->points_ar = new Point[this->n_points]; 
		for(int i = 0; i < this->n_points; i++){
			// It is okay to shallow copy a Point 
			// because the Point class does not contain pointers.
			this->points_ar[i] = old_instance.points_ar[i]; 
		}
		
	} 
	std::cout << "The copy constructor for a Line instance was called." << std::endl;
}

// The overloaded assignments operator.
Line& Line::operator=(const Line& r_instance){
	// Checking for self assignment.
	if(this != &r_instance){
		// Making sure that the old instance was not created with the default
		// constructor and has points_ar = NULL.
		assert(r_instance.points_ar != NULL);
		if(this->points_ar != NULL){
			// Making sure that if the current object has an array that is 
			// freed before assigning new data.
			delete[] this->points_ar;	
		}
		// Shallow copy because it is between primitive types.
		this->n_points = r_instance.n_points;
		for(int i = 0; i < this->n_points; i++){
			// It is okay to shallow copy a Point 
			// because the Point class does not contain pointers.
			this->points_ar[i] = r_instance.points_ar[i]; 
		}
	}
	std::cout << "Assignment operator overload." << std::endl;
	return *this;
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

