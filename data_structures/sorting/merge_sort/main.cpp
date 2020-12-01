/* ***************************************************************************************
 * Filename: main.cpp
 * Author: Lodewyk Jansen van Rensburg
 * Description: This is the first algorithm written to practise how to incorporate
 * 		a merge sort algorithm.
 * Date: November 23, 2020.
 * **************************************************************************************/
// ==============================================
// Merge sort:
// ==============================================


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
		size = std::stoi(tmp);
	}catch(...){
		std::cout << "[error]: Remember to input size as array as com arg" << std::endl;
		return -1;
	}
	// Random number will be inserted into the array.
	srand(time(NULL));
	
	// =============================================
	// This is so that the algorithm is printed to a file.
	std::fstream file_out("alg_result.txt", std::ios::out);
	// Just making sure the file was correctly opened.
	if(!file_out.is_open()){
		std::cerr << "File not opened" << std::endl;
		return -1;
	}
	// =============================================
	
	// Now for the start of the merge sort function.
	// =============================================
	int* array = new int[size];
	// Step 1: inserting random elements into the array.
	// =============================================
	std::cout << "\n*** Unsorted array ***\n"<< std::endl;
	file_out << "\n*** Unsorted array ***\n"<< std::endl;
	for(int i = 0; i < size; i++){
		array[i] = rand() % 30;
		std::cout << i << ".) "<< array[i] << std::endl;
		file_out << i << ".) "<< array[i] << std::endl;
	}	
	file_out << std::endl;
	// =============================================
	// The sorting of the array.	
	// =============================================
	int left = 0;
	int right = size - 1;
	merge_sort(array, left, right);	
	// =============================================
	
	// =============================================
	// Sorted array output.	
	// =============================================
	// 1. Output to console.	
	std::cout << "\n*** Sorted array ***\n"<< std::endl;
	// 2. Output to file.	
	file_out << "\n*** Sorted array ***\n"<< std::endl;
	// Outputting the number of lines of the file.
	file_out << size << std::endl;
	for(int i = 0; i < size; i++){
		// 1. Output to console.	
		std::cout << i << ".) " << array[i] << std::endl; // Printing to console.
		// 2. Output to file.	
		file_out << i << ' ' << array[i] << std::endl; // Printing to screen.
	}
	file_out << std::endl;
	
	// =============================================
	// Prime number output.	
	// =============================================
	// 1. Output to console.	
	std::cout << "\n*** Prime numbers ***\n"<< std::endl;
	// 2. Output to file.	
	file_out << "\n*** Prime numbers ***\n"<< std::endl;
	// Outputting the number of lines of the file.
	file_out << size << std::endl;
	int j = 1; // Just to display an index next to the ouput.
	for(int i = 0; i < size; i++){
		if(is_prime( array[i] )){
			// 1. Output to console.	
			std::cout << j << ".) " << array[i] << std::endl; // Printing to console.
			// 2. Output to file.	
			file_out << j << ' ' << array[i] << std::endl; // Printing to screen.
			j++;
		}
	}

	
	// =============================================
	// Closing the file.
	file_out.close();
	// Freeing dynamic memory.
	delete[] array;
	return 0;
}

