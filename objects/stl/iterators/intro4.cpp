/* ***************************************************************************************
 * Filename: intro4.cpp.
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


// ======================
// Iterators:
// ======================

// Containers support specific type of iterator or in some cases no iterator at all.
// Example: std::vector support random access iterators (the strongest).
// 	    std::list suppoerts bi-directional.
// 	    std::set support bi-directional.
// 	    std::stack does not support iterators.
	
// Types of Iterators: (weakest - strongest)
// 1. Input:
// 2. Output:
// 3. Foward Directional:
// 4. Bi-directional:
// 5. Random access.


// Notes on 'dangling' or invalidated iterators.
// 1. When you change the container that the iterator is associated with by example 
// 	adding elements to the container, the iterator is left dangling
// 	and this causes undefined behaviour. 
// 2. Trying to dereference a invalidated iterator leads to a segmentation fault.
int main(){	
	// =========================================================================
	// This program demonstrate how iterators work with the Sequence Containers:
	// =========================================================================
	/* all containers will have the same size for this example*/
	const int size = 20;
	/* the containers are filled with random numbers */
	srand(time(NULL));
	/* Used as an index when printing elements */
	int i = 1;
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
	std::cout << "\nFilling std_array with random data:\n"<< std::endl;
	i = 1; /* only used as an index next to elements */
	for(std::array<int, size>::iterator it = std_array.begin(); it != std_array.end(); it++){
		// All containers have at least foward iterators therfore we can
		// 	use them as an lvalue or rvalue.
		(*it) = rand() % 100; /* for example purposes only store integers 0 - 99 */ 
		std::cout << std::setw(2) << std::setfill(' ') << i
		<< ".) " << *it << std::endl;
		i++; /* only used to see how many elements are printed. */
	}	
	std::cout << "\n-----------------------------------------------\n" << std::endl;
	
	// 2. Filling the std::vector
	std::cout << "\nFilling std_vector with random data:\n"<< std::endl;
	i = 1; /* only used as an index next to elements */
	for(std::vector<int>::iterator it = std_vector.begin(); it != std_vector.end(); it++){
		// All containers have at least foward iterators therfore we can
		// 	use them as an lvalue or rvalue.
		(*it) = rand() % 100; /* for example purposes only store integers 0 - 99 */ 
		std::cout << std::setw(2) << std::setfill(' ') << i
		<< ".) " << *it << std::endl;
		i++; /* only used to see how many elements are printed. */
	}
	std::cout << "\n-----------------------------------------------\n" << std::endl;
	
	// 3. Filling the std::list	
	std::cout << "\nFilling std_list with random data:\n"<< std::endl;
	i = 1; /* only used as an index next to elements */
	for(std::list<int>::iterator it = std_list.begin(); it != std_list.end(); it++){
		(*it) = rand() % 100; /* for example purposes only store integers 0 - 99 */ 
		std::cout << std::setw(2) << std::setfill(' ') << i
		<< ".) " << *it << std::endl;
		i++; /* only used to see how many elements are printed. */
	}
	std::cout << "\n-----------------------------------------------\n" << std::endl;
	
	// 4. Filling the std::foward_list	
	std::cout << "\nFilling std_f_list with random data:\n"<< std::endl;
	i = 1; /* only used as an index next to elements */
	for(std::forward_list<int>::iterator it = std_f_list.begin(); it != std_f_list.end(); it++){
		(*it) = rand() % 100; /* for example purposes only store integers 0 - 99 */ 
		std::cout << std::setw(2) << std::setfill(' ') << i
		<< ".) " << *it << std::endl;
		i++; /* only used to see how many elements are printed. */
	}
	std::cout << "\n-----------------------------------------------\n" << std::endl;
	
	// 5. Filling the std::deque	
	std::cout << "\nFilling std_deque with random data:\n"<< std::endl;
	i = 1; /* only used as an index next to elements */
	for(std::deque<int>::iterator it = std_deque.begin(); it != std_deque.end(); it++){
		// All containers have at least foward iterators therfore we can
		// 	use them as an lvalue or rvalue.
		(*it) = rand() % 100; /* for example purposes only store integers 0 - 99 */ 
		std::cout << std::setw(2) << std::setfill(' ') << i
		<< ".) " << *it << std::endl;
		i++; /* only used to see how many elements are printed. */
	}
	std::cout << "\n-----------------------------------------------\n" << std::endl;

	// =======================================
	// III. Printing out data using iterators:
	// =======================================


	// To add a nice end to the program.
	std::cout << "\n\n** Press [enter] to terminate the program. **" << std::endl;
	std::cin.get();

	return 0;
}
