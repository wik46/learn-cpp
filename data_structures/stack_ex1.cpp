/* ***********************************************************************
 * File name: stack_ex1.cpp
 * Author: Wikus.
 * Date: Sept 12, 2020.
 * Description: This is a basic implementation of a stack data structure.
 *              The resource is from "simple snipptes" on Youtube.
 * Input: The size of the stack.
 * Output: A stack with functionality provided. 
 * ***********************************************************************/

// A Stack is a linear, fixed sized data structure that uses implemeted by the
//  FILO (first in last out) or LIFO (last in first out) operation.

// Standard functionality of a stack. (8)
//
// 1. push(): Add an element to the top most position on the stack.
// 2. pop(): Returns and remove the top most element on the stack.
// 3. isFull(): If number of elements = stack size, return true. (overflow state)
// 4. isEmpty(): If there are no elements in the stack, return true. (underflow state)
// 5. count(): The number of elements in the stack.
// 6. change(): Change the value at the i'th position.
// 7. peak(): Returns the value at the i'th position.
// 8. display(): Displays the entire stack. Note that the indices need to be displayed in descending order.
//

#include <assert.h>
#include <iostream>

class Stack{
private: 
	// The array where my data will be stored.
	int* m_data_arr;
	// The user specifies the size of the stack.
	int m_size;
	// This variable will keep track of the index of the
	//  top most element in the stack.
	// m_top is initialized to -1. If we add one element to the stack we add 1 to top.
	// m_top represents the index of the top of the stack.
	int m_top;

public:
	// The constructor.
	//
	Stack (int size = 10)
	: m_size(size), m_top(-1)
	{
		// The data inserted into the stack will be stored in the array.
		create_ar(m_size);
	}
	
	// The destructor.
	// The only funtion handled by the contructor is to free dynamic memory.
	~Stack ()
	{
		delete_ar();
	}
// Functionality of my stack.
	
	// Returns true if the stack is in overflow state.
	bool isFull(){
		if(m_size == m_top + 1){
			std::cout << "stack overflow" << std::endl;
			return 1;
		}else{
			return 0;
		}
	}
	// Returns true if the stack is in underflow state.
	bool isEmpty(){
		if(m_top == -1){
			return 1;
		}else{
			return 0;
		}
	}
	// Adds an element to the top most position of the stack, if the
	// 	stack is not in overflow state.
	void push(int data){
		std::cout << "Push function used." << std::endl;
		if(isFull()){
			std::cout << "stack overflow" << std::endl;
		}else{
			// The index was at the previous top of the stack
			// 	 before we incremented it.
			m_top++;	
			m_data_arr[m_top] = data;
			std::cout << "The value added to the stack: " << m_data_arr[m_top] 
			<< "." << std::endl;
		}
	}
	// Returns and removes the top most element of the stack, if the stack
	// 	is not in underflow state.
	int pop(){
		if(isEmpty()){
			std::cout << "stack underflow" << std::endl;
		}else{
			int tempVal = m_data_arr[m_top]; 
			m_data_arr[m_top] = 0; 
			m_top--;
			return tempVal;
		}
	}
	// Returns the number of elements in the stack.
	int count(){
		// example if m_top = 0, then the #elements in the stack is 1.
		// example if m_top = 3, then the #elements in the stack is 4.
		return m_top + 1;
	}
	// Returns the element in the i'th position.
	// Validates if there is at least one element in the stack.
	int peek(){}

	void change(){}	

	void display(){
		// It will be trivial for the user to display empty data.
		assert(m_top >= -1);
		std::cout << std::endl;
		std::cout << "The current stack." << std::endl;
		// The stack needs to display the indeces in descending order.
		for(int i = m_size - 1; i >= 0; i--){
			std::cout << m_data_arr[i] << std::endl;
		}
		std::cout << std::endl;
	}
public:

private:
	// The create() method is used inside the constructor constructor.
	// Input: The size of the stack.
	// Output: A newly created stack where all the values are set to zero.
	void create_ar(int size){
		// The user may not enter a non-negative size for the stack.	
		assert(size >= 0);
		// Creating an array on the heap so that the user can 
		// specify the size of the stack at runtime.
		m_data_arr = new int[size];
		// Setting the value of each element in the stack to zero.
		for(int i = 0; i < size; i++){
			m_data_arr[i] = 0;
		}
	}
	
	// delete() method will be called from the constructor. It is used to 
	// free the dynamically allocated memory.
	// Input: -
	// Output: Frees the dynamicly allocated memory used by the stack.
	void delete_ar(){
		delete[] m_data_arr;
	}

};

// Testing of the stack.
// =====================

int main(){
	
	Stack s1;
	for(int i = 0; i < 5; i++){
		s1.push(10);
	}
	s1.display();
	for(int i = 0; i < 5; i++){
		s1.pop();
	}
	
	s1.display();

	return 0;
}
