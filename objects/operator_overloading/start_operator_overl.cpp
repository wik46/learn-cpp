/*
 * Filename: start_overl.cpp
 * Author: Wikus
 * Date: November 1, 2020
 * Description: This is a summary of the different ways to overload operators. 
 * ***************************************************************************/
#include <iostream>


// ======================================================================================
// Operator Overloading: Learncpp 9.1 - 9.6
// ======================================================================================

/*
	Consider the following.
	int x = 0, y = 0;
	std::cout << x + y << std::endl;  
 	
	1. Firstly, you should think of an operator as a function:
		- Instead of seeing 'x + y', what actually happens is operator+(x,y)
		- This function returns a integer, lets call it z.
	2. Now we have:
		* std::cout << z << std::endl;
 		- The stream operator is also a function.
		- Instead of seeing ' std::cout << z ', what actually is happens is
		  operator<<( std::cout, z).
		- This function returns an object of type std::stream, the one you passed in. 
	3. Then we have:
		* std::cout << std::endl;
		Now what actually happens is operator<<( std::cout, std::endl)
		This function also takes in a reference to an std::ostream object and returns
		that std::stream object at the end of the function.
	** These above mentioned overloaded operators are all defined with the types used in 
	   the example. That is integers and std::ostream object.

	The usefulness with overloaded operators is when we can use them on our own custom data types.
	Lets say that you create a type 'Vector_2d' that is the mathematical object, a two dimensional
	vector. Without operator overloading, you will need to pass in each component to a function
	that knows how to output the vector to the console or the screen. 
	
	** Solution: You can overload the 'operator<<()' to print out the vector as you see fit.
	** Take caution: Only define overloaded operators in away that it makes sense to use.
	** If another person uses your class and needs to see the implementation of the overloaded
		operator, then you did not used it correctly.


*/

// =========
// Rules:
// =========
/*
	1. You cannot create new operators to overload and you can only use
	   operators that exist.
	2. You cannot change the order of operations of the operators.
		* All operators keep there precedence and associativity.
	3. At least one operand in the operator must be a user defined type.
	   - You cannot overload the operator to work with a double and a float, 
		for example.  
	4. It is not possible to change the number operations that a operator
	   supports.
	
*/ 


// =========
// Note:
// =========
// 1. You cannot overload the operator '.', '::', and ':?'.
// 2. You cannot change the number of parameters used by the function

// ===========================
// Ways to overload operators:
// ===========================
// a. Member function: only one operand becuase the other one is the class itself.
// b. Friend function: a function that has access to a classes private members.
// c. Normal function: most of the time pass and return objects by const references.

// ===========================
// List of operator overloads.
// ===========================
// 1. Mathematical operators (binary): +, -, *, and /.
// 2. Unary operators: !, +, and -.
// 3. Overloaded I/O operators: << and >>.
// 4. Comparison operators: ==, !=, >, =>, <, and <=.
// 5. 
// 6.
// 7.
// 8. The subscript operator: []
//

// Prints information of how to use the directory to the user.
void how_to_use();
// Start of the main program.
// This file should only be used as a reference to the rest of the directory.
int main(){
	how_to_use();
	return 0;
}

// This function is only defined to inform the user of the directory 
//  on how to use it and the sequence in which to follow the tutorials.

void how_to_use(){
	std::cout << "\n\n=======================================" << std::endl
	<< "Operator Overloading C++:" << std::endl
	<< "=======================================\n" << std::endl
	<< "1.) Open the start_operator_overl.cpp" << std::endl
	<< "2.) Go through the files in the followin sequence:"<< std::endl
	<< "2.a)  "<< std::endl
	<< "2.b)  "<< std::endl
	<< "2.c)  \n\n"<< std::endl;
	return;
}
