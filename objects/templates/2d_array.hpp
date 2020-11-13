/// ########################
//  In progress.
/// ########################

/* ***************************************************************************************
 * Filename: 2d_array.hpp
 * Author: Wikus
 * Date: November 12, 2020.
 * Description: This file contains the first attempt to create a universal container
 * 		that I can use for future projects. 
 * 		The container will add extra functionality such as it will print the
 * 		be a 2d array that is at essecence a 2d std::vector.
 * 		I will uss this class to inherent from.
 * 		Methods:
 *			1. display(bool print_grid = false): If true, then the member will
 *							     print a grid around the 
 *							     element.
 * 			2. search_around(int, int): This will search 
 * 						    around the point given and print
 * 						    the contents of the adjacent elemnts.
 *
 * Learning resource: Learn cpp 13.1 - 13.3
 * **************************************************************************************/
#ifndef _2D_ARRAY_HPP
#define _2D_ARRAY_HPP

#include <cassert>
#include <iostream>
#include <vector>

// ===================
// Class templates: 
// ===================

// Purpose of this class.

/* 
 Why do we need class templates? It enables us to build containers to store data of
 different types but that are very similar in functionality.
 Note that the compiler creates a template instance of an object if is used by the 
 program. Because cpp compiles files seperatly, we need to add our implementation
 file along with our header file in a .hpp file.
*/


// List of member functions:


// In this context the 'class' and 'typename' keyword has the same meaning.
// It is best practises to use the 'class' keyword here and 'typename' with 
// function templates.
template <class T>
class _2d_Array{
public:	// This will represent the array.
	// This is an array of vectors. "vector of vectors"
	std::vector< std::vector<T> > m_array;
	// This function will be used to print the contents of the array.
public: 
	// Overloaded operators:
	// =====================
	
	// A) Assignement operators.
	// =========================
	// 1. The standard one is deleted for now.
	_2d_Array& operator=(const _2d_Array&) = delete;
	// 2. This one will be used to insert one data type into the array.
	_2d_Array& operator=(T);

	// =====================
	// Displaying the array.
	// =====================
	// 1. This print will list all the elements.
	void print() const ;
	// =============
	// Constructors:
	// =============
	// 1. Default: Will intialize the std::vector with out any elements.
	_2d_Array();
	// 2. Version 1: This will construct the array with a given size.
	_2d_Array(int);	
	// 3. Version 2: This will construct the array of a set size with uniform elements.
	_2d_Array(T, int = 1);
	// ============
	// Destructor:
	// ============	
	~_2d_Array();
};


/* ***************************************************************************************
 * Function name: operator=() 
 * Version: 2
 * Description:  This assignment will insert one element inside the array at the back
 * 		 because it makes use of the push_back() member function from
 * 		 std::vector.
 * Parameters: <template T>
 * Pre-conditions: -
 * Post-conditions: -
 * **************************************************************************************/
template <typename T>
_2d_Array<T>& _2d_Array<T>::operator=(T var){
	// This will insert the element at the end of the constainer.
	m_array.push_back(var);
}

// You function can take in just one template parameter.
/* ***************************************************************************************
 * Function name: print() 
 * Description: This function will be used to list the contents of the area. See display()
 * 		for other version to ouput the contents of the array to the screen. 
 * 		This function is for development purposes and should not be used for
 * 		an application.
 * Parameters: -
 * Pre-conditions: Assumes that the array constains data.
 * Post-conditions: -
 * **************************************************************************************/
// == Remember that to add the template parameters in the definition outside of the class
//    as well. ==
template <typename T>
void _2d_Array<T>::print() const{
	std::cout << std::endl;
	for(int i = 0; i < m_array.size(); i++){
		// Remember that the type that is stored inside the container needs
		// to be able to be outputted with the operator<<().
		std::cout << m_array[i] << std::endl;
	}
	std::cout << std::endl;
}


// ===================
// Constructors:
// ===================
/* ***************************************************************************************
 * Function name: Array() 
 * Version: default
 * Description: This will be the default constructor. It will intialise the std::vector
 * 		array as if you normally initalize the vector. 
 * Parameters: - 
 * Pre-conditions: -
 * Post-conditions: -
 * **************************************************************************************/
template <typename T>
_2d_Array<T>::_2d_Array(){
	// Temporary.
	std::cout << "Default constructor for the Array." << std::endl;
}
/* ***************************************************************************************
 * Function name: Array() 
 * Version: 1
 * Description: This constructor will be used to create the Array with a given size passed
 * 		in as the parameter of the constructor. This constructor makes use of the
 * 		fact that the vector class can be instantiated in the same manner. 
 * Parameters: int: Size of the array.
 * Pre-conditions: -
 * Post-conditions: -
 * **************************************************************************************/
template <typename T>
_2d_Array<T>::_2d_Array(int n)
{
	assert(n > 0 && "[Unable to construct array]: Must have size of at leaste one");	
	m_array.reserve(n);
}
/* ***************************************************************************************
 * Function name: Array() 
 * Version: 2
 * Description: This constructor will construct the array with the set size and the 
 * 		uniform type that is passed as the first argument.
 * Parameters: int - size, and <typename T> .
 * Pre-conditions: -
 * Post-conditions: -
 * **************************************************************************************/
template <typename T>
_2d_Array<T>::_2d_Array(T variable, int n) 
{
	// Making sure that the array has at least one element.
	assert(n > 0 && "[Unable to construct array]: Must have size of at leaste one");	
	// This is to ensure that the vector does not resize every time that I insert
	// a new element. (See Cherno++ optimizating std::vector)
	m_array.reserve(n);
	// This fills the array with the uniform element passed by the constructor.

	// Note that n is used and not .size() because every time a use push_back()
	// the array grows.	
	for(int i = 0; i < n; i++){
		// This is better thatn push_back() becuase it does not copy the data
		// from main() to the places where vector wants to store it.
		std::cout << i << std::endl;
		m_array.emplace_back( T() );
	}
}


// ===================
// Desctructor:
// ===================
/* ***************************************************************************************
 * Function name: Array() 
 * Version: default
 * Description: The destructor is not yet needed for the container/class but will in the 
 * 		future be needed.
 * Parameters: - 
 * Pre-conditions: -
 * Post-conditions: -
 * **************************************************************************************/
template <typename T>
_2d_Array<T>::~_2d_Array(){
	// Temporary.
	std::cout << "Array is destructed" << std::endl;
}

#endif

