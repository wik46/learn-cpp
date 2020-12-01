/*
 * Filename: func_ptr.cpp
 * Author: Wikus Jansen van Rensburg
 * Date: November 26,2020.
 * Description: This is a small little program to demonstrate how to used function
 * 		pointers. This is mainly used to remember the syntax of how to
 * 		use them.
 *
 * */
#include <iostream>

// The name of a function without the '()' is the address of the function.

// Example 1:
// This is a function that will be passed into another function.
void print(){
	std::cout << "I passed as a function parameter." << std::endl;
}
// This functions accpets function pointers that have a return typ of void and 
// 	do not accept and parameters.
void function(void (*f)()){
	f();	
}

// Example 2:
bool greater_than(int a, int b){
	return a > b;
}
// This function accpets functions with return type bool and parameters int, int.
void print_greater(int a, int b,  bool (*f)(int,int)){
	if( f(a, b) ){
		std::cout << a << " greater than " << b << std::endl;
	}else{
		std::cout << a << " less than " << b << std::endl;
	}
}

int main(){
	// Use of example one.
	function( print );

	// Example 2:
	print_greater(10, 5, greater_than);

	return 0;
}
