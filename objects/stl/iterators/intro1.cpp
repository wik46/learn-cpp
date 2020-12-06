/* ***************************************************************************************
 * Filename: intro1.cpp.
 * Author: Wikus Jansen van Rensburg.
 * Date: November 15, 2020.
 * Description: This is the first file written to practise iterator. Iterators should
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

int main(){	
	// Declaring a normal std::vector of ints.
	std::vector<int> v = {1,2,3,4,5};
	// Declaring an iterator to use alongside my vector.
	std::vector<int>::iterator i;
	// 1. Using the iterator to print out all the elements in the vector.
	for(i = v.begin(); i < v.end(); i++){
		std::cout << *i << ' ';
	}
	std::cout << "\n------"<< std::endl;
	// 2. Here I am using the .advance() member function.
	// This function will advance the iterator by the number specified.
	std::vector<int>::iterator n = v.begin();
	// This function takes an iterator and advances 2 steps foward.
	// This is only available with random-access iterators.
	advance(n, 2);
	std::cout << *(n++) << std::endl;
	// Note that the post-increment happens after cout, but at the next cout er
	// can see that it walk one element fowards.
	std::cout << *n << std::endl;
	std::cout << "-------" << std::endl;
	
	std::cin.get();

	return 0;
}
