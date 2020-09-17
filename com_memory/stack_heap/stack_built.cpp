/***************************************
 *Program Filename: stack_built.cpp
 *Author: Wikus
 *Date: August 22, 2020
 *Description: learing stack vs heap memory allocation
 *Input:
 *Output:
 ***************************************/

#include <iostream>
#include <assert.h>

class Stack{
private:
	// The array represent the stack.
	int* dyn_array;
	int current_size;
	int stack_size;
public:
	// Constructor.
	Stack(int size = 10){
		current_size = 0;
		stack_size = size;
		dyn_array = new int[stack_size];	
	}
	// Destructor.
	~Stack(){
		delete[] dyn_array;
	}

	// This is for the user to set the array size to zero.
	// That is the "empty the stack".
	void reset(){
		current_size = 0;
	}
	// This member function allow the user to push data on to the stack.
	void push(int data){
		// The user should not be able to push data on to the stack when the stack is full. 
		assert(current_size != stack_size - 1);
		dyn_array[current_size] = data;
		current_size++;
	}
	// This member function allow the user to pop the top value of the stack.
	// This function should also return the value that is being popped.
	int pop(){
		// The user should not be allowed the pop the stack when it is empty.
		if(current_size <= 0){
			std::cout << "[warning]: stack is already empty." << std::endl;
			return 0;
		}
		current_size--;
		return dyn_array[current_size]; // The current size is being decremented before I return the value.
	}
	// Print the values in the stack.
	void print(){
		std::cout << "The stack.\nCurrent Size: "<< current_size << std::endl;
		std::cout << "(";
		for(int i = 0; i < current_size; i++){
			std::cout << dyn_array[i];
			if(i != current_size - 1){
				std::cout << ", ";
			}
		}
		std::cout << ")" << std::endl;
	}
};

// This is a basic implementation of a stack datastructure.
int main(){

	Stack stack;
	stack.reset();
	stack.print();
	
	stack.push(5);
	stack.push(3);
	stack.push(8);
	stack.print();

	stack.pop();
	stack.print();

	for(int i = 0; i < 2; i++){
		stack.pop();
	}
	stack.print();

	return 0;
}
