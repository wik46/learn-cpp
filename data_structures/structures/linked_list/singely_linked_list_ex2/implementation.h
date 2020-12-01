/*
 *	Filename: implementation.h
 * 	Author: Wikus
 * 	Date: August 26, 2020.
 * 	This is all the function prototypes for my singely linked list.
 */

#ifndef IMPLEMENTATION_H
#define IMPLEMENTATION_H

#include <iostream>

struct Node{
	// This struct contains the data that my singely link list holds.
	int m_data;
	// This points to the next elemetent in the list.
	Node* next;
	// This points to the second elements in the list when I implement the dubblely linked list.
	Node* prev;
	// This constructor is used to insert data.
	Node(int value = 0): m_data(value)
	{}
		
};

class LinkedList {
	// The member variables.
	Node m_node;
	Node* m_head; // This is a pointer to the first element in the list.
	int m_length;
	std::string m_name; // This is the name of the list.

public:
	// The default constructor.
	LinkedList(std::string name = "default");

	// The destructor.
	~LinkedList();
	
	// Insert head
	// This is to insert data into the first node.
	void insert_head(int data);

	// To insert a node in a specific position in the list.
	void insert_position(int data, int pos);

	// Insert tail.
	// Insert an element into the tail of my list.
	void insert_tail(int data);

	// This is to print the contents of the list.
	void print();

	// This is to get the length of my list.
	std::string GetName();

private:
	// This function deletes the entire list.
	// It is used by the destructor.
	void delete_entire();
};

#endif
