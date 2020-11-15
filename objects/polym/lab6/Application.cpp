/* ***************************************************************************************
 * Filename: Application.cpp 
 * Author: Lodewyk Jansen van Rensburg.
 * Student ID: 934 309 717.
 * Date: November 3, 2020.
 * Lab6: Intheritance with shapes.
 * Description: This file is used to demonstrate the use of the various shape.
 * 		1. Demonstration of the base class Shape.
 * 		2. Demonstration of a child class Circle.
 * 		3. Demonstration of a child class Rectangle.
 * 		4. Demonstration of a child of Rectangle class, called Square.
 * Input: -
 * Output: -
 * **************************************************************************************/


#include "Shape.h"      // Parent.

#include "Circle.h"     // Child of Shape.
#include "Rectangle.h"  // Child of Shape.
#include "Square.h" 	// Child of Rectangle.

#include <iostream>

int main(){
	std::string name = "circle";
	std::string name1 = "rectangle";
	std::string color = "color";
	std::string blue = "blue";
	std::string red = "red";


	// 1. Demonstration.
	std::cout << std::endl;
	std::cout << "1.) Demonstration of the base class called Shape." << std::endl;
	// A default shape.
	Shape* s1;
	// A specified shape.
	Shape* s2;
	std::cout << std::endl;
	
	// 2. Demonstration.
	std::cout << std::endl;
	std::cout << "2.) Demonstration of a child class called Circle." << std::endl;
	Circle c1;
	
	Circle c2(name, color, 1.6);		
	Shape* s_ptr = &c1;
	s_ptr->print();
	Circle* dyn_casted = dynamic_cast<Circle*>(s_ptr);
	// If dynamic_cast fails, it will return a NULL pointer.
	// It can fail because what is we are trying to cast a base type to a derived type if
	// the underlying type is actually a base and not a derived like we tought.
	if(dyn_casted){
		std::cout << "Dynamicly casted back toe Circle, radius: " << dyn_casted->get_radius() << std::endl;
	}
	// 3. Demonstrating the comparison operator.
	
	std::cout << std::endl;
	std::cout << "3.) Demonstration of the comparison operator." << std::endl;

	Circle bigger(name, blue, 20);
	Circle smaller(name, red, 10);
	Shape& bigger_ref = bigger;
	Shape& smaller_ref = smaller;

	if(bigger_ref > smaller_ref){
		bigger_ref.print(); 
	}else{
		std::cout << "Comparison has an error."<< std::endl;
	}
	
	// 4. Demonstration of the Rectangle class.
	std::cout << std::endl;
	std::cout << "4.) Demonstration of the Rectangle class." << std::endl;
	Rectangle default1;
	Rectangle default2(1.5,2.5);
	Rectangle rec1(name, red, 23, 10);


		
	Shape* d1_ptr = &default1;
	Shape* d2_ptr = &default2;
	Shape& rec1_ref = rec1;
	d1_ptr->print();
	d2_ptr->print();
	rec1_ref.print();
	if( *d1_ptr < rec1_ref){
		std::cout << "Condition evaluated true." << std::endl;
		rec1_ref.print();	
	}else{
		std::cout << "Something is not right." << std::endl;
	}
	return 0;
}
