/* ***************************************************************************************
 * Filename: intro1.cpp
 * Author: Wikus
 * Date: November 12, 2020.
 * Description: This is the first program written using templates in cpp.
 * 		The purpose of this file is only to learn the basic use of templates.
 * Learning resource: Learn cpp 13.1 - 13.3
 * **************************************************************************************/

#include <iostream>


// ===================
// Function templates: 
// ===================

// Why do we need them?

/* 
   We want to be able to define a function that different types as parameters
   but those types are similiar so we don't want to write two different functions.
   Think about a function that adds to integers. We would want the same function to
   be able to add double's, floats without losing the contents due to implicit casting. 
*/



/* ***************************************************************************************
 * Function name: sqrt() 
 * Description: This function will take the square root of the number passed in as 
 * 		argument to it.
 * Parameters: <template>
 * Pre-conditions: -
 * Post-conditions: -
 * **************************************************************************************/
template <typename T> // You can chooses any identifier for T but T is best practise. 
T sqrt(T number){
	if(number > 0){
		return number * 0.5;
	}else{
		// This will indicate that the square root was unsuccessful.
		return -1;
	}
}

// You function can take in just one template parameter.
/* ***************************************************************************************
 * Function name: print() 
 * Description: This function will take the square root of the number passed in as 
 * 		argument to it.
 * Parameters: <template>
 * Pre-conditions: -
 * Post-conditions: -
 * **************************************************************************************/
// This is to define multiple template type parameters.
template <typename T1, typename T2>
void print(T1 variable1, T2 variable2, const char* message){
	std::cout << message << ": 1. "<< variable1 << std::endl;
	std::cout << message << ": 2. "<< variable2 << std::endl;
	std::cout << "--------" << std::endl << std::endl;
}

int main(){
	float float1 = 10.2;
	int int1 = 2;
	double double1 = 23.111;
	// Note that I am passing three different types into the same function
	std::cout << "I passed in a float: " << sqrt(float1) << std::endl;
	std::cout << "I passed in a int: " << sqrt(int1) << std::endl;
	std::cout << "I passed in a double: " << sqrt(double1) << std::endl;
	std::cout << std::endl;
	// You can determine the number of template parameters:
	print(float1, int1, "This the first message");
	print(int1, double1, "This the second message");
	return 0;
}
