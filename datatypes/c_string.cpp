/************************************************
*Program filename: string.cpp
*Author: Wikus
*Date: 11 July
*Description: Strings in cpp
*Input:
*Output:
************************************************/

#include <iostream>
#include <string>

// c-style strings vs string objects.
// You can use the assignment operator to directly convert a char* to a string.


int main(int argc, char* argv[]){
	if(argc < 2){
		std::cout << "You need at least two command line arguments." << std::endl;
		return 0;
	}
	
	std::string my_string_object;

	my_string_object = argv[0];

	std::cout << "The length of the first com_line arg: " << my_string_object.length() << std::endl;
	// Learn CPP 6.6
	// C-style strings and arrays are immutable.
	// You can change a single element but not the entire array/string
	

	// Fixed array case
	char array_case[20] = "Fixed array";
	array_case[0] = 'b' ;
	std::cout << array_case << std::endl;
	
	// Symbolic Constant case
	// (They have static duration: The dont go out of scope, instead they get terminated at the end of the program)
	const char* ptr_case = "Symbolic const";
	std::cout << ptr_case << std::endl;	

	// Notice the way cout treats pointers of different types.
	int int_value = 10;
	int* int_ptr = &int_value;


	// 'a' is a character, "a" is a string (i.e a const char*)	
	int int_array[4] = {'a','b','c','d'};
	std::cout << "int*: " << int_ptr << " and const char*: " << ptr_case << std::endl;
	std::cout << "int_array: " << int_array << " and value at index 0: " << int_array[0] << std::endl;
	return 0;	
}
	
