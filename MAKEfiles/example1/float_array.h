// This file contains the definition of my float array.

#ifndef FLOAT_ARRAY_H
#define FLOAT_ARRAY_H

class float_array{
	float* m_head;
	int m_size;
public:
	// The constructor creates the array on the heap.
	float_array(int size);
	// The destructor deletes the array that is allocated on
	// 	the heap.
	~float_array();

	// This function is to get access to the float array.
	float* get_float_array();
	// To get access to the length of the array. 
	int get_length();

};

#endif
