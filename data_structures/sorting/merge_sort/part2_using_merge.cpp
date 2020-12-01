/* ***************************************************************************************
 * Filename: part2_sorting.cpp
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
#include "part1_merge_fun.hpp"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
int main(int arc, char** argv){
	// This is just so that I can specify the size of the array with commandline input.
	int size = 0;
	try{
		std::string tmp = argv[1];
		int size = std::stoi(tmp);
	}catch(...){
		std::cout << "[error]: Remember to input size as array as com arg" << std::endl;
		return -1;
	}
	// Random number will be inserted into the array.
	srand(time(NULL));
	// Now for the start of the merge sort function.
	// =============================================
	int* array = new int[size];
	// Step 1: inserting random elements into the array.
	for(int i = 0; i < size; i++){
		array[i] = rand() % 30;
	}	
	
	int ar2_size = 11;
	// These are the inputs that the function will take.
	int m = (ar2_size ) / 2;
	int l = 0;
	int r = ar2_size - 1;
	int array2[] = {1,2,3,4,5,13,2,4,6,10,23};
	// ----------------------
	// Print unsorted array.
	// ----------------------
	std::cout << "\n*** Unorted array ***\n"<< std::endl;
	for(int i = 0; i < ar2_size; i++){
		std::cout << i << ".) " << array2[i] << std::endl;
	}
	// =============================================
	// Part 1: The merge function body.
	// Given an array that is sortd from A[0:m] and A[m+1:r]
	// 	merge them into a storted array.
	// =============================================
	// Step 1:
	// We can assume that the left an right array is sorted.
	// Create temporary data to store it.
	// Now we print the entire array and see if we managed to sort it properly.
	
	merge(array2, l, m, r);
	std::cout << "\n*** Sorted array ***\n"<< std::endl;
	// This is so that the algorithm is printed to a file.
	std::fstream file_out("alg_result.txt", std::ios::out);
	// Just making sure the file was correctly opened.
	if(!file_out.is_open()){
		std::cerr << "File not opened" << std::endl;
		return -1;
	}
	// Inputting the number of lines of the file.
	file_out << ar2_size << std::endl;
	for(int i = 0; i < ar2_size; i++){
		std::cout << i << ".) " << array2[i] << std::endl; // Printing to console.
		file_out << i << ' ' << array2[i] << std::endl; // Printing to screen.
	}
	// Closing the file.
	file_out.close();
	delete[] array;
	return 0;
}
