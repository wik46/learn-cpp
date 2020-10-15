/*
 * Filename: inheritance1.cpp
 * Author: Wikus
 * Date: October 7, 2020
 * Description: This program is used to study how the inherance works. 
 *
 * */

#include <iostream>

class Person{
public: // Everything is public to make the example simplies.
	// Member variables.
	std::string m_name;
	int m_age;
	// The default constructor.
	Person(const std::string& name = "", int age = 0)
		: m_name{name}, m_age{age}
	{
	}
	// Methods.
	friend std::ostream& operator<<(std::ostream& stream, const Person& object){
		stream << object.m_name << ", " << object.m_age << std::endl;
		return stream;
	}
};

class RugbyPlayer: public Person
{	
	// Still need to add member variables and member
};

int main(){
	std::string name = "Wikus";
	RugbyPlayer r;
	r.m_name = name;
	r.m_age = 20;
	std::cout << r << std::endl;
	return 0;
}
