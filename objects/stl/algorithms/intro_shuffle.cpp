/*
 * Filename: intro_shuffle.cpp
 * Author: Wikus Jansen van Rensburg
 * Date: November 19, 2020.
 * Description: This file is used to study how to used the shuffle 
 * 		function provided by the STL algorithms.
 *
 * */

#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>

// To calculate random numbers.
#include <ctime> 
#include <cstdlib>
int main(){
	// Seeding the random number generators.
	srand(time(NULL));
	// Creating an array of vector numbers.
	std::vector<int> v1;
	// 1. Storing random numbers in the container.
	// ============================================
	// Storing random numbers in side the vector that I want to sort and shuffle later.
	for(int i = 0; i < 10; i++ ){
		v1.push_back( rand() % 21);
	}
	// Now I print the vector.
	std::cout << "\n1. Initial Container: "<< std::endl;	
	std::cout << std::setw(20) << std::setfill('-') << ' '<< std::endl;
	std::vector<int>::iterator it;
	// Using iteratorors to traverse through the container.
	for(it = v1.begin(); it != v1.end(); it++){
		std::cout << *it << std::endl;
	}
	// 2. Sorting the container
	// =========================
	std::cout << "\n2. Sorting the container: "<< std::endl;	
	std::cout << std::setw(20) << std::setfill('-') << ' '<< std::endl;
	// This function will sort the container in ascending order.
	// std::sort() can only sort a container that has a RandomAccessIterator.
	std::sort(v1.begin(), v1.end());
	// Printing out the newly sorted container.
	for(it = v1.begin(); it != v1.end(); it++){
		std::cout << *it << std::endl;
	}	
	// 3. Shuffeling the container
	// =========================
	std::cout << "\n3. Shuffling the container: "<< std::endl;	
	std::cout << std::setw(20) << std::setfill('-') << ' '<< std::endl;
	std::random_shuffle(v1.begin(), v1.end());
	// Printing the newly shuffled container.
	for(it = v1.begin(); it != v1.end(); it++){
		std::cout << *it << std::endl;
	}
	return 0;
}
