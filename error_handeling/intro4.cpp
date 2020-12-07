/* ***************************************************************************************
 * Filename: intro4.cpp
 * Author: Wikus Jansen van Rensburg
 * Date: December 7, 2020.
 * Description: This program is used to show the timing of catch blocks
 * 		and how they are used with construction and destruction of objects.
 * Learning Resource: 
 * 		https://www.geeksforgeeks.org/c-exception-handling-question-1/?ref=rp
 * **************************************************************************************/
#include <iostream>

// ============================================
// Throw statements inside constructors..
// ============================================

/*
	This is a basic class just to show what happens with objects when
	throw statements are executed. 
*/
/*  Side note: You cannot throw just and empty exeption, but you can throw an empty
	exception inside a nested try/ catch blocks. 
*/

// This example if from the GeeksforGeeks quiz on exception handeling.

// First class.
class Object1{
	// The number that keeps track of the number of Object1 instance created.
	static int count;
	// The unique id number of each class.
	int m_id;
public:
	// A constructor that is used to see when my object is constructed.
	Object1() 
	{
		// Add to the number of instances created.
		count++;
		// This will be the id of the class.
		m_id = count;
		std::cout << "[Object1]: constructor called and id: "<< m_id << std::endl;
		// This will throw an exception if there are 4 intances of the class.
		if(m_id >= 4){
			throw 4;
		}
		// This will not be called if the throw statement executes.
		// Remember that a destructor of a class will no get called if the 
		// 	constructor did not finish its body.
		std::cout << "** End of construction **\n" << std::endl;
	}
	// This constructor is used to see when my object is destructed.
	/** Remember that destructors always get called in seperate order than the constructors.**/
	~Object1(){
		std::cout << "[Object1]: destructor called and id: " << m_id << std::endl;
	}
};
	
// This keeps track of the number of instances of the class.
int Object1::count = 0;

int main(){
	// Example 2:
	// -----------
	std::cout << "\n=========================" << std::endl;

	// This will create not create 5 objects becuase an exception will be thrown during the
	// 	creation of the 4 object.
	// Remember that destructors get called in opposite direction as the constructors.	
	try{
		// This will attempt to create 5 objects.
		Object1 array[5];
	}catch(int a){
		std::cout << "Exception caught: " << a << std::endl;	
	}	

	std::cout << "\n** End of program. **\n"<< std::endl;
	return 0;
}
