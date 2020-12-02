/* ***************************************************************************************
 * Filename: intro_set.cpp
 * Author: Lodewyk Jansen van Rensburg
 * Date: December 1, 2020.
 * Description: This is a program to demostrate the use of the std::set template
 * 		class defined inside the C++ Standard Template Library.
 * **************************************************************************************/

// =======================
// std::set
// =======================


// Lives inside this header file.
#include <set>

#include <iostream> /* To perform basic console input and ouput*/
#include <iomanip> /* This is to used std::setw() */

// What is it?
/*
	std::set is an associative container defined in the STL library.
	The charateristics of the associative containers are that they automatically
	sort the datapoints that you insert to the contianer (by default in ascending order).
	-  For example if insert integers into the container in the order {1,4,-3,4,10}.
	   the contianer will automatically sort them to {-3,1,4,10}.
	- Also note that no duplicate values are kept. This the same as with a mathematical
	  set of integers.
	- Values of elements cannot be modified when inside a set, all these values are const.
		But you can remove and replace the elements.
	Keys:
		- The value of the data acts as its key.
		- Example: If you want to delete 4 from a set of integers you use
			   set_name.erase(4).

*/

// ** Note that the type of iterator used is a:

// 	- bi-directional iterator.

// 1. Used inside remove_if().
bool is_12(int);

int main(){
	std::cout << "#################################" << std::endl;
	std::cout << "std::set Program." << std::endl;
	std::cout << "#################################" << std::endl;
	std::cout << "1. Iterator: bi-directional" << std::endl;
	std::cout << "2. Type of associative container." << std::endl;
	std::cout << "#################################\n" << std::endl;


	// I Methods of contruction:
	// ============================
	std::cout << "\nI Methods of construction: " << std::endl;	
	std::cout << "===========================" << std::endl;	
	// 1. Default constructor. (empty list)
	std::set<int> empty_set;
	// 2. Fill the constructor with n elements, each containing a copy value provided.
	/* Not valid method for std::set contruction */
	// std::set<int> int_set(n,value);
	// 3. Method of construction.
	std::set<int> int_set = {10,10, -1, 4, 3, 10, -4, 5};
	// 5. Set of chars2.
	std::set<char> char_set = {'k','z','s','c','g','w','w','e'};
	// II: Manipulation of data.
	

	// --------------------------
	// B. State of the container.
	// --------------------------
	std::cout << "\nII State of the container: " << std::endl;	
	std::cout << "==============================" << std::endl;	
	// 1. .empty() returns true if size = 0, else returns false.
	std::cout << "\nint_set.empty() : (true/false) " << int_set.empty() << std::endl;
	std::cout << "char_set.empty() : (true/false) " << char_set.empty() << std::endl;
	// 2. Returns the number of elements in the container.
	std::cout << "int_set.size() : " << int_set.size() << std::endl;
	std::cout << "char_set.size() : " << char_set.size() << std::endl;

	// ----------------------------------
	// C. Changing data in the container.
	// ----------------------------------
	std::cout << "\nIII Manipulation of data: " << std::endl;	
	std::cout << "==============================" << std::endl;	
	// 1. .insert() adds the element to the set.
	// Note: This is the only insertion needed because the data
	// 	 gets sorted automatically.
	int_set.insert(-10);
	int_set.insert(40);
	int_set.insert(12);
	std::cout << "After inserting -10, 40, 12 using .insert( value ): "<< std::endl;
	// Using a for-each loop to iterate through the container.
	for(int num : int_set){
		std::cout << std::setw(2) << std::setfill(' ') 
		<< num << std::endl;
	}
	
	// ----------------------------------
	// D. Removing data in the container.
	// ----------------------------------
	std::cout << "\nIV Removing data: " << std::endl;	
	std::cout << "==============================" << std::endl;	
	// 1. push_front(): Adds in element in the begining.
	int_set.erase(-10);
	int_set.erase(40);
	std::cout << "After removing -10, 40 using .erase( value ): "<< std::endl;
	// Using a for-each loop to iterate through the container.
	for(int num : int_set){
		std::cout << std::setw(2) << std::setfill(' ') 
		<< num << std::endl;
	}

	
	// -------------------------
	// D. Additional operations.
	// -------------------------
	std::cout << "\nV Additional functionality: " << std::endl;	
	std::cout << "==============================" << std::endl;	
	// ** Note: For each loops make use of iterators in the background.
	// 	    For more information on iterators, see the iterator directory.
	std::cout << "\nSet before operations: "<< std::endl;
	std::cout << "\nInt set: "<< std::endl;
	// This is an example of a for-each loop.
	for(int i : int_set){
		std::cout << i << std::endl;
	}
	// 2. Printing out char set.
	std::cout << "\nChar set: "<< std::endl;
	for(char a: char_set){
		std::cout << a << std::endl;
	}	
	
	
	std::cout << "\n Char set after clear(): "<< std::endl;
	char_set.clear();
	// This will not print any elements because all the elements are removed
	// by .clear()
	for(char a: char_set){
		std::cout << a << std::endl;
	}

	std::cout << std::endl << "*** End of std::set demonstration ***"
	<< std::endl << std::endl;

	return 0;
}


