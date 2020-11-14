/* ***************************
 * Filename: main.cpp
 * Author: Wikus
 * Date: 5 Sept
 * Desription: Comparing the time it takes to sum all the values between linked lists and arrays.
 * Input: Two different datastructures
 * Output: The difference in time to iterate through the data structure.
 * **************************/

#include "implementation.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

// This function sums all the elements in the array.
int total_sum(const int* array, const int size){
	int sum = 0;
	for(int i = 0; i < size; i++){
		sum += array[i];	
	}
	return sum;
}


int main(){
	long int data_struct_size = 900000000;

	{	
		double duration  = 0.0;
		// The timer starts here.
		std::clock_t start = std::clock();
		srand(time(NULL));
		// The array.
		int* array = new int[data_struct_size];
		// Inserting values into my array.
		for(int i = 0; i < data_struct_size; i++){
			array[i] = rand();
		}
		// This function sums all the integers in my array.	
		int result = total_sum(array, data_struct_size);
		// The timer ends here.
		std::clock_t end = std::clock();
		// The time used.
		duration = (double)(end - start)/CLOCKS_PER_SEC; // The amount of clocks passed is not consistand on different architecture.
						// This is the number of ticks per second.
		std::cout << " The duration of creating summing the array: " << duration << " seconds." << std::endl; 
		
		// Deleting the array.
		delete[] array;
	}
	{
		// The linked list.
		double duration  = 0.0;
		// The timer starts here.
		std::clock_t start = std::clock();
		// Creating an instance of an object.
		Linked_list ll(data_struct_size);
		// Summing through my list.
		int result = ll.total_sum();
		// The timer ends here.
		std::clock_t end = std::clock();
	
		// The time used.
		duration = (double)(end - start)/CLOCKS_PER_SEC; // The amount of clocks passed is not consistand on different architecture.
						// This is the number of ticks per second.
		std::cout << " The duration of summing the list: " << duration << " seconds." << std::endl; 

	}
}
