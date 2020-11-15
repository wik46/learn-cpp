/*
 * Filename: testing.cpp
 * Author: Lodewyk Jansen van Rensburg.
 * Date: November 12, 2020.
 * Description: This file will be used to testing the 2d_array inside 
 * 		the class_templates.hpp file.
 * */
#include "1d_array.hpp"

#include <iostream>


int main(){
	
	Array<int> my_ar(1,10);
	// This inserts the number at the back of the array.
	my_ar = 1;
	my_ar = 2;
	std::cout << my_ar.m_array.size();
	my_ar.print();
	return 0;
}
