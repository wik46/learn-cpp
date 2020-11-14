/*************************************************
 *Program Filename: pointers1.cpp
 *Author: Wikus
 *Date: 13 June 2020
 *Desription: Learning pointers from the one lonely coder
 *Input:
 *Output:
 ************************************************/

//=========================
// Resource: C++ handboek
//==========================


#include <iostream>
#include <cstdio>
#include <string>

#define size 26


int main(){

	char character1 = 'A';
	char alphabet[size];
	
	for(short int i =0; i < size; i++)
		alphabet[i] = i + 65;	
	// Displaying array
	for(short int i = 0; i < size ;i++)
		std::cout << alphabet[i] << std::endl;
	
	//Pointer to store array size
	int holder = 0;
	int* array_size = &holder;
	std::cout << "Size of your array: ";
	std::cin >> (*array_size);

	//Dynamically creating my array
	std::string* heap_array = new std::string[*array_size];
	
	// Getting value from the user
	
	std::cout << "Enter the class names." << std::endl;
	for(int k = 0; k < *array_size; k++){
	
		std::cout << k  <<"Enter name: ";
		std::cin >> heap_array[k];
	}
	// Returning the array to the user.
	for(int i = *array_size - 1; i >= 0; i--)
		std::cout << *(heap_array + i) << std::endl;
	
	int integer = (int)'A';
	std::cout << "Integer: " << integer << " and char: " << character1 << std::endl;
	
	int* pointer = &(integer);
	delete[] heap_array;	
	
	return 0;
}	
