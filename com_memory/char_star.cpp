/*************************************************
 *Program Filename: .cpp
 *Author: Wikus
 *Date: 
 *Desription:
 *Input:
 *Output:
 ************************************************/

// In programming we get two types of strings
// 1. c++ style string: which is an object an has member functions
// 2. c-style string: which is a char array.
// 		     Remeber that the last element in the array of array containing chars must be the NULL charater.
// 		     NULL is represented bu the integer 0 in ascii.
// 		     The '0' character is represented by the 48 int in ascii.


#include <iostream>
#include <cstdio>
#include <string>
#include <assert.h>  // This is a header file that contains the assert function.

int main(){
	// C-style string
	// You must set the size of the array one greater that the number of chars you want to store to make room for NULL at the end
	char My_array_of_char[10] = {'M','y',' ','a','r','r','a','y','\0'}; // \0 and NULL is equivalent.
	char My_array_of_char2[10] = {'M','y',' ','a','r','r','a','y'}; // Both arrays are equivalent because C++ sets the last element of a char array to NULL 
	
// NB!!! MUST USE NULL AS THE LAST ELEMENT IN THE CHAR ARRAY TO KEEP TRACK OF THE SIZE OF THE ARRAY.

	// "I am printing a pointer but c++ knows a char* is a string and prints the strin od chars: ; 
	std::cout << "I am printing a pointer but c++ knows a char* is a string and prints the strin od chars: " <<My_array_of_char << std::endl; 
	
	
	// if the condtion is false then my program will end abroptly
	// If conditions true my program continues§
	assert(1);

	return 0;
}

