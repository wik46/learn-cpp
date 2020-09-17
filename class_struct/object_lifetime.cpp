 /**************************************************
 *Program Filename: object_lifetime.cpp
 *Author: Wikus
 *Date: 18 July 2020
 *Description: Learing the difference between static variables and when they go out of scope.
 *Input
 *Output
 **************************************************/


#include <iostream> //Remember all that the #inlcude statement does is copy and paiste

struct Node{
	
	// My data is 8 bit strings.
	
	const char* m_data;
	// This pointer will be used later
	Node* m_next;
	// The constructor.
	Node(const char* data = "default"): m_data(data)
	{
		std::cout << "Node created" << std::endl;
	}
	// Destructor.
	~Node(){
		std::cout << "Node deleted" << std::endl;
	}
};

class Stack_Object{

	Node* my_ptr;
	int m_value;
	
public:
	// The constructor.
	Stack_Object(int val = 0): my_ptr(NULL), m_value(val)
	{
		std::cout << "Stack object created." << std::endl;
		create_array(&my_ptr);
	}
	// My destrucor.
	~Stack_Object(){
		delete_array(&my_ptr);
		std::cout << "Stack_Object deleted." << std::endl;
		std::cout << "Stack_Object value: " << m_value << std::endl;
	}
	// This function is to get the value of a private member.
	int getval(){
		return m_value;
	}
	// This is to set the value for a private class member.
	void setval(int val){
		m_value = val;	
	}
	
private:
	// The function used inside my constructor.
	void create_array(Node** ptr){
		*ptr = new Node[1];
	}
	void delete_array(Node** ptr){
		// Notice what is happening here.
		// 	-firstly I am passing the address of my Node ptr.
		// 	My ptr is pointing to an array of nodes. That is why I use delete[].
		// 	-Then I dereference the pointer of type Node** to access the variable of type Node*
		// 		where the dynamic memory was allocated.	
		delete[] *ptr;
		std::cout << "array deleted" << std::endl;
	}
};


int main(){
	
	Stack_Object* scope_ptr;
	{
		Stack_Object scope_ob(10);
		scope_ptr = &scope_ob;
		// Note that larger_scope is intantiated before smaller_scope
		//Node larger_scope;
		{
			Stack_Object smaller_scope(20);
		}
		// This is valid because the Node that node_ptr is pointing
		// 	to was created in the scope.	
		std::cout << scope_ptr->getval() << std::endl;
	}
	// This is invalid because scope_ob has gone out of scope and the memory
	// 	has been freed.
	//
		scope_ptr->setval(12);
		std::cout << scope_ptr->getval() << std::endl;
	// The above code will compile but this is undefined behaviour.
		
	std::cout << std::endl;	
	std::cout << "==================" << std::endl;
	std::cout << "between two scopes" << std::endl;
	std::cout << "==================" << std::endl;	
	std::cout << std::endl;
	{
		std::cout << "=========================" << std::endl;
		std::cout << "Enterance of second stack" << std::endl;
		std::cout << "=========================" << std::endl;
		Node Second_scope;	
	}
	std::cout << "=========================" << std::endl;
	std::cout << "Back in the main function" << std::endl;
	std::cout << "=========================" << std::endl;
	
	return 0;
}
