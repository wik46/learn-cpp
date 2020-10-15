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
	// This is an accessor:
	int get_numerator(){
		return this->m_numerator;
	}
		
	// This is a mutator:
	void set_numerator(int x){
		this->m_numerator = x;
	}


	// Prints the membors:
	void print(){
		std::cout << "m_numerator: " << m_numerator << std::endl;
		std::cout << "m_denominator: " << m_denominator << std::endl;
	}
};



/*
 * Function name: MakeNeg()
 * Description: This function will take in a Fraction object by value and return a 
 * 		Fraction object by value. Therefore the copy constructor will be
 * */

Fraction MakeNeg(Fraction f) // Ideally you want to pass objects by const reference or ptr.
{
	f.set_numerator(-f.get_numerator());	
	return f;
}
int main(){
	Fraction twoThirds(2,3);
// MakeNeg will copy a Fraction objects twice() and therefore call the copy constructor twice. 
	std::cout << std::endl;	
	MakeNeg(twoThirds);
	std::cout << std::endl;	
	twoThirds.print();
	return 0;
}
