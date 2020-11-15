/* ***************************************************************************************
 * Filename: 
 * Author: Lodewyk Jansen van Rensburg.
 * Student ID: 934 309 717.
 * Date: November 3, 2020.
 * Lab6: Intheritance with shapes.
 * Description: 
 * Input: -
 * Output: -
 * **************************************************************************************/

#include "Shape.h"
#include "Rectangle.h"

#include <iostream>

/* ***************************************************************************************
 * Function name: area().
 * Description: This function will return the area of the circle.
 * Parameters: - 
 * */
float Rectangle::area(){
	return m_width * m_height;
}

/*
 * Function name: print().
 * Description: This function will be used to print all the member variables that is in
 * 		the child part as well as the member variables inherited from the
 * 		parent.
 * Parameters: -
 * */
void Rectangle::print(){
	Shape::print();
	std::cout << "Width: " << m_width << std::endl;
	std::cout << "Height: " << m_height << std::endl;
}

/* ***********************
 * Function name: get_width().
 * Description: This function will act as a getter and a setter because it returns
 * 		a reference to the m_width.
 * Parameters: - 
 * */
float& Rectangle::get_width(){
	return m_width;
}
/*
 * Function name: get_height().
 * Description: This function will act as a getter and a setter because it returns
 * 		a reference to the m_height.
 * Parameters: - 
 * */
float& Rectangle::get_height(){
	return m_height;
}


/* 
 * Function name: Rectangle()
 * Description: This is the 2nd constructor for the class. It will allow the user to 
 * 		set the name and color of the shape as well.
 * Parameters: -
 * */
Rectangle::Rectangle(std::string name, std::string color, float width, float height)
:Shape(name, color), m_width{width}, m_height{height} 
{}
/* 
 * Function name: Rectangle()
 * Description: This is the default constructor for the class Rectangle. It will
 * 		intitial the Shape parent class members with the default Shape()
 * 		and set m_width, m _height = 1.
 * Parameters: -
 * */

Rectangle::Rectangle(float width, float height)
:Shape(), m_width{width}, m_height{height}
{}
