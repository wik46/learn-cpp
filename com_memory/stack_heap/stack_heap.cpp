/***************************************
 *Program Filename: stack_heap.cpp
 *Author: Wikus
 *Date: 17 July 2020
 *Description: learing stack vs heap memory allocation
 *Input:
 *Output:
 ***************************************/

#include <iostream>

struct Vector3{

	float x, y, z;
	   Vector3() 
	   	: x(10), y(112), z(15) {}

};

// Dynamically allocated variables acts exactly the same as local variables when declared inside the scope of the function
// The pointer is deleted like a normal local variable when it exits the scope.
// Therefore that memory address is deleted and we cannot delete the heap allocated value, because we dont know
// what is its addres. This leads to a memory leak.


int main(){

	//Stack allocation of an integer in  memory
	int value = 5;
	
	std::cout << "Memory address of value: " << &value << std::endl;
	//Stack allocation of an integer array in memory
	double array[5];
	//This for loops puts integers in my array
	for(int i = 0; i < 5; i++){
		array[i] = (double)i + 1;
		std::cout << "Memory between doubles in my array: " << &array[i] << std::endl;
	}

	//Stack allocation to creat the struct
	Vector3 vector1;

	//Heap allocation of memory
	
	//integer primitive data type
	int* hvalue = new int;
	//You need to defrence the variable with rhe * in front the save memory into it
	*hvalue = 5;    

	//Heap allocation of an array
	int* harray = new int[5];
	for(int i = 0 ; i < 5; i++){
		hvalue[i] = i + 1;
		// Note that an integer is 4 bytes of data so the difference in the memory is 4 (in heksadecimal)
		std::cout << "Memory of hvalue[i]: " << &hvalue[i] << std::endl;
	}	
	
	//Heap allocation to create a struct
	Vector3* hvector = new Vector3();

	//After stack allocation you need to delete 
	delete hvalue;
	delete[] harray;
	delete hvector;

//==================
//Dynamic Allocation
//==================

	// This array is to big to be allocated on the stack
	//int big_array[1000000000];
	int* ptr = new int;
	*ptr = 7;
	std::cout << *ptr << std::endl;
	delete ptr;
	// This is undefined behaviour. I cannot dereferenc a dangling pointer (a pointer that is not pointing to an address)
	std::cout << *ptr << std::endl;
	
	// This will lead to a sagementation fault, because I cant delete the same memory twice
	//delete ptr; 

	// Deallocating memory can lead to multiple dangling pointers
	int* ptr_1 = new int;
	int* ptr_2 = ptr_1;
	// Bothe prt_1 and ptr_2 is pointing to the same memory ADDRESS
	*ptr_1 = 10;
	
	delete ptr_2; // This is returning the memory address to the operating system
	// Both these pointer as dangling pointers. This is undefined behavior
	
	// std::cout << "ptr_1 and ptr_2: " << *ptr_1<< " and "<< *ptr_2 << std::endl; 
//=================
// Memory leaks
//================

	//1. Pointer out of scope
	
	//2. Changinf the address of a pointer pointing to heap allocated memory
	int* heap_pointer = new int;
	int a = 10;
	// heap_pointer = &a; // this will result in losing of the memory address where my heap allocated memory is stored
	int* p_pointer = &a;
	
	delete heap_pointer;
	
	// 3. Memory leak via double allocation
	int* double_ptr = new int;
	int* double_ptr1 = new int; // Now I have to heap allocated integers but only the address of the last one created
	
	return 0;
}
