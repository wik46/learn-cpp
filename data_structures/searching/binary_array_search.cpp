/* ***************************************************************************************
 * Filename: binary_array_search.cpp
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
// Used inside merge_sort()
template <typename T>
void merge(T*, int, int, int);
// This uses a recursive merge sort algorithm.
template <typename T>
void merge_sort(T*, int, int);

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
	// NB! The data in the array must be sorted before we can use a
	// 	binaray search algorithm.
	merge_sort(array, 0, n - 1);
	print_ar(array, n);
	// ========================================================
	// Start of the binary searching algorithm for the program.
	// ========================================================
	// Implementation of the binary search algorithm.
	// Runtime complexity: O( log(n) )
	// The idea: We start with the middle index in the array.
	// 		1. If we found the value we were looking for we
	// 			return the value and end the search.
	// 		2. If the value we looking for is SMALLER 
	// 			than the middle, we only search
	// 			the bottom half of the array. Our array
	// 			is assumed to be sorted, therefore we
	// 			know the value must lie below the mid point
	// 			if it is inside our array.
	// 		3. If the value we are looking for is GREATER than
	// 			the midpoint we search the top half of our
	// 			array. Similiarly to the above mentioned, since
	// 			our array is assumed to be sorted we can conclude
	// 			that the value must be in the top half of the array
	// 			if it is inside our array.
	
	// Part 1: The user will enter the value that the program needs to search
	// 		for.
	// ** Taking user input. ** 
	int input = 0;
	std::cout << "Please enter a number to search for: ";
	std::cin >> input;
	// Part 2:
	// =================================================================
	// Implementation of the binary searching algorithm for the program.
	// =================================================================
	// Step 1: We start by finding the original bounds of the array.
	int left = 0;
	int right = n - 1;
	bool not_found = true; // This will be set to false if value found.
	// Step 2: We start our search.
	// ** Note we keep on searching untill our left bound is greater
	// 	than our right bound.
	while(left <= right){
		// This is to calculate the midpoint on each iteration.
		// Make sure that you calculate the midpoint correctly to avoid of
		// 	by one errors.
		int midpoint = (right + left) / 2;
		// Case 1: The value we are looking for lies on the midpoint.
		if( input == array[midpoint] ){
			// We can stop our search because we found it.
			std::cout << "[Search successful]: It found : "<<
			array[midpoint] << " at index " << midpoint << " ."<< std::endl;
			// Set the not_found = false so that I know I found
			// 	the value.
			not_found = false;
			// Exit the loop because we do not need to search anymore.
			break;
		// Case 2: The midpoint lies above our desired target value.
		}else if( input < array[midpoint] ){
			// a. Set the new upper bound.
			// We know that we only need to search between the values
			// that are less than the midepoint.
			right = midpoint - 1; // Note that right is the new last index.
		// Case 3: The midpoint lies below our target value.
		}else if( input > array[midpoint] ){
			// a. Set the new lower bound.
			// We do not have to search between the values smaller
			// 	than the midpoint or at the midpoint itself.
			left = midpoint + 1;
		}
	}
	// This is only to output to the programmer if the value is inside
	// 	the array.
	if(not_found){
		std::cout << "** Your value " << input << " was not found.**\n" 
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

/* ***************************************************************************************
 * Function name: merge_sort()
 * Description: This is a merge sort function for an array that is needed to
 * 		sort the data before we can use it on binary search. In CS162 we
 * 		study insertion, selection, bubble, and merge sort. I choose to implement
 * 		merge sort to get further practise on it.
 * Parameters: T* array, int left_index, int right_index.
 * Pre-conditions: Merge sort has two parts:
 * 			1. Divide: Split the array untill only one element 
 * 					is reached.
 * 			2. Conquer: Merge the sorted arrays where an array of 1 element
 * 				    is by definition sorted.
 * Post-conditions: Returns a sorted array.
 * **************************************************************************************/
