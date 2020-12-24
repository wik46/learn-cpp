/* **************************************************************************************
 * Filename: hourglass_sum.cpp 
 * Author: Lodewyk Jansen van Rensburg
 * Date: December 24, 2020
 * Description: These are all example questions from hackerrank.com. 
 * 		The purpose of the file is to study for an interview test.
 * *********************************************************************************** */
#include <iostream>
#include <vector>
/* **************************************************************************************
 * Question:
 * ---------
 * Given a 6x6 square matrix, an hourglass is the elements in a row of three columns 
 * 	followed by the middle colmn below the intial row, and then the 3 elements
 * 	in another column below.
 * The goal is to find the largest hourglass. An hourglass's size is determined by the 
 * sum of all its elements.
 * *********************************************************************************** */



/* ***********
 * Function name: sum_glass()
 * Description: This function will be used to sum the total of a single glass.
 * Parameters: std::vector<std::vector<int>>
 * Pre-conditions: The size of the 2d vector is assumed to be 6x6
 * 			- This function assumes that the hourglass is valid. That is we 
 * 			  cant index out of the vector's range.
 * 			- This function will be used in the larger hourglassSum() funtion
 * 				as a wrapper function.
 * Post-conditions: The function returns the sum of a single hour glass.
 * **********/
template <typename T>
int sum_glass(int m, int n, const std::vector<std::vector<T> >& v ){
	// This variable will be used to store the total sum.
	int total = 0;
	// We sum all the elements in the hourglass.
	const short hourglass_dim = 3;
	for(int i = 0; i < hourglass_dim; i++){
		for(int j = 0; j < hourglass_dim; j++){
			// We only want the middle element when summing the 3x3 cube
			// that outline the array.
			if(i != hourglass_dim/2 || i == j){
				total += v[m + i][n + j];
			}
		}
	}
	// Lastly we return the size of the hourglass.
	return total;
}
/* **************************************************************************************
 * Function name: hourglassSum()
 * Description: This function return the largest hourglass within a 6x6 square matrix.
 * Parameters: std::vector<std::vector<int> >
 * Pre-conditions: The function make use ot the sum_glass() function defined above.
 * Post-conditions: The function return the largest hourglass within the matrix.
 * *********************************************************************************** */
int hourglassSum( const std::vector<std::vector<int> >& vec){
	// This will be used to store the current max and the current hourglass value.
	int current_glass = sum_glass(0, 0, vec);
	int max = current_glass;
	// Now we find the max by iteration throught the 4X4 left upper part of the 
	// square matrix.
	// This is the size of an hourglass. (3x3)
	const short hourglass_dim = 3;
	for(int i = 0; i <= vec.size() - hourglass_dim; i++){
		// We assume a square matrix.
		for(int j = 0; j <= vec.size() - hourglass_dim; j++){
			// Size of the current hourglass.
			current_glass = sum_glass(i, j, vec);
			std::cout << "Current: " << current_glass << std::endl;
			// We determine if the current glass is larger then the max.
			if(current_glass > max){
				max = current_glass;
			}
		}
	}
	// Lastly we return the sum of the largest hourglass.
	return max;
}
// Demonstration of code.
int main(){
	// This is one vector that is used as a test case.
	std::vector<int> v1 = {0, -4, -6, 0, -7, -6};
	std::vector<int> v2 = {-1, -2, -6, -8, -3, -1};
	std::vector<int> v3 = {-8, -4, -2, -8, -8, -6};
	std::vector<int> v4 = {-3, -1, -2, -5, -7, -4};
	std::vector<int> v5 = {-3, -5, -3, -6, -6, -6};
	std::vector<int> v6 = {-3, -6, 0, -8, -6, -7};
	
	// this is the 2d vector.
	std::vector<std::vector<int> > v(6);
	v[0] = v1;
	v[1] = v2;
	v[2] = v3;
	v[3] = v4;
	v[4] = v5;
	v[5] = v6;
	for(int i = 0; i < v.size(); i++){
		for(int j = 0; j < v.size(); j++){
		std::cout << v[i][j] << ' ';
		}
		std::cout << std::endl;
	}

	// Now we test out function.
	std::cout << "Max: " << hourglassSum(v) << std::endl;
	return 0;
}
