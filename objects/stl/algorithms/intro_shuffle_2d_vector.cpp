/* ***************************************************************************************
 * Filename: intro_shuffle_2d_vector.cpp
 * Author: Wikus Jansen van Rensburg
 * Date: November 19, 2020.
 * Description: This file is used to study how to used the shuffle 
 * 		function provided by the STL algorithms.
 *		
 *		================================================
 *		Operations performed on the 2d vector container.
 *		================================================
 *		1. This program creates a container with random numbers and prints it to
 *			the screen.
 *		2. Then it sorts the 2d container and prints it to the screen.
 *		3. Thereafter is shuffles the container and prints it to the screen.
 * **************************************************************************************/

#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <iterator>
// To calculate random numbers.
#include <ctime> 
#include <cstdlib>
int main(){
	// Seeding the random number generators.
	srand(time(NULL));
	// Creating an array of vector numbers.
	std::vector<std::vector<int> > v1(12,std::vector<int>(15));
	// Declaring the iterators.
	// a. This iterator is like the pointer to the first element of the 2d container.
	// std::vector has random access iterators.
	std::vector<std::vector<int> >::iterator it_out;
	// b. This is like a pointer to the first element of each 1d constainer.
	std::vector<int>::iterator it_in;
	// 1. Storing random numbers in the container.
	// ============================================
	for(it_out = v1.begin(); it_out != v1.end(); it_out++){
		for(it_in = it_out->begin(); it_in != it_out->end(); it_in++){
			// This will store any random number in the container.
			*it_in = rand() % 21;
		}
	}
	// Storing random numbers in side the vector that I want to sort and shuffle later.
	// Now I print the vector.
	std::cout << "\n1. Initial Container: "<< std::endl;	
	std::cout << std::setw(20) << std::setfill('-') << ' '<< std::endl;
	// Using iteratorors to traverse through the container.
	std::cout << std::setfill(' ');
	for(it_out = v1.begin(); it_out != v1.end(); it_out++){
		for(it_in = it_out->begin(); it_in != it_out->end(); it_in++){
			std::cout << std::setw(3) << *it_in << " ";
		}
		std::cout << std::endl;
	}
	// 2. Sorting the container
	// =========================
	std::cout << "\n2. Sorting the container: "<< std::endl;	
	std::cout << std::setw(40) << std::setfill('-') << ' '<< std::endl;
	std::cout << std::setfill(' ');
	// This function will sort the container in ascending order.
	// std::sort() can only sort a container that has a RandomAccessIterator.
	// Printing out the newly sorted container.
	for(it_out = v1.begin(); it_out != v1.end(); it_out++){
		// This will sort the array before printing it.
		std::sort(it_out->begin(), it_out->end());
		for(it_in = it_out->begin(); it_in != it_out->end(); it_in++){
			std::cout << std::setw(3) << *it_in << " ";	
		}	
		std::cout << std::endl;
	}	
	
	// 3. Shuffeling the container
	// =========================
	//
	// Note**: If you want to use std::shuffle for custom data types you need
	// 		to define the swap function.
	
	std::cout << "\n3. Shuffling the container: "<< std::endl;	
	std::cout << std::setw(20) << std::setfill('-') << ' '<< std::endl;
	std::cout << std::setfill(' ');
	std::random_shuffle(v1.begin(), v1.end());
	// Printing the newly shuffled container.
	// a. Shuffle the rows of the columns.
	std::random_shuffle(v1.begin(), v1.end());
	for(it_out = v1.begin(); it_out != v1.end(); it_out++){
		// This shuffles the current row in the 2d container.
		std::random_shuffle(it_out->begin(), it_out->end());
		// Printing out the newly shuffled row.
		for(it_in = it_out->begin(); it_in != it_out->end(); it_in++){
			std::cout << std::setw(3) << *it_in << " ";	
			
		}
		std::cout << std::endl;
	}
	
	return 0;
}
