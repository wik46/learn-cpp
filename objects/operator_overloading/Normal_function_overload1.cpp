/* ***************************************************************************************
 * Filename: Normal_function_overload1.cpp
 * Author: Wikus
 * Date: December 6, 2020
 * Description: T
 * **************************************************************************************/
#include <iostream>
// ======================================================================================
// Operator Overloading: Learncpp 9.1 - 9.6
// ======================================================================================
// ===========================
// Ways to overload operators:
// ===========================
// a. Member function: only one operand becuase the other one is the class itself.
// b. Friend function: a function that has access to a classes private members.
// c. Normal function: most of the time pass and return objects by const references.

/* (purpose of this file to study the follwinf type of overloaded operators)*/
// =============================================
// 1. Overloaded Operators as Normal Functions:
// =============================================

// ===========================
// List of operator overloads.
// ===========================
// 1. Mathematical operators (binary): +, -, *, and /.
// 2. Unary operators: !, +, and -.
// 3. Overloaded I/O operators (binary): << and >>.
// 4. Comparison operators (binary): ==, !=, >, =>, <, and <=.
// 5. Increment, decrement: pre and post fix: x++, ++x, x--, and --x. 
// 6.
// 7. The subscript operator: []
// 8. The parenthesis operator: ()



// The class used for the example.
/*
 	This class will represent a dollar.
 */ 
class Dollar{
	// Member 1: This will be the member that store the value of the dollar.
	float m_value;
public:
	// Member 1: This will be used to get access to the value of the dollar.
	const float get_value() const { return m_value;}
	// Constructor:
	Dollar(float val = 0): m_value{val} {}

};
// 1. Overloaded Operators as Normal Functions:
/* Defining overloaded mathematical operators to work with my dollar class.*/

// a. Overloading the addition operator.
//    Remember that this function will only work when my custom object is on the left of the double.
/* Note this returns by value because we want to copy and not return a locally
   created object */
Dollar operator+(const Dollar& d, float val){
	return Dollar{d.get_value() + val}; // Returns the new Dollar value.
}


// This process works exactly the same for operator-(), operator*(), operator/().
// * Note with operator/(): You can ad code to protect the user from division by zero.
int main(){
	
	// 1. Creating a Dollar intance.
	Dollar my_dollar{9.99};
	std::cout << "Current dollar value $: " << my_dollar.get_value() << std::endl;
	float result = 0;
	std::cout << "How much would you like to add to your dollar count?: ";
	std::cin >> result;
	// Note that this uses the defualt assignment operator provided by the compiler for the class Dollar.
	Dollar new_dollar = my_dollar + result; /* Note that I have not defined an operator+() for my Dollar
							instance on the right hand side, therefore it will only
							work if the Dollar instance is on the left hand side. */
	// 2. Printing out the new result of the float.
	std::cout << "Your new dollar value is $: " << new_dollar.get_value() << std::endl;

}
