/* ***************************************************************************************
 * Filename: Friend_function_overload1.cpp
 * Author: Wikus
 * Date: December 6, 2020
 * Description: This shows used how to use friend functions of a class.
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
// 1. Overloaded Operators as Friend Functions:
// =============================================

/*
 	A friend function is just a normal function with one extra super power.
		* That is it has access to its 'friends' private, protected and public
		* member variables and member functions.
		* By friend we mean the class that it is a friend of.
	2. How to make a normal function a friend?
		1. Define the function just like any other function.	
		2. Add the function prototype inside the definition of the class 
			and prefix the prototype with the 'friend' keywoard.
*/
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
	// This function is defined above main.
	// This is only a friend function and not a member funtion.
	friend std::ostream& operator<<(std::ostream&, const Dollar&);
};

// Function from previous example.
Dollar operator+(const Dollar& d, float val);
// This process works exactly the same for operator-(), operator*(), operator/().
// * Note with operator/(): You can ad code to protect the user from division by zero.
// =================
// NOW!!!: 
// ================
/*
	The problem with the previouse code was that we need to define a member function
	each time that we want to print the value of the dollar to the screen. But it would make
	sense if we can just use an instance of a dollar like and int or a float to ouput and
	input values to the screen and accept user input respectively. 
	But we can !!!.
	We define them only as friend functions because then we dont have to create accessors and
	specifiers as well.
*/ 

// The prototype of the function is inside the definition of the class below.
// A friend function is not a member of a class therefore we do not need the scope
// 	resolution operator.
// 1. This function must take the std::ostream object as the left operand and our class on the
// 	right operand. Furthemore, C++ does not allow us to copy stream objects (example std::ostream).
// 	Therefore we need to pass the std::ostream object back as reference to the caller.

std::ostream& operator<<( std::ostream& stream_out, const Dollar& d){
	// 1. This is a friend function so we have access to m_value directly.
	//    m_value is of type 'float' and floats are defined for the << operator.
	stream_out << d.m_value; 
	// 2. NB! You need to return that stream object that you used.
	return stream_out;
}
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
	// I. Old way.
/*	std::cout << "Your new dollar value is $: " << new_dollar.get_value() << std::endl; */
	// II. New way. This makes much more sense and is easier to use.
	std::cout << "Your new dollar value is $: " << new_dollar << std::endl;

}

/* ****************************************************************************************
 * Function name: operator+()
 * Defined in the first example.
 * Description Follows:
 * 	1. Overloaded Operators as Normal Functions:
 * 	Defining overloaded mathematical operators to work with my dollar class.x
 *
 * 	a. Overloading the addition operator.
 * 	   Remember that this function will only work when my custom object is on the left of the double.
 * 	Note this returns by value because we want to copy and not return a locally
 * 	  created object 
 * ***************************************************************************************/
Dollar operator+(const Dollar& d, float val){
	return Dollar{d.get_value() + val}; // Returns the new Dollar value.
}

