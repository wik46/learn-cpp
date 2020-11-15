/* **************************************************************************************
 * Filename: Animal.cpp
 * Author: Lodewyk Jansen van Rensburg.
 * Description: This is the file for my Animal class. This class will be frequently used.
 * 		One thing to take note of that each type of animal will be stored in
 * 		a "cage". That is an array of the desired type. 
 * 		Animals are babies if they are between [0,6] months old. 
 * 		-	They will have a birth date if they were born in the zoo.
 *		- 	If they were born outside the Zoo they arrive at the zoo
 *			at age 4.
 *		- 	The "cages" - array of the types - will keep track of the number
 *			of babies and adults in the zoo.
 *		-	An adult is any animal 4 years or greater.
 *		- 	Any non-adult cannot give birth to a baby.
 *		- 	Each specie gives birth to a set number of babies.
 * **************************************************************************************/

#include "Animal.h"
#include <assert.h>

#include <iomanip>
#include <iostream>

// Polymorphism.
// 1. Compile time: Function and operator overloading.
// 2. Runtime: Function overiding i.e. virtual functions.

// Virtual functions.
// NB! When you declare a function in the base class virtual, what happenss is that
// 	you signal to the compiler that every time this function is used, it must use
// 	the most derived version of the object is is used with. 
// 	Virtual function must match exeactly with the one in the Base class.
// 		That is : Same return type, number of parameters, type of parameters, and whether

class Bear: public Animal{

public:
	// This function will be overidden.
	// It is not necesarry to add virtual to the child class as well but it is good 
	// practise.
	virtual void print();
	// This is the constructor for a Bear instance so far.
	Bear(const char* where): Animal(where) {}
};

/* *
 * Function name: print()
 * Description: This is used to show how to use the power of polymophism.
 * */
void Bear::print(){
	std::cout << std::setfill(' ') << std::setw(15)
	<< std::setprecision(3) << std::left;
	// This is just to see which function gets called.
	std::cout << "[As a Bear instance.] " << std::endl;
	std::cout << m_id_number << ' ' << m_name << ' ' << "Bear" << ' '; 
	std::cout << m_age_months << ' ' << m_place_of_birth 
	<< '.' << std::endl;
	return;
}

class Tiger: public Animal{
public:
	// This function will be overidden.
	// It is not necesarry to add virtual to the child class as well but it is good 
	// practise.
	virtual void print();
	// This is the constructor for a Bear instance so far.
	Tiger(const char* where): Animal(where) {}
};
/* *
 * Function name: print()
 * Description: This is used to show how to use the power of polymophism.
 * */
void Tiger::print(){
	std::cout << std::setfill(' ') << std::setw(15)
	<< std::setprecision(3) << std::left;
	// This is just to see which function gets called.
	std::cout << "[As a Tiger instance.] " << std::endl;
	std::cout << m_id_number << ' ' << m_name << ' ' << "Tiger" << ' '; 
	std::cout << m_age_months << ' ' << m_place_of_birth 
	<< '.' << std::endl;
	return;
}



// This class will be where all the animals are stored.
class Zoo{
// Just for now.
public:
	// This is an array of various animals: Bears, Tigers ...
	// We use an array of Animal*.
	Animal** all_animals;
	const int num_animals;
	// This constructor will create a Zoo given size.
	// It will also set all the Animal* to the zoo as NULL.
	Zoo(int size): num_animals(size)
	{
		assert(num_animals > 0);
		// Create an array to store different animals.
		all_animals = new Animal*[num_animals];
		// Set all the Animal* to NULL.
		for(int i = 0; i < num_animals; i++){
			// This is so that I freed only non-NULL data.
			all_animals[i] = NULL;
		}
	}
	// The destructor.
	~Zoo(){
		// This will clean up all the memory used by the class.
		for(int i = 0; i < num_animals; i++){
			if(all_animals != NULL){
				delete all_animals[i];
			}
		}
		delete[] all_animals;
	}
};


int main(){
	
	Animal** array = new Animal*[2];
	array[0] =  new Bear("zoo");
	array[1] = new Tiger("other");
	// Note that I am using a variable of type Animal* to access the members
	// of the child classes that is required.
	array[0]->print();
	array[1]->print();
	
	delete array[0];
	delete array[1];
	delete[] array;
	
	// Example using the Zoo class.
	Zoo z1(10);
	z1.all_animals[0] = new Bear("zoo"); 
	z1.all_animals[9] = new Tiger("zoo"); 
	z1.all_animals[6] = new Bear("zoo"); 
	z1.all_animals[3] = new Tiger("zoo"); 
	
	z1.all_animals[3]->print();

	return 0;
}
