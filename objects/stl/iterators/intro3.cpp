/* ***************************************************************************************
 * Filename: intro3.cpp.
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
// 	and this causes undefined behaviour. 
// 2. Trying to dereference a invalidated iterator leads to a segmentation fault.
int main(){	
	// =================================================
	// This program creates a 2d vector of strings:
	// =================================================
	
	std::string _default = "default";
	// This creates a 2d_vector container to store strings.
	std::vector<std::vector<std::string>> _2d_str(10,std::vector<std::string>(10,_default));	
	// This is the 2d vector iterator.
	std::vector<std::vector<std::string>>::iterator it;
	// This is the 1d vector iterator.
	std::vector<std::string>::iterator it2;
	// Remember that an iterator is pointer
	for(it = _2d_str.begin(); it != _2d_str.end(); it++){
		for(it2 = it->begin(); it2 != it->end(); it2++){
			std::cout << *it2 << std::endl;
		}
		std::vector<std::string>::iterator it2;
	}

	std::cin.get();

	return 0;
}
