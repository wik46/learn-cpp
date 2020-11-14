/* ***************************************************************************************
 * File name: print_statements.cpp
 * Author: Wikus.
 * Date: November 6, 2020.
 * Description: This is built on the functionality of intro.cpp. Every file in the 
 * 		sequence will start to go more in depth.
 * Type: Example of basic use.
 * **************************************************************************************/

#include <iostream>

// These classes are only used to show how excpetion handeling works with classes.
class Base
{

};

class Derived: public Base{

};

int main(){
	// Example 1;
	std::cout << std::endl;
	std::cout << "Example 1" << std::endl;
	try{
		std::cout << "Inside try." << std::endl;
		throw 4.1;
		std::cout << "I am after throw and will not get printed." << std::endl;
	}catch(double f){
		std::cout << "Inside catch" << std::endl;
	}catch(...){
		std::cout << "See what you thrown" << std::endl;
	}	
	std::cout << "After exption handeling" << std::endl;
	
	// Example 2;
	std::cout << std::endl;
	std::cout << "Example 2: Catching classes." << std::endl;
	Base b;
	Derived d;
	// The Derives instance has a part Base therefore the Base is caught. Therefore always put your
	// most base class at the bottom.
	try{
		std::cout << "Inside try." << std::endl;
		// I am throwing Derived.
		throw d;
	}catch(Base b){
		std::cout << "Base caught" << std::endl;
	}catch(Derived d){
		std::cout << "Derived caught" << std::endl;
	}
	// Example 3;
	std::cout << std::endl;
	std::cout << "Example 3: Nested try/catch" << std::endl;
	try {
		std::cout << "Inside try." << std::endl;	
		throw 5;
	}catch(int x){
		std::cout << "First catch" << std::endl;
		try{
			std::cout << "Inside inner try" << std::endl;
			// This will rethrow the intial type
			// In this case 5 will be thrown again.
			throw;
		}catch(int n){
			std::cout << "Inside inner catch" << std::endl;
		}
	}

	// Example 1;
	std::cout << std::endl;
	//std::cout << "Example 1" << std::endl;

	return 0;
}
