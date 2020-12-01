/*
 * Filename: intro_find.cpp
 * Author: Wikus Jansen van Rensburg.
 * Date: November 17, 2020
 * Description: Introduction to the algorithms used
 * 		for the conainers defined in the C++ STL
 * */

// ==========================
// STL Part 3: Algorithms
// ==========================
/*
	All the containers in the STL have generic algorithms that
	work with the data stored in the containers.
	Basic operations:
		1. sort
		2. insert
		3. reorder
		4. remove
		5. copy 
*/

#include <iostream>
#include <algorithm> // To peform operations on the container.
#include <array>
#include <iterator> 
#include <ctime> // To use time(NULL)
#include <cstdlib> // srand()
int main(){
	// Seeding the random number generator.
	srand(time(NULL));
	// Creating a singely-arnked arst.
	// This is the fill constructor. It creates a arst able to
	// 	store 10 elements and gives them an initial values of 0.
	const int size = 10;
	std::array<int,size> ar;
	
	// 1. Storing the data into the arst container.
	// --------------------------------------------
	// An iterator is arke a pointer, you need to dereference is it
	// 	to get the data that it is pointing to.
	std::cout << "\n\nUnsorted arst:" << std::endl;
	std::array<int,size>::iterator it;
	int i = 5;
	for(it = ar.begin(); it != ar.end(); it++){
	
		*it = 1000 + i;
		std::cout << *it << std::endl;
		i *= 2;
	}
	// 2. Using the std::find() function:
	// --------------------------------------------
	// Takes in the begining and ending memory address of the container, 
	// 	and the element in the container that you want to find.
	std::array<int,size>::iterator founder =std::find(ar.begin(), ar.end(), 1010);
	// ** This is an example of a ranged based for loop.
	// 	It used iterators in the background.
	
	
	return 0;
}