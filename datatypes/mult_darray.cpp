/***************************************
 *Program Filename: mult_darrays.cpp
 *Author: Wikus
 *Date: 20 July 2020
 *Description: Learning about multi-dimensional arrays
 *Input
 *Output
 **************************************/

#include <iostream>
#include <cstdlib>



int main(){

	// this is a normal array
	int my_array[3];
	// I am defining a 2 dimensional array
	// An array is a pointer. A 2D-array is an array of pointers. Where each pointer points to an array.
	// Remember you create an pointer here
	int* my_2darray[3] ;
	
//I am setting each element in my array as an array
	for (int i = 0; i < 3;i++){
		my_2darray[i] = my_array;
	}

//EASY WAY TO CREATE AN 2D ARRAY
	
	int _2darray[4][3] = {
	{1,2,3},	
	{4,5,6}	,
	{7,8,9},
	{10,11,12}			};
		
//THIS IS HOW TO PICTURE YOUR ARRAY
//
//	[0][0]  [0][1]  [0][2]
//      [1][0]  [1][1]  [1][2]  
//	[2][0]  [2][1]  [2][2]
//	[3][0]  [3][1]  [3][2]
		
		
		
		
		
	// note the size difference
	std::cout <<sizeof(my_array) << std::endl;
	std::cout <<sizeof(my_2darray) << std::endl;
	
	// this will print row 1 collumn 2
	// remember we start from [0][0]
	std::cout << _2darray[1][2] << std::endl;
	return 0;
}

