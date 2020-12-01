/*
 * Filename: testing.cpp
 * Author: Lodewyk Jansen van Rensburg.
 * Date: November 12, 2020.
 * Description: This file will be used to testing the 2d_array inside 
 * 		the class_templates.hpp file.
 * */
#include "_2d_Array.hpp"
#include "Vec2d.h"

#include <iostream>


int main(){
	
	_2d_Array<char> my_ar('@', 4);
	std::cout << my_ar.m_array.size() << std::endl;
	
	// 1. Taking in the vector to test if is_inside() works correctly.
	std::cout << std::endl;
	Vec2d v;
	std::cin >> v;
	
	if(my_ar.is_inside(v)){
		std::cout << "Is inside" << std::endl;
	}
	my_ar.search_around(v);

	std::cout << std::endl;
	// This is just a print function used for development.	
	my_ar.print();
	// 4. Using the .print_with_grid() function.
	my_ar.print_with_grid();
	return 0;
}
