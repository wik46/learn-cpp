 /**************************************************
 *Program Filename: class_ex2.cpp
 *Author: Wikus
 *Date: 18 Aug 2020
 *Description: Learning how to use th create a log function to print types of errors
 *Input
 *Output
 **************************************************/


#include <iostream> //Remember all that the #inlcude statement does is copy and paiste

// You need to create an instance of a class, called an object in order to us it feautures.
// Only defining a class will do nothing to you program.
class Human{
public:	
	int array_size;
	
	// member variables.
	std::string m_date_of_birth;
	std::string m_place_of_birth;
	std::string* m_gender;
	 // The user can only access age through GetAge()
	int m_age;
	
	std::string m_name;
	

public:
	// Constructor;
	Human(int i = -1, int size = 0){;
		std::cout << i <<"). Human created." << std::endl;		
		array_size = size;
	}

	// Method
	void PrintInfo(){
		std::cout << "Please enter your name: ";
		std::cin >> m_name;
		std::cout << "Your age: ";
		std::cin >> m_age;
	}

	void introduce_yourself(){
		std::cout << "Hello my name is " + m_name << " and I am " << m_age << " years old."
		  << std::endl;
	}
	// This is so that the user can only see the age and not change it.
	int GetAge(){
		return m_age;
	}
	// This is for the user to acces user_name outside the class.
	std::string GetName(){
		return m_name;
	}
	
	// I only need the function prototype inside the class.
	void SetAge(int user_age);

	void SetSize(){
		std::cout << "Entere the size of your grade 1 class: ";
		std::cin >> array_size;
	}
	// This function is a member of a class that can print another classes data.
	void print(Human* c_Human);
	
	// I only need the function prototype inside the class.
	void SetAge(int user_age);


};

// This can is a method of the class human.
void Human::SetAge(int user_age){
	if(user_age < 1){
		std::cout << "[SetAge]: Enter a positive age." << std::endl;
	}else{
		m_age = user_age;
	}
}


void Human::print(Human* c_Human){

	std::cout << c_Human->m_name << std::endl;
}

int main(){
	// I am creating an instance of the class Human.
	// first_person is an object.
	Human first_person(1);

	first_person.PrintInfo();
	first_person.introduce_yourself();

	first_person.print(&first_person);
	std::cout << "You are indeed " << first_person.GetAge() << std::endl;
	// Dynamically allocating an instance of Human.
	Human* second_person = new Human(2);

	second_person->PrintInfo();
	second_person->introduce_yourself();
	
	int size = 10;
	Human* grade_1_class = new Human[size];
	for(int i = 0; i < size; i++){
		//std::cout << i << std::endl;
		(grade_1_class + i)->m_name = "default";
	}
	std::cout << grade_1_class[4].m_name << std::endl;
	

	// Deleting the Human pointer.
	delete[] grade_1_class;
	delete second_person;


}
