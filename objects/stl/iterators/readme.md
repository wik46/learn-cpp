## Author: Lodewyk Jansen van Rensburg.
## Date: December 1, 2020.
## Description: 
		This is a directory used to study the basic types of iterators defined
		inside the C++ Standard Template Library.
		What is an iterator.
			* A pointer is a type of iterator.
			  It is used to iterate/ traverse through a set of datapoints.	

		There are 5 categories for types of iterators:
			- The iterator you used is based on the one used by the container you are using.
			- We list the iterators from most basic to most powerful.
			- The difference between the iterators are the operatrions that can be performed
			  on them and with them.
			- All containers in the STL support at least foward iterators.		

		** All iterators 	

		** The iterator has all the functionality of the ones above it an more. ** 
		a, b.) Input and Output iterators.
			* Can only be incremented.
	
			* Most basic type of iterator.
			Input Iterator:
				* Can only be dereferenced as an rvalue.
			Output Iterator:
				* Can only be dereferenced as an lvalue.
		c.) Foward iterators.(most primitive iterator used by the STL containers)
		- This is the Input and Ouput iterator combined.
		- This cannot be decremented, only incremented.
		
		d.) Bi-directional iterators.
		- This is a Foward iterator and more.
		- This iterator can be decremented.
		
		e.) Random-access iterators.
		- This is a Bi-directional iterator and more.
		- 1. You can add an integer n, to traverse n steps foward in the 
			container, instead of walking one element at a time.
		     Similiarly with subtracting n, to travers n elements in the opposite 
		     direction.
		     ** Note that you should ensure not to access out of range.	

Functions working with iterators:
	a. begin()
	b. end()
	c. advance()
	d. difference()
	
Take note:
	With the additions of C++11, all the associative containers have an unordered version of 
	the container. (https://www.cplusplus.com/reference/stl/)
