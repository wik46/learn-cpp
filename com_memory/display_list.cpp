/******************************************************
 * File name: display_list().cpp
 * Author: Wikus
 * Date: 24 July 2020
 * Description: Writing a function that displays a table
 * Input
 * Output:
 *****************************************************/

#include <iostream>










/******************************************************
 * Function name: display_list() 
 * Description: Writing a function that displays a table
 * Parameters: 
 * Input
 * Output:
 *****************************************************/


void display_list(int array_size, int* array){
	const int num_col = 4;
	for(int k = 0; k < array_size; k += 1){
		if (k%num_col == 0 ){
				std::cout << "\n";
		}
		std::cout << array[k] << "\t";
	}
	std::cout << std::endl;
}
