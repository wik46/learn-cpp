/* ***************************************************************************************
 * Filename: intro3.cpp.
 * Author: Wikus Jansen van Rensburg.
 * Date: December 6, 2020.
 * Description: This is the second file written to practise iterator. Iterators should
 * 		be used to iterate throught the container types in the C++ STL.
 * **************************************************************************************/

// Needed for output to the commandline.
#include <iostream>
// To use std::setfill() and std::setw()
#include <iomanip>
// Needed for random number generation.
#include <cstdlib>
// These headerfiles are needed to use the various containers.
#include <array>
#include <vector>
#include <list>
#include <forward_list>
#include <deque>
// Used to gain access to std::sort()
#include <algorithm>

// ============================================
// Lookin at how to use the <algorithm> header:
// ============================================

// ================================================================
// ** SKIP TILL THE '%%%' lines to see what this file demonstrates.
// ================================================================


// See function description and definition below.
bool ascending(int a, int b);

int main(){	
	// =========================================================================
	// This program demonstrate how iterators work with the Sequence Containers:
	// =========================================================================
	/* all containers will have the same size for this example*/
	const int size = 20;
	/* the containers are filled with random numbers */
	srand(time(NULL));
	// ===========================
	// I. Creating the containers:
	// ===========================
	
	// 1. Creating the std::array templated class.
	std::array<int, size> std_array;
	// 2. Creating the std::vector templated class.
	std::vector<int> std_vector( size );
	// 3. Creating the std::list templated class. (doubley-linked list)
	std::list<int> std_list( size );
	// 4. Creating the std::foward_list templated class. (singley-linked list)
	std::forward_list<int> std_f_list(size);
	// 5. Creating the std::deque templated class. 
	/* A dynamic array that can grow from both sides */
	std::deque<int> std_deque(size);

	// ========================================
	// II. Filling containers with random data:
	// ========================================
	
	// 1. Filling the std::array
	std::cout << "\nFilling std_array with random data:"<< std::endl;
	std::cout << "------------------------------------------------------------------------" << std::endl;
	std::cout << "std_array: ";
	for(std::array<int, size>::iterator it = std_array.begin(); it != std_array.end(); it++){
		// All containers have at least foward iterators therfore we can
		// 	use them as an lvalue or rvalue.
		(*it) = rand() % 100; /* for example purposes only store integers 0 - 99 */ 
		std::cout << *it << ' ';
	}	
	std::cout << "\n------------------------------------------------------------------------\n" << std::endl;
	
	// 2. Filling the std::vector
	std::cout << "Filling std_vector with random data:"<< std::endl;
	std::cout << "------------------------------------------------------------------------" << std::endl;
	std::cout << "std_vector: ";
	for(std::vector<int>::iterator it = std_vector.begin(); it != std_vector.end(); it++){
		// All containers have at least foward iterators therfore we can
		// 	use them as an lvalue or rvalue.
		(*it) = rand() % 100; /* for example purposes only store integers 0 - 99 */ 
		std::cout << *it << ' ';
	}
	std::cout << "\n------------------------------------------------------------------------\n" << std::endl;
	
	// 3. Filling the std::list	
	std::cout << "Filling std_list with random data:"<< std::endl;
	std::cout << "------------------------------------------------------------------------" << std::endl;
	std::cout << "std_list: ";
	for(std::list<int>::iterator it = std_list.begin(); it != std_list.end(); it++){
		// All containers have at least foward iterators therfore we can
		// 	use them as an lvalue or rvalue.
		(*it) = rand() % 100; /* for example purposes only store integers 0 - 99 */ 
		std::cout << *it << ' ';
	}
	std::cout << "\n------------------------------------------------------------------------\n" << std::endl;
	
	// 4. Filling the std::foward_list	
	std::cout << "Filling std_f_list with random data:"<< std::endl;
	std::cout << "------------------------------------------------------------------------" << std::endl;
	std::cout << "std_f_list: ";
	for(std::forward_list<int>::iterator it = std_f_list.begin(); it != std_f_list.end(); it++){
		// All containers have at least foward iterators therfore we can
		// 	use them as an lvalue or rvalue.
		(*it) = rand() % 100; /* for example purposes only store integers 0 - 99 */ 
		std::cout << *it << ' ';
	}
	std::cout << "\n------------------------------------------------------------------------\n" << std::endl;
	
	// 5. Filling the std::deque	
	std::cout << "Filling std_deque with random data:"<< std::endl;
	std::cout << "------------------------------------------------------------------------" << std::endl;
	std::cout << "std_deque: ";
	for(std::deque<int>::iterator it = std_deque.begin(); it != std_deque.end(); it++){
		// All containers have at least foward iterators therfore we can
		// 	use them as an lvalue or rvalue.
		(*it) = rand() % 100; /* for example purposes only store integers 0 - 99 */ 
		std::cout << *it << ' ';
	}
	std::cout << "\n------------------------------------------------------------------------\n" << std::endl;

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	// ===================================================
	// GOAL OF THIS FILE
	// ===================================================
	// 	III. Sorting data using iterators:
	// ===================================================
	
	// Sorting all the containers.
	/* std::sort() defined inside <algorithm> only works with containers that
 		have random access iterators. */
	// 1. Reversing the part of the array that is bounded by the iterators.
	// Needs bi-directional iterators. 
	std::reverse( std_array.begin(), std_array.end());
	// 2. Sorting the std::vector templated class's first 4 elements.
	std::sort( std_vector.begin(), std_vector.begin() + 4);
	// Returns an iterator to the maximum element.
	std::vector<int>::iterator max_elem = std::max_element(std_vector.begin(), std_vector.end());
	
	/* Note that the linked list has sort as a member function*/
	// 3. Sorting the std::list templated class. (doubley-linked list)
	std_list.sort();
	// 4. Sorting the std::foward_list templated class. (singley-linked list)
	std_f_list.sort();
	// 5. Sorting the std::deque templated class. 
	/* A dynamic array that can grow from both sides */
	std::sort(std_deque.begin() + 10, std_deque.end() - 3);

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	
	// ===================================================
	// IV. Printing data using iterators:
	// ===================================================
	std::cout << "\n\nAfter using algorithms inside <algorithm>:\n" << std::endl;
	// 1. Printing the std::array
	std::cout << "------------------------------------------------------------------------" << std::endl;
	std::cout << "std_array( std::reverse() ):\n";
	for(std::array<int, size>::iterator it = std_array.begin(); it != std_array.end(); it++){
		// All containers have at least foward iterators therfore we can
		// 	use them as an lvalue or rvalue.
		std::cout << *it << ' ';
	}	
	std::cout << "\n------------------------------------------------------------------------\n" << std::endl;
	
	// 2. Printing the std::vector
	std::cout << "------------------------------------------------------------------------" << std::endl;
	std::cout << "std_vector:\n";
	for(std::vector<int>::iterator it = std_vector.begin(); it != std_vector.end(); it++){
		std::cout << *it << ' ';
	}
	std::cout << std::endl << "Maximum element (std::max_element()): " 
	<< *max_elem;
	std::cout << std::endl << "Minimum element (std::min_element() return an iterator to it): " 
	<< * std::min_element( std_vector.begin(), std_vector.end() ); /* we need to dereference the iterator to get the value*/
	std::cout << "\n------------------------------------------------------------------------\n" << std::endl;
	
	// 3. Printing the std::list	
	std::cout << "------------------------------------------------------------------------" << std::endl;
	std::cout << "std_list: ";
	for(std::list<int>::iterator it = std_list.begin(); it != std_list.end(); it++){
		std::cout << *it << ' ';
	}
	std::cout << "\n------------------------------------------------------------------------\n" << std::endl;
	
	// 4. Printing the std::foward_list	
	std::cout << "------------------------------------------------------------------------" << std::endl;
	std::cout << "std_f_list: ";
	for(std::forward_list<int>::iterator it = std_f_list.begin(); it != std_f_list.end(); it++){
		std::cout << *it << ' ';
	}
	std::cout << "\n------------------------------------------------------------------------\n" << std::endl;
	// 5. Printing the std::deque	
	std::cout << "------------------------------------------------------------------------" << std::endl;
	std::cout << "std_deque ( sorting an interval):\n";
	for(std::deque<int>::iterator it = std_deque.begin(); it != std_deque.end(); it++){
		std::cout << *it << ' ';
	}
	std::cout << "\n------------------------------------------------------------------------\n" << std::endl;
	


	// To add a nice end to the program.
	std::cout << "\n\n** Press [enter] to terminate the program. **" << std::endl;
	std::cin.get();

	return 0;
}

/* ***************************************************************************************
 * Function name: ascending()
 * Decription: This function is used to sort the container in ascending order.
 * Remember: 1. You need to define a function that take in two parameters
 * 		of the same type as the container.
 * 	     2. This function must return a boolean value.
 * 	     3. Ensure that the operator you are using to make the comparison
 * 	     	is defined for the data type you are using if you are using user-defined
 * 	     	data types.
 * 	     4. By default, std::sort uses '<' to make comparisons.
 * **************************************************************************************/
bool ascending(int a, int b){
	return (a > b); /* This will work because the operator is defined for integers.*/
}
