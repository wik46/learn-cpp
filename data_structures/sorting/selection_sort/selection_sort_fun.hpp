/* ***************************************************************************************
 * File name: selection_sort_fun.hpp
 * Author: Lodewyk Jansen van Rensburg.
 * Date: Novemember 24,2020.
 * Description: This is a file that contains the code needed to use a selection
 * 		sorting algorithm.
 * Input: An 1D-array.
 * Ouput: The array is sorted and printed to the screen.
 * **************************************************************************************/

#include <iostream>
// ====================================
// Selection sort:
// ====================================

/*
	*** The Idea *** 
	(ascending order): You start with an array of length n.
			   Set i = 0;
		  	     a.  You find the smallest element in the array and set it to
			 	 A[i], then i++.
			     b. You then find the smallest element in A[i:n - 1]
				and set it equal to i, then i++.
			     c. You continue this process untill you reached the last element
				in the array.
	*** Time complexity ***
		- O(n^2).
	
	*** Auxiliry space ***
		- Never makes more than n swaps. Therefore is a good idea if memory swapping is 
		  costly.
*/ 
/* ***************************************************************************************
 * Function name: swap()
 * Description: An helper function to swap the elements.
 * **************************************************************************************/
template <typename T>
void swap(T* a, T* b){
	T tmp = *a;
	*a = *b;
	*b = tmp;
	return;
}
/* ***************************************************************************************
 * Function name: selection_sort()
 * Description: Simple sorting algorithm. Does no more than n swaps and is usefull 
 * 		when performance is limited.
 * Type: In place selection sort.
 * Advantages: Uses fewer right, therefore is used when performance is limited.
 * Disadvantages: Slow compared to insertion sort.
 * Parameters: An array and the size of an array.
 * **************************************************************************************/
template <typename T>
void selection_sort(T* A, int n){
	// Case 1: Ensure that the array is at least length 1.
	if( n < 1){	
		std::cerr << "[selection_sort()]: Error, "
		<< "cannot sort array of length < 1." << std::endl;
		throw -1;
	}
	// Case 2: The case for an array of length greater than 1.
	if(n > 1){
		int i = 0; // Start at the first index.
		int k = 0;
		int min_index = 0;
		for(int i = 0; i < n -1; i++){
			// If the current element at index i is less than the min element
			// 	the two will swap.	
			min_index = i; // Start with first index as miminum.
			// Start searching from the i + 1 th element because min_element = i;
			for( k = i + 1; k < n; k++){
				// You first find the minimum index.
				if(A[k] < A[min_index]){
					min_index = k; // This sets the new minimum index.
				}	
			}
			// Now you swap the mimum index.
			// i is the leftmost index.
			swap( &A[i], &A[min_index] );
				
		}
	}
	// Case 3: Array length 1 is already sorted and will return the sorted array.
	return;	
}
