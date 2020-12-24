/* **************************************************************************************
 * Filename: min_max_sum.cpp 
 * Author: Lodewyk Jansen van Rensburg
 * Date: December 23, 2020
 * Description: These are all example questions from hackerrank.com. 
 * 		The purpose of the file is to study for an interview test.
 * *********************************************************************************** */
#include <iostream>
#include <cstdlib>

/* **************************************************************************************
 * Function name: printMinMax()
 * Description: Print the  smallest sum of five numbers and the largest sum of 
 * 		5 numbers.
 * *********************************************************************************** */
void printMinMax(long* arr){
	// We find the largest ans smallest integer to subtract later from the sum.
	// The question specified that the array will by of size 5.
	short size = 5;
	// To store the elements found in the array.
	long min = arr[i], max = 0,total = 0; 
	for(int i = 0; i < size; i++){
		// This will save the minimum element.
		if(arr[i] < min){
			min = arr[i];
		}
		// This will save the maximum element.
		if(arr[i] > max){
			max = arr[i];
		}
		// We will use this as the base for the sum and then just subtract
		// the min variable to get the maximum sum and the min variable
		// to get the mimimu sum.
		total += arr[i];
	}
	// Now we print out the min and max sums.
	std::cout << total - max << ' ' << total - min << std::endl;
}

int main(){
	// Random number generator will be used to fill the array.
	srand(time(NULL));
	// We fill the array with random numbers.
	const short size = 5;
	long array[5];
	for(int i = 0; i < size; i++){
		array[i] = rand();
	}
	// We let the function do the work.
	printMinMax(array);

	return 0;
}
