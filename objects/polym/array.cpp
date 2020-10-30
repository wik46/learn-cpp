// Filename: array.cpp
// Description: This is a program to study how to create and array that
// 		contains different child's derived from a single parent.
//

#include <iostream>

class Base{
protected:
	// Base has one member that is a string.
	std::string m_str;

public:
	std::string get_name(){
		return "Base";
	}
	// The Base class constructor.
	Base(std::string str = "Base class m_string"): m_str{str}
	{
		std::cout << "Base constructed. "<< std::endl;
	}
	// Simple print function for the Base class.
	// When this function is called, it will search for the most derived verion
	// of the object that called it.
	virtual void print(){
		std::cout << "I a Base." << std::endl;
	}
	

};

// This is the first child derived from Base and has an extra int member.
class Child_int: public Base{
	int m_int;
		
public:
	// Construcor.
	Child_int(const std::string& name = "Child_int m_string", int val = 0): Base(name), m_int{val} 
	{
		std::cout << "Child_int constructed." << std::endl;
	}
	// This function returns the extra member.
	int& get_member(){
		return m_int;
	}
	std::string get_name(){
		return "Child_int";
	}
	// This is a basic print function.
	// It is not needed to add virtual infront of the derived functions
	// but it is good practise.
	virtual void print(){
		std::cout << "I a Child_int." << std::endl;
	}
};

// This is the first child derived from Base and has an extra int member.
class Child_float: public Base{
	float m_float;
		
public:
	// Construcor.
	Child_float(const std::string& name = "Child_int m_string", float val =  0.0): Base(name), m_float{val} 
	{
		std::cout << "Child_float constructed." << std::endl;
	}
	// This function returns the extra member.
	float& get_member(){
		return m_float;
	}
	// Tells me which Child instance I have.
	std::string get_name(){
		return "Child_float";
	}
	// This is a basic print function.
	// NB!!! If you want to called the derived verion, it must be exactly the same function.
	// This function wont be called using a Base* because I added the const access specifier.
	/// #### This will act unsuspectedly because the function is not identical to that of the
	//	base class.
	virtual void print()const{
		std::cout << "I a Child_float." << std::endl;
	}
};


// You can set a Base* to a intance of derived.
int main(){

	Base* b_ptr = new Base();
	Child_int* int_ptr = new Child_int();
	Child_float* fl_ptr = new Child_float();
	std::cout << std::endl;
	std::cout << b_ptr->get_name() << std::endl;
	std::cout << int_ptr->get_name() << std::endl;
	std::cout << fl_ptr->get_name() << std::endl;
	// This is the problem.
	std::cout << std::endl;
	Base* parent_ptr = int_ptr;
	parent_ptr->print();
	parent_ptr = fl_ptr;
	parent_ptr->print();
	//Base** family = new Base*[2];
//	family[0] = new Base[10];
//	family[1] = new Base[15];
	
	
	std::cout << std::endl;
	
	


	delete b_ptr;
	delete int_ptr;
	delete fl_ptr;
	
//	delete[] family[0];
//	delete[] family[1];
//	delete[] family;

	return 0;
}
