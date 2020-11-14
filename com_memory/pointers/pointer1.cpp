/*************************************************
 *Program Filename: pointers1.cpp
 *Author: Wikus
 *Date: 13 June 2020
 *Desription: Learning pointers from the one lonely coder
 *Input:
 *Output:
 ************************************************/

//=========================
//Resource is wikibooks c++
//==========================


#include <iostream>
#include <cstdio>
#include <string>


int main(){
	
	//Think of each char as an element of the array.	
	char name[] = "123456789";
	char* pointer_char = &name[3]; // We are pointint to the 4 element
	std::cout << pointer_char << " and  " << sizeof(name) << std::endl;
	
	//defining int pointers
	int i = 5;
	int* point = &i;
	std::cout << *point << std::endl;
	i = 3;
	std::cout << *point <<std::endl;
	
	//Defining string pointers
	std::string array1[] = {"wikus","monica", "mamma"};
	std::string* str = &array1[1];
	//Printing the second element in my array
	std::cout << array1[0] << std::endl;
	//Printing my pointer and using the dereferencing operator
	std::cout << *str << std::endl;
#if 0

	int some_array[10] = {3,6,9,12,15,18,21,24,27,30}; 

	int* array_p = &some_array[0];
	int* location_6 = &some_array[6];
	int* location_0 = &some_array[0];

	// Some pointer arithmetic.
	// The adding an integer each time will add 4 place in memory because an integer is 4 bytes
	for(int i = 0 ; i < 10 ; i++){
		std::cout << i  <<"th iteration of the loop" << std::endl;
		std::cout << array_p + i << " = "<< *(array_p + i) << std::endl;	
		std::cout << "Memory i: " << &i << std::endl;
	}
	std::cout << "============" << std::endl;
	for(int i = 0; i < 10; i++){
		std::cout << location_0 <<  std::endl;
		location_0++;
	}
#if
	std::cout << "Location 6: " << location_6 << std::endl;
	std::cout << "Location 0: " << location_0 << std::endl;
	std::cout << "Difference: " << location_6 - location_0 << std::endl;

	int a = 10;
	int* i_pointer = &a;       // & - Get the address of a
	int value_at = *i_pointer; // * - Get value at the address	
	
	std::cout << "Value of a: " << a << std::endl;
	std::cout << "Memory address of a: " << i_pointer << std::endl; 


#endif	std::cout << "Value at the memory address stored in i_pointer: " << value_at << std::endl;
#endif
	return 0;
}
