/*
 * Filename: driver.cpp.
 * Author: Wikus
 * Description: This is to practise using static member variables.
 * Date: October 26, 2020.
 * */

#include <iostream>

class Animals{
public:
	// This declares the static variable.
	// It tells the compiler that the variables exist, but we need to 
	// define it outside the class scope.
	static int m_num_animals; // declaration.
	// Constructor.
	Animals(){
		Animals::m_num_animals++;
	}
};
// This is the static variable.
int Animals::m_num_animals{0}; // Definition.


int main(){
	// Notice that the static variable is created before any instance
	// of the class Animals is created.
	std::cout << Animals::m_num_animals << std::endl;

	Animals an1, an2, an3;
	std::cout << Animals::m_num_animals << std::endl;
	return 0;
}
