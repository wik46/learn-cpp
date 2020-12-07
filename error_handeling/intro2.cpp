/* ***************************************************************************************
 * File name: intro2.cpp
 * Author: Wikus.
 * Date: November 6, 2020.
 * Description: This is built on the functionality of intro.cpp. Every file in the 
 * 		sequence will start to go more in depth.
 * Type: Example of basic use.
 * **************************************************************************************/

#include <iostream>

// Here we are building on the example of intro.cpp.
// The only purpose of this function is to show how to put your throw statements inside
// a function an what happens afterwards.
// This function will throw an integer error.
int thrower_int(){
	// This is the error that will be thrown.
	// This is only for example purposes to show how a throw statement will be used.
	if(1){
		throw -1;
	
	}// This will never be printed because the function will not
	// exect after the throw statement.
	std::cout << "I will not get printed." << std::endl;
	return 0;
}

// 2nd function that will throw.
void thrower_float(){
	float err = 1.4;
	throw err;
	return;
} 
// 3rd function that will throw.
void thrower_c_string(){
	
	const char* err = "I am a c-string";
	throw err;
	return;
} 
// 4th function that will throw.
void thrower_string(){
	std::string error = "";
	throw error;
	return;
} 
// You can evene throw user defined types.
class User_def{
	std::string m_name;
public:
	User_def(): m_name{"struct"}
	{}
};
// The function that will throw the error.
void thrower_user_type(){
	throw User_def();
	return;
}

int main(){
	// If know exceptions are thrown by the line of code, then the program
	// will continue as normal.
	try{
		std::cout << "********************************************" << std::endl;
		std::cout << "Enter the expetion that you want to throw.\n"
			<< "1. Int \n2. float \n3. c_string \n4. string \n5. User_def."
			<< std::endl;
		std::string user_input = "";
		std::cin >> user_input;
		std::cout << "********************************************" << std::endl;
		// This is to help the user see what is happening.	
		if(user_input == "1"){
			thrower_int();
		}else if(user_input == "2"){
			thrower_float();
		}else if(user_input == "3"){
			thrower_c_string();
		}else if(user_input == "4"){
			thrower_string();
		}else if(user_input == "5"){
			thrower_user_type();
		}else{
			std::cout << "Restart the program and enter an int between 1-5." 
			<< std::endl;
			// A char is not defined as a catch condition. Therefore it will evoke the
			// last catch block.
			throw 'a';
		}

	// If an integer is thrown then it will be caught by this block.
	// You can catch and throw any data type.
	}catch(int){
		std::cout << "I caught an intger error." << std::endl;	
	// This is the syntax to catch errors that you did not predict.
	}catch(float){
		std::cout << "I caught an float error." << std::endl;	

	}catch(const char*){
		std::cout << "I caught an const char* error." << std::endl;	

	}catch(std::string){
		std::cout << "I caught an string error." << std::endl;	

	}catch(User_def& ){
		std::cout << "This is very helpful because you can give"
		<< " a lot of info in a class." << std::endl;
		std::cout << "I caught an User_type error." << std::endl;	

	}catch(...){
		std::cout << "I caught an unknown error." << std::endl;
	}	

	std::cout << "\n** End of program **" << std::endl;
	return 0;

}
