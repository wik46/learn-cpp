/*************************************************
 *Program Filename: pointers_const.cpp
 *Author: Wikus
 *Date: 13 June 2020
 *Desription: Learning pointers from the one lonely coder
 *Input:
 *Output:
 ************************************************/

//=========================
//const and pointers
//==========================


#include <iostream>
#include <cstdio>
#include <string>


int main(){
	
	// 1.==============================
	// This is a pointer to a const int.
	// Equivalent: int const*
	// Rules: I am not allowed to change the value of the integer that ptr is pointing to.	
	const int* ptr;	
	int first_val= 10;
	int second_val = 12;
	ptr = &first_val;
	// I am allowed to point the ptr to different memory.
	ptr = &second_val;
	// *ptr = 0; // Compilation error, you can not change read only memory.
		
	// 2.==============================
	// Remeber that any variable that is of type const must be initialized. (value assigned at decleration)
	// This is a const pointer to an int.
	// - I am not allowed to point the pointer to different memory.
	int b = 12;
	int* const ptr1 = &b;
	// I am allowed to change the value of the integer the pointer is pointing to.
	*ptr1 = 7;
	// ptr1 = &second_val; // Compilation error: You cannot change the value of a constant variable.
	// 						i.e. you cannot point a const pointer to different memory.
	

	// 3.==============================
	// This is a const pointer to a const int.
	// - I am not allowed to change the value of the int the pointer is pointing to.
	// - I am not allowed to point the pointer to different memory.
	int c = 14;	
	const int* const ptr2 = &c;
	// Invalid: 
	//ptr2 = &b; pointer is a variable that contains read-only memory.
	//*ptr2 = 2; pointer is pointing to read-only memory.
	
	std::cout << "const int*: "<< *ptr << ", int* const: " << *ptr1 <<  
	 ", const int*: " << *ptr2<< std::endl;
}
