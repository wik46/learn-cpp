/* ***************************************************************************************
 * File name: selection_sort_fun.hpp
 * Author: Lodewyk Jansen van Rensburg.
 * Date: Novemember 24,2020.
 * Description: This is a file that contains the code needed to use a selection
 * 		sorting algorithm.
 * Input: An 1D-array.
 * Ouput: The array is sorted and printed to the screen.
 * **************************************************************************************/

// ====================================
// Selection sort demonstration:
// ====================================

#include "selection_sort_fun.hpp"
#include <fstream>
#include <iomanip>
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
		array[i] = rand() % 1000;
		std::cout << i << ".) "<< array[i] << std::endl;
		file_out << i << ".) "<< array[i] << std::endl;
	}	
	file_out << std::endl;
	// =============================================
	// The sorting of the array.	
	// =============================================
	selection_sort(array, size);	
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
	// Closing the file.
	file_out.close();
	// Freeing dynamic memory.
	delete[] array;
	return 0;
}

