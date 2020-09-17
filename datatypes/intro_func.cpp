/************************************************
 *Program Filename: intro_func.cpp
 *Author: Wikus
 *Date: 12 July 2020
 *Description: Introduction 
 *Input:
 *Output:
 ***********************************************/

#include <iostream>

// This is my first namespace created
namespace name_s{
	void doB(){
		std::cout << "Function doB()" << std::endl;
	}	
	void doA(){
		std::cout << "Start doA()" << std::endl;
		doB();
		std::cout << "End doA()" << std::endl;
	}
	int get_number(){
		int user_num;
		std::cout << "Please enter a number: ";
		std::cin >> user_num;
		return user_num;
	}
}

// This is my 2nd namespace created
namespace name_p{	
	
	void PrintValue(int x, int y){
		std::cout << "The value of the first argument: " << x << std::endl;
		std::cout << "The value of the second argument: " << y << std::endl;
	}
}
int main(){
#if 0	
	name_p::PrintValue(name_s::get_number(),name_s::get_number()); /*Note that the order of the functiond
									is not defined in c++
									This is another example of undefined behaviour*/
	std::cout << "===========" << std::endl;
	int number = name_s::get_number();
	std::cout << number << std::endl;
	std::cout << "============" << std::endl;	
	std::cout << "Start main()" << std::endl;
	name_s::doA();
	std::cout << "End main()" << std::endl;



	
	std::cout << "This prints in my #if an #endif part." << std::endl;	

#endif
	return 0;
}
