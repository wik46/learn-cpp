/************************************************
*Program filename: c_string3.cpp
*Author: Wikus
*Date: 15 August, 2020
*Description: This is a practise code for understaning the difference between
		how the program handles pointers to string literals and array of char. 
*Input:
*Output:
************************************************/

#include <iostream>
//#include <string>

// c-style strings vs string objects.
// You can use the assignment operator to directly convert a char* to a string.

// Function prototype
const char* GetName();
char* GetName_a();

int main(int argc, char* argv[]){

	const char* pointer_to_symbolic_const = "This is a string literal";
	std::cout << "A const char* is a pointer to a symbolic literal (i.e. constant data): " << pointer_to_symbolic_const	
	<< std::endl;
	const char* name = GetName();
	std::cout << "The name: " << name << std::endl;	

	int int_array[] = {1,2,3,4};
	char char_array[] = "This is a char array";
	const char* const_char_ptr = "This is pointer to a string literal";

	// Any non-char pointer, cout will print the address.
	// If you print a char pointer, cout assumes you want to print
	// out the value that it is pointing to.
	std::cout << "[Array of int]: " << int_array << std::endl; // This will print out the memory address.
	std::cout << "[Array of char]: " << char_array << std::endl; // This will print out all the array char's.
	std::cout << "[Pointer to literal]: " << &const_char_ptr << std::endl; // This will print the string literal not the memory address.	
	return 0;
}

// NOtice that string literals have static duration not automatic duration.
// That is they die after the end of the program not at the end of the scope.
const char* GetName(){

	const char* name = "Jan-Anton";	
	return name;
}	


// This function will not work because the address of a local variable is returned.
// The address gets freed at the end of the function scope.
char* GetName_a(){
	char char_array[] = "Automatic";
	return char_array;
}
