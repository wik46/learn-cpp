/*
 * Filename: float_array.cpp
 * Author: Wikus
 * Decription: Implementation file for the array of floating point numbers.
 */
#include <iostream>	
#include "float_array.h"
// The constructor.
float_array::float_array(int size): m_size(size)
{
	// The constructor creates my floating point number array and intializes each element in
	// 	the array to a value dependant on i.
	std::cout << "Created array of size: "<< m_size << std::endl;
	m_head = new float[m_size];
	for(int i = 0; i < m_size; i++){
		m_head[i] = (float)i;
	}
}

// The destructor.
// Free's the dynamically allocated memory.
float_array::~float_array(){
	delete[] m_head;
}

// This function is to get access to the array.
float* float_array::get_float_array(){
		return m_head;
}
// To get access to the length of the array. 
int float_array::get_length(){
		return m_size;
}

