/*
 * Filename: test_vec.cpp
 * Description: This is a file that is used to test the functionality of the
 * 		Vec2d class.
 * Date: November 15, 2020.
 * */

#include "Vec2d.h"

#include <iostream>

// Testing the code.
//
int main(){

	// Creating a 2 dimensional mathematical vector.
	Vec2d v1(1,2);
	Vec2d v2(1,4);
	Vec2d v3(3,2);
	Vec2d v4(10,2);
	Vec2d v5(1,0);
	Vec2d v6(2,7);
	// 1. Summing the two vectors:
	std::cout << std::endl;
	std::cout << "v1: " << v1 << " + v2: " << v2 << std::endl;
	std::cout << " = "<< v1 + v2 << std::endl;
	std::cout << "v1: " << v1  << std::endl;
	std::cout << "v2: " << v2 << std::endl;
	std::cout << std::endl;
	// 2. Scalar multiplication.
	std::cout << "2 * v1 : " << v1 << std::endl;
	std::cout << " = "<< v1 * 2 << std::endl;
	std::cout << "v1: " << v1  << std::endl;
	std::cout << std::endl;
		
	return 0;
}
