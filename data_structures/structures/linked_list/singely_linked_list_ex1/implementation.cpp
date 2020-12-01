/*
 * File name: implementation.cpp
 * Author: Wikus
 * Description: This is the implementation of the methods
 * 		used to create/delete nodes for my linked lists.
 *
 *
 * */

#include "interface.h"

// Take in data d and insert it at the head if the list.
void LinkedList::insert_head(int d){
	// new_node is pointer to the node that contains the data d. 
	Node* new_node = new Node(d);
	// The first node address is currently stored in head.
	// next now points to the second node.
	new_node->next = head; 
	// head is now pointing to the new node inserted.
	head = new_node;
	// Recap:
	// next is the pointer in the struct.
	// new_node is the new node inserted.
	// After execution, the head know points to the address of the first node new_node.

	std::cout << "The new head that was inserted: " << new_node->data << std::endl; 
	print_list();
}

// Take data d and insert it into the position pos.
void LinkedList::insert_position(int d, int pos){
	// new_node is a pointer of type Node*.
	Node* new_node = new Node(d);
	
	if(head == NULL){
		// To see if the user wants to do a head insertion.
		if(pos == 0){
			// I am pushing the head pointer one step further
			new_node->next = head;
			// The new head is pointing to the new data inserted.
			head = new_node;
		// Invalid operation because you cannot insert a non-header node into an empty list.
		}else{
			assert(head == NULL && pos == 0);
		}
	}else{	
		Node* temp = head;
		Node* prev = NULL;
		// This loop will walk down the list.
		// I need to get to the position that I want to place the data.
		for(int i = 0; i < pos; i++){
			// The trailing one.
			prev = temp;
			// The next block.
			temp = temp->next;
		}
		if(prev == NULL){
			// This means that we did not enter the loop.
			// Therefore the user must have entered 
			new_node->next = head;
			head = new_node;
		}else{
			new_node->next = prev->next;
			prev->next = new_node;
		
		}
	}

	std::cout << "The following data: " << new_node->data << " was inserted at position " << pos << std::endl;
	print_list();

}


void LinkedList::print_list(){
	std::cout << "[print_list() entered.]" << std::endl;
	Node* temp = head;
	// The function will stop printing when I reach my termination node.
	while(temp != NULL){
		std::cout << temp->data << " | "; 
		temp = temp->next;
	}

	std::cout << std::endl;
}
