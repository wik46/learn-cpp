/*************************************************
 *Program Filename: void_pointer.cpp
 *Author: Wikus
 *Date: August 7, 2020
 *Desription: Post cs 161 class on void_pointers.
 *Input:
 *Output:
 ************************************************/

#include <iostream>
#include <cstdio>
#include <string>

// Void pointers.
// =============
//
// 1. You cannot dereference a void pointer.
// 2. You must cast it into a pointer of a specific type in oder to dereference. 

int main(){
	int my_int = 65;

	// This is not allowed and will cause a compiler error
	// You cannot point a char* to a variable that is not of type char.
	//char* ptr1 = &my_int;


	void* my_pointer = NULL; // This is good practise to set the value of an unused
					// pointer to NULL
	my_pointer = &my_int; // This is allowed.
	
	// You can used a void pointer and cast into it.
	
	// Both pointers are pointing to my_int
	int* int_ptr = (int*)&my_int;
	char* char_ptr = (char*)&my_int;
	
	// This will still print out 65.
	std::cout << "int_ptr: " << *int_ptr << std::endl;
	// This will print out A, because the ascci value of 65 is A
	std::cout << "char_ptr: " << *char_ptr << std::endl;		
	

}
