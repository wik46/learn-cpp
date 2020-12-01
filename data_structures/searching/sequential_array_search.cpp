/* ***************************************************************************************
 * Filename: sequential_array_search.cpp
 * Author: Wikus Jansen van Rensburg
 * Date: November 30, 2020.
 * Description: This is a file to start studying searching algorithms.
 * 		All that is happening in this file is I am creating an array
 * 		of size n fille with random numbers. Thereafter the program will
 * 		prompt the user to enter a number and the program will
 * 		return the number if it is in the array of random numbers.
 * Learning Resource: Searching algorithms (Medium.com - Pulsara Sandeepa)
 * **************************************************************************************/

#include <iostream>
#include <exception> // To use the basic exception class
#include <cstdlib> // To use the random number generator.
#include <ctime>  // The function needed to seed the random number generator.

// Function defined below main().
// Helper function to print the array.
template <typename T>
void print_ar(T*, int);

int main(int argc, char** argv){
	// This is only to ensure that the user entered a value for the size
	// of the array as a commandline argument.
	// n will be the size of the array.
	int n = 0; 
	int* array = NULL;
	try{
		// This will ensure that the user enters the correct input.
		if(argc > 1){	
			n = std::stoi(argv[1]);
		}else{
			throw "[error]: Remember to enter size of the array as com arg.";
		}
		// Creating a new array based on the size entered by the user.
		// new will throw an exception if the allocation is unsuccessful.
		array = new int[n];
		std::cout << "Array of size : " << n << " allocated. " << std::endl;
	}catch(std::exception a){
		// The case when the user did not enter a valid integer.
		std::cerr << a.what() << std::endl;
		return -1;
	}catch(const char* a){
		std::cerr << a << std::endl;
		return -1;
	}	
	// Seeding the random number generator.
	srand(time(NULL));
	
	// ========================================================
	// Start of the searching algorithm portion of the program.
	// ========================================================
	// 1. Setting random values inside the array.
	for(int i = 0; i < n; i++){
		array[i] = rand() % 100;
	}
	// 2. Printing out the contents of the array.
	print_ar(array, n);
	
	// ========================================================
	// Start of the searching algorithm for the program.
	// ========================================================
	// 1. This is a sequantial searching algorithm. It will search the entire array 
	// 	untill the number entered was found or the end of the array was reached.
	// 	Stopping criteria: 1. First instance of element found. () 
	// 			   2. The end of the array was reached.
	// Taking user input.
	int input = 0;
	std::cout << "Please enter a number to search for: ";
	std::cin >> input;
	// Searching for user input.
	int i = 0; // We use i outside of the loop, therefore it needs to be declared outside the
			// scope of the for loop/
	for(; i < n; i++){
		if(array[i] == input){
			std::cout << "\n\nYour input is found: " << array[i] << std::endl;	
			std::cout << "First instance at index: " << i 
			<< std::endl << std::endl;
			break; // This is to stop searching.
		}
	}
	// If this condition is true then we did not find the data the user entered
	// 	in the array.
	// This means that the for loop stopped becuase i was equal to n and we did
	// 	not find the element the user search for.
	if(i >= n){
		std::cout << "\nSorry your input: " << input << " was not found.\n" 
		<< std::endl;
	}
	

	
	// ========================================================
	// Freeing the memory used by te array.
	// ========================================================
	if(array){ // Only want to free the memory if it was allocated.
		delete[] array; // remember delete[] with the '[]' when freeing an array.
	}
	return 0;
}

// This function is used to print the content of the array.
// Only using templates to become more familiar with using them. Not needed for 
// 	this basic program.
template <typename T>
void print_ar(T* ar, int n){
	for(int i = 0; i < n; i++){
		std::cout << i + 1 << ".) "<<  ar[i] << std::endl;
	}
}
