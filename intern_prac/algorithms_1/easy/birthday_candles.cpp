/* **************************************************************************************
 * Filename: birthday_candles.cpp
 * Author: Lodewyk Jansen van Rensburg
 * Date: December 23, 2020
 * Description: These are all example questions from hackerrank.com. 
 * 		The purpose of the file is to study for an interview test.
 * *********************************************************************************** */
#include <iostream>
#include <cstdlib>
#include <vector>
/*
	Question:
	---------
	You are in charge of the cake for a child's birthday. 
	You have decided the cake will have one candle for each year of their total age. 
	They will only be able to blow out the tallest of the candles. 
	Count how many candles are tallest.
*/

/* **************************************************************************************
 * Function name: birthday_candles()
 * *********************************************************************************** */
template <typename T>
void birthday_candles(std::vector<T> arr){
	// We first find the tallest brithday candle.
	int max = 0;
	for(int i = 0; i < arr.size(); i++){
		if(arr[i] > max){
			max = arr[i];
		}
	}
	// Now we count the number of tallest candles on the birthday cake.
	int count  = 0;
	for(int i = 0; i < arr.size(); i++){
		if(max == arr[i]){
			count++;
		}
	}
	// Lastly we print out the number of tallest candles.
	std::cout << count << std::endl;
	return;
}

// Demonstration of the program.
int main(){
	// Random number generator will be used to fill the array.
	srand(time(NULL));
	// We fill the array with random numbers.
	const short size = 10;
	std::vector<int> vec;	
	for(int i = 0; i < size; i++){
		vec.push_back(rand() % 4);
		std::cout << vec[i] << std::endl;
	}
	std::cout << std::endl;
	// Print out the number of tallest candles.
	birthday_candles(vec);
	return 0;
}
