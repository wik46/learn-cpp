/* ***************************
 * Filename: implementation.h
 * Author: Wikus
 * Date: 5 Sept
 * Desription: This source file contains the headerfile of the implementation of the list.
 * Input: Two different datastructures
 * Output: The difference in time to iterate through the data structure.
 * **************************/

#ifndef IMPLEMENTATION_H
#define IMPLEMENTATION_H

#include <iostream>

// My list will contain the food needed for a braai.

// The list consist of various nodes.
struct Node{
	// Member variables.
	int data;
	// The pointer pointing to the next node.
	Node* next;
	Node(): data(0), next(NULL) {}
};

// The linked list.
class Linked_list{
	// A pointer to the first element in the list.
	Node* head;
	// The initial size of the list.
	int m_size;
public:
// The constructor.
	Linked_list(int size);
// The Destructor.
	~Linked_list();
// This fills the list	
	void fill_list();
// This function totals the entire list
	int total_sum();
// This prints the list.
 	void print();
private:
// This creates the list of specified size.
	void create();
// This is used in the destructor and frees up all the memory.	
	void delete_();

};

#endif
