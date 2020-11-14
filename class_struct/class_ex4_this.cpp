 /**************************************************
 *Program Filename: class_ex4_this.cpp
 *Author: Wikus
 *Date: 18 Aug 2020
 *Description: Learning how to use th create a log function to print types of errors
 *Input
 *Output
 **************************************************/


#include <iostream> //Remember all that the #inlcude statement does is copy and paiste

// this - is a pointer to the object that your member function is working on.
// ===================
// When I write code like number.add(5); - what the compiler actually does is add(&number,5);
//

// this is used by the std::cout and << operators.
// std::cout << "Hello" << name << std::endl;
// 	What actually happens: (std::cout << "Hello") << name << std::endl;
// 	Then 			(std::cout << name ) << std::endl; 
//  	Lastly  		(std::cout << std::endl;)
// 	The object std::cout is returned in order to print out the next stream of bits.

class Calculator{
private:
	int m_value;
public:
	Calculator(int number = 0)
	:m_value(number)
	{

	}
	// This is actually what is happening.
	// Calculator(const Calculator* this, int number)
	// {
	//	std::cout << this->m_value << std::endl;	
	// }

	// I can return the object in order to chain multiple functions.
	Calculator& add(int number){
		std::cout << "I added: " << number << " to " << this->m_value << "." << std::endl;
		m_value += number;
		// I am returning a reference to the object I am working with.
		return *this;
	}
	// Second function in the chain.
	Calculator& subtract(int number){
		std::cout << "I subtracted: " <<  number << " from " << this->m_value << "." << std::endl;
		m_value -= number;
		return *this;
	}
	// Third function in the chain.
	Calculator& multiply(int number){
		std::cout << "I multiplied: " << this->m_value<< " by " << number << "." << std::endl;
		m_value *= number;	
		return *this;
	}
	// This is to print the result.
	Calculator& print(){
			// this->m_value is waht actually happens.
			// But C++ does it implicitly for us.
		std::cout << "The value is: " << this->m_value << "." << std::endl;
		return *this; // I want to use print in the chain.
	}

};

int main(){
	
	Calculator example(0);
	// The first print is called and the function returns a reference to example.
	// Then example.add(5) is called an return a reference to example.
	// Then example.print() is called and return a reference to example.
	// And so on ...
	example.print().add(5).print().subtract(10).print().multiply(4).print();

	return 0;
}
