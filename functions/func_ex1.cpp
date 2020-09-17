/***************************************
* File name: func_ex1.cpp
* Author: Wikus
* Date: September 17
* Description: Refreshing my memory on c-style strings. 
* Input: Studying.
* Output: Better knowledge.
***************************************/

#include <iostream>

// Note to self:
// 	std::string should always be used but it is important to understand
// 	how c-style strings work.

// Function name print_and_return()
// Parameters: const char*
// Description: The function will be used to compare with different but very
// 		similiar functions.
// Pre-conditions:
// Post-conditions:

// The parameter of the function is read-only variable.
// 	Changing a charater in the string will result in a seg fault.
const char* print_and_return(const char* read_only_memory_var){
	std::cout << "[const char* version]" << std::endl;
	std::cout << "You entered the c-style string by value: ";
	std::cout << read_only_memory_var << std::endl;
	return read_only_memory_var;
	
}

// Function name print_and_return()
// Parameters: char[]
// Description: The function will be used to compare with different but very
// 		similiar functions.
// Pre-conditions:
// Post-conditions:

// The name of an array is a pointer to the first elements in the array.
// If I want modify the string after it was return by the function it needs to 
// 	be of type char* and not const char*.
char* print_and_return(char* read_write_memory_var){
	// To see which function was called.
	std::cout << "[char* version]" << std::endl;
	std::cout << "You entered the c-style string by value: ";
	std::cout << read_write_memory_var << std::endl;
	return (char*)read_write_memory_var;
}

int main(){
	// Example of function 1.
	const char* string_const_char_star = print_and_return("I am a string.");
	// string_const_char_star[0] = '5'; // This statement will result in a seg fault.
					    // you cannot change read only memory.

	// Example of function 2.
	char char_array[] = "A string";
	char* string_char_star = print_and_return(char_array);
	string_char_star[0] = '$';
	// Outputting the result of the changed variable.
	std::cout << "[main]: " << string_char_star << std::endl;
	
	return 0;
}
