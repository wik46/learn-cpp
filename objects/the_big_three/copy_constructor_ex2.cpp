/*
 * Author: Wikus
 * Description: This is written to study how the copy constructor works.
 * Learning Resources: Learn cpp 9.11.
 * */

#include <cassert>
#include <iostream>

// 1. Direct initializing. "int x(6);" or "Fraction frac1(2,3)"
// 2. Uniform initializing. "int x{6}" or "Fraction frac1{2,3}"
// 3. Copy initializing. "int x = 6;" or "Fraction frac1 = Fraction(3,2)"


class Fraction{
	int m_numerator;
	int m_denominator;
public:
	// Default Constructor.
	Fraction(int numerator = 0, int denominator = 1):
	m_numerator(numerator), m_denominator(denominator) 
	{
		assert(denominator != 0);
	}
	// The compiler provides a defaul copy constructor.
	// But we can also explicityly declare one.
	// Note: if you want to disable the copy default copy constructor, you can explicitly
	// declare one and make theic access private. The user of the class wil no be able to user it.
	Fraction(const Fraction& fraction):
	// Although these member are private, we are working with instances of the same class.
	// Therefore we have access to private members in the copy constructor.
	m_numerator(fraction.m_numerator), m_denominator(fraction.m_denominator)
	{
		std::cout << "You used the copy constructor made by the"
		<< " programmer." << std::endl;
	}
	// Prints the membors:
	void print(){
		std::cout << "m_numerator: " << m_numerator << std::endl;
		std::cout << "m_denominator: " << m_denominator << std::endl;
	}
};

int main(){
	int x{5};
	Fraction fiveThirds{5,3};
	//fiveThirds.print();
	
	//This is copy intialization of my member variables.
	Fraction twoThirds = Fraction(2,3);
		
	// Here I am passing in an object to the constructor of the same class.
	
	// Note that the copy constructor is not called because the compiler optimizes.
	// Avoid this method of initializing.
	Fraction copy(Fraction(5,3));
	// Elision: The procees where the compiler turns the above statement into the one below
	// for optimization.
	// The statment above is turned into "Fraction copy(5,3);" by the compiler. 

	copy.print();
	twoThirds.print();
	return 0;
}
