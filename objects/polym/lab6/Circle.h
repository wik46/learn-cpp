/* ***************************************************************************************
 * Filename: Circle.h
 * Author: Lodewyk Jansen van Rensburg.
 * Student ID: 934 309 717.
 * Date: November 3, 2020.
 * Lab6: Intheritance with shapes.
 * Description: 
 * Input: -
 * Output: -
 * **************************************************************************************/

#ifndef CIRCLE_H
#define CIRCLE_H

#define PI 3.14159265

#include "Shape.h"
#include <iostream>


class Circle: public Shape{
	// This will the only additional field for the Circle class.
	float m_radius;

public:
	// This will return the area of the Circle instance.
	float area() override;
	// This function will print out all the members in the class
	// as well as the members inherited from the class.
	void print() override;
	
	// Accessor and Mutator.
	float& get_radius();
	
	// The circle constructor:
	// The default constructor will set the radius equal to 1.
	Circle(float radius = 1.0);	
	// A version of a parameterized consructor.
	Circle(std::string, std::string, float);
	// Destructor.
	// Copy constructor.
	// Assignment operator overload.	
};

#endif
