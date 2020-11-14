/***************************************
 *Program Filename: stack_heap.cpp
 *Author: Wikus
 *Date: 17 July 2020
 *Description: learing stack vs heap memory allocation
 *Input:
 *Output:
 ***************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "convert_to_int.cpp"

void printSize(int array[]){
	std::cout << "Size:[inside] " << sizeof(array)<< std::endl; 

}


int main(){
	// Always accept user input as a string
	std::string int_str = "";
	
	std::cout << "Please enter an integer: ";
	getline(std::cin,int_str);
	
	int user_int = convert_to_int(int_str);
	srand(time(NULL));
	int rand_num = rand() % 9 + 1;
	
	if(user_int){
		std::cout << "You entered: " << user_int << std::endl;
	} 

	int* array = new int[user_int];
	for(int i = 0; i < user_int; i++){
		array[i] = rand() % 900 + 100;
	}
	
	const int num_col = 4;
	for(int k = 0; k < user_int; k += 1){
		if (k%num_col == 0 ){
			std::cout << "\n";
		}
		std::cout << array[k] << "\t";
	}
	std::cout << std::endl;
	std::cout << "Random number: "<< rand_num << std::cout;
//============
// Statically allocated arrays
//============


	// An array is a pointer, pointing to the firts element in the array
	int array_t[5] = {1,2,3,4,5};
	std::cout << "Memory array_t[0]: " << &(array_t[0])<< " and memory of array_t: " << *(array_t+4) << std::endl;

	std::cout << "Size of: [outside function] " << sizeof(array_t) << std::endl;
	printSize(array_t); // Note the array_t is not copied into the function, it is implicitly casted into a pointer
				// Therefore the sizeof inside the function will be the size of the pointer
 
//============================
//Dynamically allocating arrays
//============================

	int* h_array = new int[user_int];
	h_array[2] = 10;
	std:: cout << "Heap array: "<<  h_array[2] << std::endl;	
	delete[] h_array;
	return 0;
}
