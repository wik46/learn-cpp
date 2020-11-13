/* ***************************************************************************************
 * Filename: Shape.cpp 
 * Author: Lodewyk Jansen van Rensburg.
 * Student ID: 934 309 717.
 * Date: November 3, 2020.
 * Lab6: Intheritance with shapes.
 * Description: 
 * Input: -
 * Output: -
 * **************************************************************************************/


#include "Shape.h"

/* 
 * Function name: area().
 * Description: This is an empty function. It is only defined so that the behaviour of the
 * 		function can be changed by inhereted classes. This is a virtual function
 * 		so that pointers or a references of the base class can store
 * 		derived member addresses.
 * Parameters: -
 * */
//float Shape::area(){
//	return 0.0;
//}

/*
 * Function name: print().
 * Description: This function will be used to output all the members contain in class.
 * Parameters: -
 * */
void Shape::print(){
	std::cout << "Name: " << m_name << "\nColor: " << m_color << std::endl;
	return;
}
/* **
 * Function name: get_name()
 * Description: This function will act as a getter and a setter.
 * Parameters: -
 * */
std::string& Shape::get_name(){
	return m_name;
}
/* **
 * Function name: get_color().
 * Description: This function will act as a getter and a setter.
 * Parameters: -
 * */
std::string& Shape::get_color(){
	return m_color;
}

/* *
 * Function name: Shape()
 * Description: This is the constructor used to intitialize the Shape class
 * 		member variables m_name and m_color.  
 * Parameters: const char*, const char*.
 * */
Shape::Shape(const char* name, const char* color)
:m_name{name}, m_color{color}
{}
/* *
 * Function name: Shape()
 * Description: This is the constructor used to intitialize the Shape class
 * 		member variables m_name and m_color. The default values are 
 * 		default_name and default_color.
 * Parameters: string, string.
 * */
Shape::Shape(std::string name, std::string color)
:m_name{name}, m_color{color}
{}

/* *
 * Function name: ~Shape()
 * Description: This constructor does not need to clean up after the 
 * 		base portion of the class, but later classes will need to clean up
 * 		after themselves. Therefore we declare the destructor virtual.
 * Paramters: -
 * */
// I made the virtual destructor default.
//Shape::~Shape(){}

// ======================================================================================
// Non - member functions.
// ======================================================================================

/*
 * Function name: operator<().
 * Description: This is the overloaeded comparison operator.
 * Parameters: const Shape*, const Shape*.
 * */

// Note that I am not passing by const referenc because area() is not a const member.
bool operator<(Shape& s1, Shape& s2){
	// This is only a approx comparison.
	return (int((s1.area()) * 10000) < int((s1.area()) * 10000));
}
/* **
 * Function name: operator>().
 * Description: This is the overloaeded comparison operator.
 * Parameters: const Shape*, const Shape*.
 * */
bool operator>(Shape& s1, Shape& s2){
	// This is only a approx comparison.	
	return (int((s1.area()) * 10000) > int((s2.area()) * 10000));
}

