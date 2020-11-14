/* ***************************************************************************************
 * File name: stack_unwinding.cpp
 * Author: Wikus.
 * Date: November 11, 2020.
 * Description: This is built on the functionality of intro.cpp. Every file in the 
 * Type: Stack unwinding.
 * Learning resource: Learncpp 14.3
 * **************************************************************************************/

// ===============================================================
// This is a program that demonstrates how stack undwinding works.
// ===============================================================

/* A throw statement does not have to be directly inside a try block. It can be inside a 
 * funtcion. What happens is that when an exception is thrown inside a function, the 
 * program immediatly stops and starts looking for the try block above. If is cannot
 * find a try block inside the function, power is returned to its caller. The caller 
 * then searches for a try block. If a try block is found then the program searches for
 * the catch block of the corrects type inside the current caller. 
 * If no correct catch block is found or if not initial try block was found, the caller
 * returns power to its caller. This process continues untill the correct catch block is 
 * found or if main() is reached and the program is terminated. The process is referred
 * to as stack unwinding.
 */  


#include <iostream>
#include <string>


// These function will be used to demonstrate how the stack unwinds.
void last_func(){
	std::cout << "Inside last_func()." << std::endl;
	throw 10;
	// This statement will never get printed.
	std::cout << "End of last_func()." << std::endl;

}
// This function will call last_func().
void third_func(){
	// Notices that there is no try/catch block inside this function. Therefore
	// after last_func() is called and it throws the exception, third_func() will 
	// bubble up and return power to its caller second_func().
	std::cout << "Inside third_func()." << std::endl;
	last_func();
	// This will not be printed because third_func() does not have a try/catch block.
	std::cout << "End of third_func()." << std::endl;
}
// This function calls third_func() and has a try/catch block but of incorrect type.
// Notices that no implicit conversion will occur between int and double.
void second_func(){
	std::cout << "Inside of second_func()." << std::endl;
	try{
		third_func();
	}catch(double){
		std::cout << "second_func() caught a double." << std::endl;
	}
	// Note that this will not be printed because the function bubles
	// up the stack since the exception can not be caught.
	std::cout << "End of second_func()." << std::endl;
}
// This function will catch the exception.
// Notice that if an exception is caught it returns as normal to the caller.
void first_func(){
	std::cout << "Inside of first_func()." << std::endl;
	try{
		second_func();
	}catch(int n){
		std::cout << "first_func() caught an int: " << n << std::endl;
	}
	std::cout << "End of first_func()." << std::endl;
}
// This function will be the original one.
void normal_func(){
	std::cout << "Inside of normal_func()." << std::endl;
	try{
		first_func();
	}catch(int){
		// The exception was already caught by first_func() so this will not
		// be handeled by normal_func().
		std::cout << "normal_func() caught an int." << std::endl;
	}
	std::cout << "End if normal_func()."<< std::endl;	
}

int main(){
	// Notice how there is no try/catch block inside main.
	// ## All the print statements in the first lines of the functions will be called.
	// 1. When last_func() is reached it will throw the exception 10, type int.
	// 2. There is no try/catch block inside third_func() therefore the program 
	//     immediately returns power to second_func().
	// 3. second_func() has a try/catch block but is is not a correct type. 
	//     Therefore the function returns power to its caller.
	// 4. first_func() has the correct try/catch blocks to handel the error.
	//     It will handle the error and then the error is handeled.
	// 5. The error is handeled in first_func() so normal_func() will
	//     not attempt to handel it and the function continues as normal.
	std::string message = "Start of main.";
	std::cout << message.c_str() << std::endl << std::endl;
	normal_func();	
	std::cout << std::endl << "End of main()." << std::endl;
	return 0;
}
