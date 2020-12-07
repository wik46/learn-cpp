/* ***************************************************************************************
 * File name: stack_unwinding.cpp
 * Author: Wikus.
 * Date: November 11, 2020.
 * Description: This is program where I used the std::exception class to derive my own
 * 		exception classes.
 * Type: Using the standard exception class inside the C++ standard template library.
 * Learning resource: Learncpp 14.5
 * **************************************************************************************/

// =======================================================================================
// This program shows how to derive custom exception classes from the std::exception class.
// =======================================================================================

/*
 * The standard template library in C++ provides an exception class to use.
 * Many of the operators in the STL throws errors of classes all derived from
 * std::exception. Therefor is you catch the type std::exception& you will
 * catch all the errors thrown by STL operators.
 * */

#include <iostream>
#include <string>
#include <exception>

class MathError: public std::exception
{
	std::string m_error;
	double m_error_num;
public:
	// The class constructor.
	MathError(const char* error, double num)
	:m_error(error), m_error_num(num)
	{}
	// This is a member function to tell me what I need to do.
	// NB! This is overriden from the std::exception class so the 
	// 	function prototype must be identitcal
	const char* what() const throw() /*noexcept*/{
		std::cout << "Number that cause exception: " << m_error_num << std::endl;
		return m_error.c_str();
	}
	// THIS is needed because we derive from std::exception
	virtual ~MathError() throw(){}
};
// Always need a body for a virtual destructor.


// This function divides to numbers.
double divide(double numerator, double denominator ){
	if(denominator == 0.0){
		throw MathError("Division by zero is undefined", denominator);
	}
	return numerator/denominator;
}
// This function returns the square root but you cant square a negative number.
double sqrt(double num){
	if(num < 0.0){
		throw MathError("You cannot take the square root of a negtive number",num);
	}
	return num * 0.5;
}

int main(){
	double num = 0.0, den = 0.0;
	
	std::cout << "Numerator: ";
	std::cin >> num;
	std::cout << "Denominator: ";
	std::cin >> den;
	try{
		std::cout << "Result from division: " << divide(num, den) << std::endl;		
		std::cout << "Result from square root: " << sqrt(num) << std::endl;
	}catch(const std::exception& e){
		std::cout << std::endl << "Enter std::exception catch block." << std::endl;

		std::cout << "Standard exception: " << e.what() << std::endl;
	}catch(...){
		std::cout << "Catch all exception executed." << std::endl;
	}

	return 0;
}


