 /**************************************************
 *Program Filename: class_ex5.cpp
 *Author: Wikus
 *Date: 22 August 2020
 *Description: Learning how to use th create a log function to print types of errors
 *Input
 *Output
 *************************************************/

#include <iostream>
#include <assert.h>
#include <type_traits>

// The constructor serves two purposes.
// 1. Firstly it is use to create and instance of a class called an object.
// 2. The programmer can use it to instantiate its member variables.
// - Remeber that a member variable that is a class, this class will be created before the body of the
// 	outer class executes. The inner class member's constructor will be call first.

// Member initializer list.
// ========================
// You cannot assign value to const or reference members in the body of the constructor.
// You need to instantiate them.
//

// I am creating an object IntArray.
// This will be an array with extra functionality.
class IntArray{
private:
	int* m_array;
	int m_length;

public:
	// The constructor.
	IntArray(int length = 10)
	: m_length(length)
	//My constructor creates the array and sets all the values of the array to 0.
	{
		assert(length > 0);
		m_array = new int[m_length];
		init_array();
	}
	// Destructor.
	// This will exectute when my class gets termintated manually, or the object get
	// 	explicitly destroyed using the new keyword.
	~IntArray(){
		delete[] m_array;
	}

	// This member is used to get the length of my array.
	int GetLength(){
		return m_length;
	}
	
	// This function sets all the ints in my array to zero.
	void init_array(){
		for(int index = 0; index < m_length; index++){
			m_array[index] = 0;
		}
	}
	// This member prints the contents of the array.
	void print(){
		for(int i = 0; i < m_length; i++){
			std::cout << i+1 << "). " << m_array[i] << std::endl;
		}
	}
	// This function lets met set the values at a certain index.
	void set_value(int data, int index){
		assert(index >= 0 && index < m_length);
		m_array[index] = data;
		std::cout << data <<  " set at index " << index << "." << std::endl;
	}	
	
	
};

int main(){

	IntArray my_array(20);
	my_array.set_value(10,2);
	my_array.print();

	return 0;
}