template <typename T>
void merge_sort(T* array, int l, int r){// left and right indices.
	// Base case: no need to sort an empty array or array of size 1.
	if(l >= r){
		return;
	}
	// Now we calculate the middle of the array.
	int middle = (l + r -1)/2 ; 
	// Now we divide the two sub arrays.
	// This will keep merging the array untill an array of size 1 is reached.
	merge_sort(array, l, middle);
	merge_sort(array, middle + 1, r);
	// Lastly we conquire by merging the two sorted arrays.
	merge(array, l, middle, r);
	return;
}
/* ***************************************************************************************
 * Function name: merge()
 * Description: This function is used inside merge_sort(). It it the conquer part of the
 * 		algorithm. It assumes that the two arrays obtained after splitting
 * 		them is already sorted. It then makes use of the two finger algorithm
 * 		to combine it in one single array.
 * Parameters: T* array, int left_index, int middle_index, int right_index.
 * Pre-conditions: This function is used insde merge_sort() when it comes
 * 		    time to execute the conquer part of the algorithm.
 * Post-conditions: Merges two sorted arrays into a single sorted array.
 * **************************************************************************************/
template <typename T>
void merge(T* array, int left_index, int middle_index, int right_index){
	// Base case: Array length 1 is by definition sorted.
	if( left_index >= right_index){
		// No need to sort array of length 1.
		return;
	}
	// Case for array of length > 1.
	// Step 1: Create temporary containers to store the left and right
	// 	 - already sorted - arrays.
	int size_l = (middle_index + 1) - left_index;
	int size_r = right_index - middle_index;
	// 1. Creating the temporary containers.
	T* tmp_l = new T[size_l]; 
	T* tmp_r = new T[size_r]; 
	// 2. Now I store the data from the original arrays into the new arrays.
	// a.
	int j = 0;
	// Remember that the left index is not always zero, Therefor i starts
	// from the left index.
	for(int i = 0; i < size_l; i++){
		tmp_l[i] = array[left_index + i]; // Storing array[ left_index: middle ] in tmp 
				     // container	
		j++;	 // This is used to access tmp_l from 0.
	}
	// b.
	for(int i = 0; i < size_r; i++){
		tmp_r[i] = array[middle_index + 1 + i];  
	}
	// Variables needed for step three.
	int i_l = 0; // Use to keep index of tmp_l
	int i_r = 0; // Use to keep index of tmp_r
	int k = left_index; // Use to keep index of array.
	// 3. Storing sorted data inside the original container.
	while(i_l < size_l && i_r < size_r){ /* Only loop for smallest sub array*/
		// This is where the algorithm makes the call on ascending/ descending.
		if(tmp_l[i_l] <= tmp_r[i_r]){
			// If the left array's element is smaller.
			// insert the element in the original array.
			array[k] = tmp_l[i_l];
			// Now walk up the left array.				
			i_l++;
		}else{
			// The right array's element was smaller.
			// Insert it into the original array.
			array[k] = tmp_r[i_r];
			// Walk one element up the right array.
			i_r++;
		}	
		// This will occure after each iteration.
		k++; // walking along in original array.
	}
	// If the data was in a manner that most of the small elements was in
	// one of the subarrays, then there will be elements left over in the other
	// one. Therefore we need to make sure that we collect all the elements back
	// in our original array.
	
	// Case if left array is left with all the larger values.
	while( i_l < size_l ){
		array[k] = tmp_l[i_l];
		// Walking along the the sub array.
		i_l++;
		// Walking along the original array.
		k++;
	}
	// Case if the right array was left with all the values.
	while( i_r < size_r ){
		// Inserting the last bit of the right sub array into the original array.
		array[k] = tmp_r[i_r];
		// Walking along the right sub array and original array, respectively.
		i_r++;
		k++;
	}
	// Lastly we free the memory used by the two containers.
	delete[] tmp_l;
	delete[] tmp_r;
	// End of function.
	return ;
}

