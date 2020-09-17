 /**************************************************
 *Program Filename: static_keyword.cpp
 *Author: Wikus
 *Date: 18 July 2020
 *Description: Learning how to use the static keyword
 *Input
 *Output
 **************************************************/


#include <iostream> //Remember all that the #inlcude statement does is copy and paiste

//If i declare a variable outside the main function I am declaring it in the global scope.
//We call it a global variable.
//
//The problem is that if you declare a variable in the global scope, then at linking time , if there are 
//variables of the same name in other translation units(source files) then the linker will give an error
//
//The static keyword is used to restrict the global variable/function to only the translation unit where it is defined

static int global_var = 5;

static void printer(){

	std::cout << "This is a message from the printer function." << std::endl;
}

//I can now use the names printer() and global_var() in other translation units without getting an error at linking time

int main(){
	printer();
	return 0;
}
