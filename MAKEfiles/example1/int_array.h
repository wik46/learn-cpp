// The integer array file
// This file contains the declartion of my array.
//
#ifndef INT_ARRAY_H
#define INT_ARRAY_H

class int_array{
	int* m_head;
	int m_size;
public:
	// The constructor.
	int_array(int size);

	// The destructor.
	~int_array();

	// This function is to get access to the array.
	int* get_int_array();
	// To get access to the length of the array. 
	int get_length();
};

#endif
