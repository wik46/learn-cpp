/* ***************************************************************************************
 * Filename: part1_merge_fun.hpp
 * Author: Lodewyk Jansen van Rensburg
 * Description: This is the first algorithm written to practise how to incorporate
 * 		a merge sort algorithm.
 * Date: November 23, 2020.
 *
 *
 * **************************************************************************************/

// Merge sort:
/*
	The algorithm can be seen as two parts:
		1. Divide the initial algorithm into smaller pieces such that they
		   are small sorted arrays. An array of 1 element is by definition
		   sorted.
		2. Merge the array using a two finger algorithm. 
			**Two finger algorithm:
				a. You have two pointers to two sorted arrays.
				b. You compare the current two elements.
				c. You insert the smaller element into the new empty array
					at index = 0 and walk one element up 
					the array that had the smaller element.
				d. ------------
				e. Now you compare the array at the two new elements.
				f. Insert the smallest element in the array at index = 1;
		
*/
#ifndef PART_1_MERGE_FUN_H
#define PART_1_MERGE_FUN_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

template <typename T>
void merge(T*, int, int, int);


// This is commented out so that part2_sort.cpp does not have multiple mains.

/* ***************************************************************************************
 * Function name: merge()
 * Description: This function will be used inside the merge_sort() function.
 * 		The function takes two halves of an array and merges them together. 
 * 		(sorted).
 * 		It assumes that each half is sorted.
 * Parameters: array (ptr to the first element in the array), int left index ,int middle
 * 		index , right index.
 * Pre-conditions: Takes in array A from index l to r, and m (the midpoint).
 * 			Assumes that A[l:m] and A[m+1:r] is two sorted arrays.
 * Post-conditions: Combines the two sorted arrays as in inserted them into the original
 * 			array. Result, A is sorted.
 * **************************************************************************************/
template <typename T>
void merge(T* A, int l, int m, int r){
	// Part 1: Create temporary containers to sort the two halves of the array.
	// ==========================================================================	
	int s1 = m + 1 - l;
	int s2 = r - m;
	// The temporary left and right sorted arrays.
	T* L = new T[s1];
	T* R = new T[s2];
	// Part 2: Storing the original data into the temporary containers.
	// ==========================================================================	
	for(int i = 0; i < s1; i++){
		L[i] = A[ (l) + i ]; 
	}
	for(int j = 0; j < s2; j++){
		R[j] = A[ (m + 1) + j];
	}
	// Part 3: Sorting the original container.
	// ==========================================================================	
	/* These variable will keep track of each array's index.*/
	// Left array.
	int i = 0;
	// Right array.
	int j = 0;
	// Original array.
	int k = l;
	while(i < s1 && j < s2){ // I want to loop untill the shortest temp array.
		// ----------------------------------------------------------------------------
		// This is the part of the algorithm where I define the condition of sort.
		// 	For this case it will sort in ascending order.
		// ** MAKE SURE THAT THE DATA TYPE IN THE ARRAY IS DEFINED FOR THID OPERATOR.
		// ----------------------------------------------------------------------------
		if( L[i] <= R[j]){ // The two finger algorithm.
			A[k] = L[i];	
			i++; // Walking along left array.
		}else{
			A[k] = R[j];
			j++; // Walking along right array.
		}
		// Walking along the original array.
		k++;
	}
	// Part 4: Adding the last elements of the container that had greate length.
	// ==========================================================================	
	while( i < s1 ){
		A[k] = L[i];	
		i++; // Walking the last part of the left array.
		k++; // Walking the last part of the original array.
	}
	while( j < s2 ){
		A[k] = R[j];
		j++; // Walking the last part of the right array.
		k++; // Walking the last part of the original array.
	}	
	// Part 5:Freeing the memory of the temporary containers.
	// ==========================================================================	
	delete[] L;
	delete[] R;
}

#endif
