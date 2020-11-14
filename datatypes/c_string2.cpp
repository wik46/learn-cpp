/************************************************
*Program filename: c_string2.cpp
*Author: Wikus
*Date: 15 August, 2020
*Description: This is an example of how a function takes in a string as a reference versus
		by value.
*Input:
*Output:
************************************************/

#include <iostream>
//#include <string>

// c-style strings vs string objects.
// You can use the assignment operator to directly convert a char* to a string.

// Function prototype
void no_change(std::string);
void change(std::string& in_string);

int main(int argc, char* argv[]){

	std::string name = argv[1];		
	// This function changes the value of the string.
	change(name);
	
	// This function copies a string.
	//no_change(name);
	std::cout << "string: " << name << std::endl;
	
	const char* const_char = argv[1];
	std::cout << "const char: " << const_char << std::endl;

	return 0;
}


/*
 * Function: no_change()
 * Description: If you take in a string by value you only copy.
 *
 * */
void no_change(std::string in_string){
	in_string[0] = '1';
	std::cout << "[no_change]: " << in_string << std::endl;
}

/*
 * Function: change()
 * Description: If you take in a string by value you only copy.
 *
 * */
void change(std::string& in_string){
	in_string[0] = '1';
	std::cout << "[change]: " << in_string << std::endl;
}	
	
