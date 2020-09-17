/***************************************
 *Program Filename: enum.cpp
 *Author: Wikus
 *Date: 10 July 2020
 *Description: Learning arrays
 *Input
 *Output
 **************************************/

#include <iostream>
#include <cstdlib>



//ENUMS
//
//When i want to creat a data type that can only take on specific interger values
//An enum is a set of integer where I can specify the name of the for the elements

enum Level // :char   : you can set your types for the elements in the enums in later c++ versions
{
	error, warning, info  //By default the enum start the first integer at 0 and increment the next elements by one	
};

int main(){
	Level level_state = error; // this A is just an integer
	if(level_state == 0){//B = 1 and I want the if statement to be true to print the result
		std::cout << "Here are the values of error: " << error << " and warning: " << warning << " and info: " << info << std::endl;
	}
	return 0;
}
