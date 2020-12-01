/* ***************************************************************************************
 * Filename: intro2.cpp.
 * Author: Wikus Jansen van Rensburg.
 * Date: November 15, 2020.
 * Description: This is the second file written to practise iterator. Iterators should
 * 		be used to iterate throught the container types in the C++ STL.
 * **************************************************************************************/

#include <iostream>
#include <vector>

// ======================
// Iterators:
// ======================

// What is an iterator:
// It is like a fancy pointer pointing at some element in the container. We can
// 	then walk foward or bi-directional towards, or in some cases have random access
// 	to the elements in the container.

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
// 	and this cuases undefined behaviour. 
// 2. Trying to dereference a invalidated iterator leads to a segmentation fault.
int main(){	
	// Iterating through an array using raw pointers.
	int length = 5;
	int m_array[] = {1,2,3,4,5};
	int* ptr = m_array;
	int* end = &(m_array[length - 1]) + 1; // Note that this is one passed to array.

	for(ptr; ptr != end; ptr++){
		std::cout << *ptr << std::endl;
	}

	// Declaring a normal std::vector of ints.
	// This is a 2 dimensiona vector.
	std::vector< std::vector<int> > v;
	
	std::vector<int> vector1 = {11,12,13,14};
	std::vector<int> vector2 = {21,22,23,24};
	// Adding elements to a containers changes the address of the container.
	// Any previously set iterator will be left dangling and cannot be used anymore.
	v.push_back(vector1);
	v.push_back(vector2);

	// Avoiding dangling iterators:
	// ================================
	// Declaring an iterator to use alongside my vector.
	// In order to avoid a 'dangling' iterator, we must
	//  first assign new elements to the vector before assinging
	//  the address of the first element to the iterator.
	std::vector< std::vector<int> >::iterator i = v.begin();
	std::vector<int>::iterator j;
	
	// Using iterators with 2d std::vectors.
	// =====================================
	for(i; i != v.end(); i++){
		for(j = i->begin(); j != i->end(); j++){
			std::cout << *j << std::endl;
		}

	}
	std::cin.get();

	return 0;
}
