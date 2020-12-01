/* ***************************
 * Filename: implementation.cpp
 * Author: Wikus
 * Date: 5 Sept
 * Desription: This source file contains of the implementation of the list.
 * Input: Two different datastructures
 * Output: The difference in time to iterate through the data structure.
 * **************************/

#include "implementation.h"
#include <iostream>
#include <cstdlib>
#include <assert.h>

// The constructor.
Linked_list::Linked_list(int size = 100000)
: head(NULL), m_size(size)
{
	create();
}
// The Destructor.
Linked_list::~Linked_list(){
	delete_();
}
// This fills the list	

// The create function.
void Linked_list::create(){
	srand(time(NULL));
	// This is to create a new list.
	assert(head == NULL);
	Node* temp = head;
	for(int i = 0; i < m_size; i++){
		Node* temp = new Node;	
		temp->data = rand();
		// The new node's next pointer needs to point to where head was pointing.
		temp->next = head;
		// Head is now pointing to the newly inserted node.
		head = temp;
	}
}
// This function sums all the nodes in the list.
int Linked_list::total_sum(){
	
	int sum = 0;
	Node* temp = head;
	// Untill I reach the end of the list.
	while(temp != NULL){
		sum +=	temp->data;
		temp = temp->next;
	}
	return sum;
}

// This function prints the entire list.
void Linked_list::print(){
	Node* temp = head;
	while(temp != NULL){
		std::cout << temp->data << std::endl;
		temp = temp->next;
	}
}

// this function will delete the heap allocated memory.
void Linked_list::delete_(){
	Node* temp = head;
	while(temp != NULL){
	// You cannot delete the memory at temp before know what temp->next is because
	// otherwise you will need to access garbage to get the next node in the list.
		// I am first pointing temp to new memory before freeing it.
		Node* temp_del = temp;
	//	std::cout << "[indside the loop of delete]" << std::endl;
		temp = temp->next;
		delete temp_del;
	}
}
