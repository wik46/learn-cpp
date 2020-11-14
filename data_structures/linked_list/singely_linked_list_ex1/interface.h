/* ***********************************************************
 * File name: interface.h
 * Author: Wikus
 * Date: August, 19, 2020.
 * Decription: This is the interface header file that contains the definition of my
 * 		classes used to create a singely linked list.
 *
 *
 *
 * *********************************************************/

#ifndef INTERFACE_H
#define INTERFACE_H

#include <iostream>
#include <assert.h>
#include <cstddef>


// This is the datatype that will be stored as each node (element) in the list.
// This is a struct because it only contains data and not methods.

// Contains data and a pointer to the next node.
struct Node{
	// The data that I want to store.
	int data;
	// A pointer type Node. This pointer will point to the next node(element) in the list.
	Node* next;
	
	// The constructor.
	Node(int d){
		data = d; // Setting the value of the data.
		next = NULL; // I do not know what memory to point to yet
	}
};


// This class defines our linked list.
class LinkedList{
private:
	// If I have the pointer to the first node in the list I can acces all the other
	// nodes by walking down the list.
	Node* head;
public:
	// Constructor
	// Sets the head to NULL because the list is empty at the start.
	LinkedList(){
		head = NULL;
	}

	// All of these methods need to either insert or delete data
	// and set the pointers accordingly so that the newly linked list is correct.

	// Inserting data.
	// This method is used to insert an node at the head (first node) of the list.
	void insert_head(int d);

	// This method is used to inert any node in a specific position in the list.
	// Add node with data: d in position: pos.
	void insert_position(int d, int p);

	// Add node with data d to the tail of the list.
	void insert_tail(int d);

	// Deleteting data.
	// Delete the data at the head of the tail.
	void delete_head();

	// Delete the data at position p.
	void delete_position(int pos);

	// Delete the data at the tail of the list.
	void delete_tail();

	// Print the list on the screen.
	void print_list();
};


#endif
