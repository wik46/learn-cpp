// Poiters and references to derived class objects.
//

#include <iostream>

class Base{

public:
	std::string get_name(){
		return "Base";
	}

	Base(){
		std::cout << "Base constructed. "<< std::endl;
	}
	void print(){
		std::cout << "I a Base." << std::endl;
	}
	

};


class Derived: public Base{
	std::string m_name;
		
public:
	// Construcor.
	Derived(const std::string& name): m_name{name}
	{
		std::cout << "Child constructed." << std::endl;
	}
	// Getter.
	std::string get_name(){
		return m_name;
	}

	void print(){
		std::cout << "I a Derived." << std::endl;
	}


};

// You can set a Base* to a intance of derived.
int main(){

	Base* b_ptr = new Base();
	Derived* d_ptr = new Derived("Wikus");
	
	std::cout << b_ptr->get_name() << std::endl;
	std::cout << d_ptr->get_name() << std::endl;
	// This is the problem.
	Base* prb_ptr = d_ptr;
	std::cout << std::endl;
	std::cout << prb_ptr->get_name() << std::endl;
	


	delete b_ptr;
	delete d_ptr;
	return 0;
}
