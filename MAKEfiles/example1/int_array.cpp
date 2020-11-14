/*
 * Filename: int_array.cpp
 * Author: Wikus
 * Decription: Implementation file for the array of integers.
 */

#include <iostream>
#include "int_array.h"	
// The constructor.
int_array::int_array(int size): m_size(size)
{
	// The constructor creates my intger array and intializes each element in
	// 	the array to a value dependant on i.
	std::cout << "Created array of size: "<< m_size << std::endl;
	m_head = new int[m_size];
	for(int i = 0; i < m_size; i++){
		(m_head[i]) = i;
	}
}

// The destructor.
int_array::~int_array(){
	delete[] m_head;
}

// This function is to get access to the array.
int* int_array::get_int_array(){
		return m_head;
}

// To get access to the length of the array. 
int int_array::get_length(){
		return m_size;
}

