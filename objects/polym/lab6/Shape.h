/* ***************************************************************************************
 * Filename: Shape.h 
 * Author: Lodewyk Jansen van Rensburg.
 * Student ID: 934 309 717.
 * Date: November 3, 2020.
 * Lab6: Intheritance with shapes.
 * Description: 
 * Input: -
 * Output: -
 * **************************************************************************************/

#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>

class Shape{
private:
	std::string m_name;
	std::string m_color;

public:
	// This function will only be used so that children can inherit from it.
	// It contains no other funtionality.
	virtual float area() = 0;
	// This function will be used to ouput all the member variables.
	virtual void print();

	// Accessors and Mutators.
	// These function acts as both an accessor and a mutator because it returns a reference.
	std::string& get_name();	
	std::string& get_color();

	// Constructors.
	// This constructor acts as the default and as a parameterized constructor.
	Shape(const char*, const char*);
	// Constructor 2.
	Shape(std::string name = "default_name", std::string color = "default_color");
	// 1. Desctructor.
	// Alway declare the destructo virtual when a class is inheriting from it.
	virtual ~Shape() = default;
	// 2. Assignment operator overload.
	// 3. Copy constructor.
};

// Non- member functions.
bool operator>(Shape&, Shape&);
bool operator<(Shape&, Shape&);


#endif
