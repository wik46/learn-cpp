/***************************************
 *Program Filename: command_line.cpp 
 *Author: Wikus
 *Date: 3 August 2020
 *Description: Command line arguments is when I can add input along with my
		executable file when I run my program. 
 *Input:
 *Output:
 ***************************************/

#include <iostream>


// int argc is the number of command line arguments enterd.
// 
// Exmple: a.out hello world and everyone else
// This above code has 6 command line arguments.
//
// char* argv[]: argv is an array containg char*. there argv[0] is the string "a.out"
// agrv is an array of char*, each char* is a set of chars that form a c-style string.

int main(int argc, char* argv[]){
	// This if statements determines if at least two command line arguments were entered.
	if(argc < 2){
		std::cout << "You did not enter the correct amount of arguments. " << std::endl;
	}

	for(int i = 0; i < argc; i++){
		std::cout << "element:[" << i << "]" << argv[i]<< std::endl;
	}
	return 0;
}

