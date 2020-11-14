/* ***************************************************************************************
 * File name: intro.cpp
 * Author: Wikus.
 * Date: November 6, 2020.
 * Description: This is a very basic program to start off error handeling.
 * Type: Example of basic use.
 * **************************************************************************************/

#include <iostream>

// The only purpose of this function is to show how to put your throw statements inside
// a function an what happens afterwards.
// This function will throw an integer error.
int thrower_int(){
	// This is the error that will be thrown.
	throw -1;
	// This will never be printed because the function will not
	// exect after the throw statement.
	std::cout << "I will not get printed." << std::endl;
	return 0;
}

int main(){
	// If know exceptions are thrown by the line of code, then the program
	// will continue as normal.
	try{
		// This is where you put the code that can cause an error.
		thrower_int();	
	// If an integer is thrown then it will be caught by this block.
	// You can catch and throw any data type.
	}catch(int){
		std::cout << "I caught an intger error." << std::endl;	
	// This is the syntax to catch errors that you did not predict.
	}catch(...){
		std::cout << "I caught an unknown error." << std::endl;
	}	
	return 0;
}
