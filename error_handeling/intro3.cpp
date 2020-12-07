/* ***************************************************************************************
 * Author: Wikus Jansen van Rensburg
 * Date: December 7, 2020.
 * Description: This program is used to show the timing of catch blocks
 * 		and how they are used with construction and destruction of objects.
 * Learning Resource: 
 * 		https://www.geeksforgeeks.org/c-exception-handling-question-1/?ref=rp
 * **************************************************************************************/
#include <iostream>

// ============================================
// Using try blocks alongside objects: classes.
// ============================================


/*
	This is a basic class just to show what happens with objects when
	throw statements are executed. 
*/
/*  Side note: You cannot throw just and empty exeption, but you can throw an empty
	exception inside a nested try/ catch blocks. 
*/

// First class.
class Object1{
	// This is only so that I can give eacj objects a unique name.
	std::string m_name;
public:
	// This is a accessor the get the name of the object caught.
	std::string get_name() const{ return m_name;}
	// A constructor that is used to see when my object is constructed.
	Object1(std::string name = "default_name"): m_name{name}
	{
		std::cout << "[Object1]: constructor called." << std::endl;
		std::cout << "\t(with name: " << m_name << " )\n" << std::endl;
	}
	// This constructor is used to see when my object is destructed.
	~Object1(){
		std::cout << "[Object1]: destructor called." << std::endl;
		std::cout << "\t(with name: " << m_name << " )\n" << std::endl;
	}
};
	
int main(){
	std::cout << "\n=========================" << std::endl;
	// This object it used as one to be thrown around.
	// Remember that a try block also have local scope.
	Object1 obj_throw("object_outside");
	// --------------------------------------------------------------------
	// Example 1: When object is created on the stack inside the try block.
	// --------------------------------------------------------------------
	std::cout << "\n=========================" << std::endl;
	try{
		std::cout << "** Inside example 1 try block: Creating static object **"<< std::endl;
		// Note that since this object was created inside this try block, it will
		// go out of scope at the end of the try block.
		Object1 obj("object_inside");
		throw &obj_throw;
	// Note that you can throw anything. Since I dont want to copy an object, I throw
	// 	its pointer. Usually with objects, you will catch by const reference to
	// 	the object.
	}catch(Object1* p){
		std::cout << "Caught the object: " << p->get_name() << std::endl;
	}
	// -----------
	// Example 2:
	// -----------
	std::cout << "\n=========================" << std::endl;
	Object1* obj_ptr = NULL;
	try{
		std::cout << "** Inside example 2 try block: Creating dynamic dynamic object **"<< std::endl;
		obj_ptr = new Object1("heap_object");
		throw obj_throw;
	// Here I am catching the object by const reference to avoid a copy being made.
	// I do not know why the destructor is called twice on the obkect defined initially.
	}catch(const Object1& p){
		std::cout << "Caught the object: " << p.get_name() << std::endl;
	}

	// This object was created in the example 2 try block.
	delete obj_ptr;	
	return 0;
}
