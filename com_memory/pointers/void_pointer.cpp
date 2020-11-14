/*************************************************
 *Program Filename: void_pointer.cpp
 *Author: Wikus
 *Date: 
 *Desription:
 *Input:
 *Output:
 ************************************************/

#include <iostream>
#include <cstdio>
#include <string>

// ==============
// Void Pointers.
// ==============

// a void pointer does not know to which memory it is pointing to therefore it cannot be dereferenced.

// Enumerations can be definde without a name.
enum Color{
	col_1 = 10,
	col_2 = 12,
	col_3,
};

class Strings{
public:
	Strings(std::string my_str = "Default"){

		std::cout << "The constructor: " << my_str << std::endl;
	}

	~Strings(){

		std::cout << "The destructor. " << std::endl;
	}
};

int main(){


	int value = 65;
	std::cout << "Before change: " << value << std::endl; // Notice that I am changing the value wit another variable.
	// Good practise to initialize your void pointer to NULL.
	void* ptr = '\0';
	ptr = &value;
	// Cannot use *ptr becuase the value of the derefernced pointer is void.
	std::cout << "void ptr: " << &ptr << std::endl;

	int* int_ptr = (int*)ptr;
	char* char_ptr = (char*)ptr;

	std::cout << "Value at int_ptr: " << *int_ptr << " and value at char_ptr: " << *char_ptr<< std::endl;
	*char_ptr = 'B';
	std::cout << "after change: " << value << std::endl;

	// Example 2 (not void pointers.)
	Color paint = col_1 ;
	Color ptr_paint[3];

	ptr_paint[0] = col_1;	
	std::cout << *ptr_paint << std::endl;
	// Example 3
	Strings my_str10;		
	

	std::cout << "Last output before return. " << std::endl;
	return 0;
}
