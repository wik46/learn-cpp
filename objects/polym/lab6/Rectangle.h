/* ***************************************************************************************
 * Filename: Rectangle.h 
 * Author: Lodewyk Jansen van Rensburg.
 * Student ID: 934 309 717.
 * Date: November 3, 2020.
 * Lab6: Intheritance with shapes.
 * Description: 
 * Input: -
 * Output: -
 * **************************************************************************************/

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"
#include <iostream>

class Rectangle: public Shape{
	float m_width;
	float m_height;
public:
	// This is a simple print function.
	void print() override;
	// This function will return the area of the rectangle.
	float area() override;
	// Accessors and Mutators.
	float& get_width();
	float& get_height();
	// The default constructor.
	// m_width = 1 and m_height = 1.
	Rectangle(float w = 1, float h = 1);
	// Constructor type 2.
	Rectangle(std::string, std::string, float, float);

	// The class does not contain any dynamic memory.
	// Therefore the class will make use of the default.
	// 1. Constructor.
	// 2. Copy constructor.
	// 3. Assignment operator overload.

};

#endif
