/* ***************************************************************************************
 * Filename: Circle.cpp 
 * Author: Lodewyk Jansen van Rensburg.
 * Student ID: 934 309 717.
 * Date: November 3, 2020.
 * Lab6: Intheritance with shapes.
 * Description: This is the implementation file for the Circle class. Circle is a child
 * 		of Shape and has one additional field that represents the radiu of
 * 		the circle. The defaul radius is 1.
 * Input: -
 * Output: -
 * **************************************************************************************/

#include "Shape.h"  // Parent.
#include "Circle.h" // Child.

#include <cassert>
#include <iostream>

/*
 * Function name: area().
 * Description: This function will return the area of the circle.
 * Parameters: - 
 * */
float Circle::area(){
	// PI = 3.14... is defined in Circle.h
	return PI * m_radius * m_radius;
}

/*
 * Function name: print().
 * Description: This function will be used to print all the member variables that is in
 * 		the child part as well as the member variables inherited from the
 * 		parent.
 * Parameters: -
 * */
void Circle::print(){
	Shape::print();
	std::cout << "Radius: " << m_radius << std::endl;
}

/*
 * Function name: get_radius().
 * Description: This function will act as a getter and a setter because it returns
 * 		a reference to the radius.
 * Parameters: - 
 * */
float& Circle::get_radius(){
	return m_radius;
}

/* **
 * Function name: Circle().
 * Description: This is the default and a parameterized contructor.
 * 		The default Shape constructor will be called.
 * Parameters: -
 * **/
Circle::Circle(float radius)
: Shape(), m_radius{radius}
{
	assert(int(m_radius) >= 0 );
}

/*
 * Function name: Circle().
 * Description: This constructor will let me set the name, color, and radius of the Circle.
 * Parameters: string, string, float.
 * */
Circle::Circle(std::string name, std::string color, float radius)
: Shape(name, color), m_radius{radius}
{}
