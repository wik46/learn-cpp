/*************************************************
 *Program Filename: .cpp
 *Author: Wikus
 *Date: 
 *Desription:
 *Input:
 *Output:
 ************************************************/

#include <iostream>

// A struct's memory is just the sum of memory of all the member variables inside the struct.

struct Entity {
	int x, y;
};

int main(){
	
	
	// Example 1. I am creating a raw array.
	
	Entity e = {5, 8 }; // Initializing the variables inside my struct.
	int* ptr_array = (int*)&e; // I am casting an Entity* to a int*.
	std::cout << ptr_array[0] << ", " << ptr_array[1] << std::endl; // An array is just a pointer to the first element in the array.
	

	// Exmaple 2.
	// Storing a as an int.
	int a = 50;
	
	// Converting &a to a double* and then dereferncing it.
	double* value = (double*)&a;
	double value1 = 50;

	std::cout << "Float: " << value << std::endl;
	std::cout << "Interger: " << &a << std::endl;


	return 0;
}

