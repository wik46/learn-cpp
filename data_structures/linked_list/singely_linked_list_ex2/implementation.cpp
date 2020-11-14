/*
 * 	Filename: implementation.cpp
 * 	Author: Wikus
 * 	Description: This is the implementation of the singely linked list.
 *
 * */
#include "implementation.h"

#include <assert.h>
#include <iostream>

// The default constructor.
LinkedList::LinkedList(std::string name)
:m_head(NULL), m_length(0), m_name(name) // I am instationing the head of my list to NULL to represent the empty list. 
{
	std::cout << "List created with no elements." << std::endl;
}


// The destrutor.
LinkedList::~LinkedList(){
	delete_entire();	
}

// The insert head function.
void  LinkedList::insert_head(int data){
	assert(m_head == NULL); // This is to make sure that the list is empty
	std::cout << "head_insert" << std::endl;
	Node* temp = new Node(data);
	temp->next = m_head;
	m_head = temp;
	
	// Increase the lenth of the list by one.
	m_length++;
}

// The insert postions function.
// Lets me insert data into the list at a specific position.
void LinkedList::insert_position(int data, int pos){
	// To make sure the the function gets called on a valid position.
	assert(pos >= 0 && pos <= m_length);
	// In the case of head insertion.
	if(pos == 0){
		Node* temp = new Node(data);
		temp->next = m_head;
		m_head = temp;
	
		// Increase the lenth of the list by one.
		m_length++;	
	}else{
		// The case when I have an empty list but the user wants to insert a node at
		// 	position n > 0;
		assert(m_head != NULL);
		// These two new pointers will help me assign the correct next and previous pointer
		// 	to the new node.
		Node* temp = m_head;
		Node* prev = temp;
		// This loop lets me walk to the correct nodes.
		for(int i = 0; i < pos; i++){
			prev = temp;
			temp = temp->next;
		}
		// Assing the new data in the correct position.
		prev->next = new Node(data);
		// This is so that the new node points to the pos+1 node in the list.
		(prev->next)->next = temp;
		// To add the length of my list.
		m_length++;					
	}
}

// This function is print the contents of the list.
void LinkedList::print(){
	Node* temp = m_head;
	while(temp != NULL){	
		std::cout << temp->m_data << ", ";
		temp = temp->next;
	}
	std::cout << std::endl;
}

// This function deletes the entire linked list.
void LinkedList::delete_entire(){
	std::cout << "[delete_entire]" << std::endl;
	Node* temp = m_head;
	while(temp != NULL){
		Node* helper = temp;
		temp = temp->next;
		delete helper;
	}	
	std::cout <<  m_name << " was list deleted." << std::endl;
}
