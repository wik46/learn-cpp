/***************************************
 *Program Filename: array.cpp
 *Author: Wikus
 *Date: 10 July 2020
 *Description: Learning arrays
 *Input
 *Output
 **************************************/

//ARRAY 
//
//An array is just a pointer. If you specify an integer array, you have and integer pointer
//Also an array is a continuous bloack of memory.



#include <iostream>
#include <cstdlib>

//Function prototypes
int average(int employee_array[],int length);
void add_list(char first[], char second[], int total[], int length);
void swap(int array[], int m, int n);
int min_elem(int array[],int start, int length_array);
void selection_sort(int array[], int length);


int main(){

//The type def keyword
// This keyword lets me create another name for c++ standard keywords 
// now_my_int can be used as the keyword int
typedef int now_my_int;
now_my_int variable = 10;
std::cout << variable << std::endl;

//====================
//Intro to arrays
//===================	
	
	//Example 1 
	//============================
	
	//Remember to avoid hard coding
	const int num_employees = 6;
	// This typedef keyword lets us chaned the names of normal keyword
	typedef int  hours_array[num_employees];	
	hours_array week1;
	hours_array week2;
	
	// This function will calculate the average of hours worked per person in a week
	//this code will let the user enter the value for my array
	int ave = average(week2,6);	
		
	// This displays the data entered
		std::cout << "average hours worked per person this week: " << ave << " hours/person." << std::endl;
	
	//Exaple 2
	//========================
	// I am declaringthese arrays to use in my add_list()	
	char six[6] = {10,20,30,40,50,60};
	char five[6] = {1,2,3,4,5,6};
	int total[6];
	//This fuction adds the elements in six and five and stores the values in total
	add_list(six, five, total, 6);	


	//Example 3 
	//=======================
	
	// A common problem with arrays is that we want to sort them in accending or deccending order
	// ===========================
	// We accomplish this task using the following method called Selection Search
	//1. The idea behind the search is to start with element i.
	//2. then look through all the other elements.
	//3. If an element smaller than i is found, replace that element with i.
	//4. if not leave the element and continue to the next one.
	//5. Continue this process untill you have iterated through the array.
	
	//Selection sort	
	
	int test[10] = {-10,2,3,4,2,2,3,1,2,-5};
	swap(test, 2,0);
	std::cout << "I want a 3: " << test[0] << " and I want a -1: " << test[2] <<std::endl;
	std:: cout << "The min value: " << min_elem(test,3,10) << std::endl;
	
//########################
//Still in progress , the selection sort does not work see miller lecture on arrays
	selection_sort(test,10);

	return 0;
}

/********
 *Function name: average
 *......
********/
int average(int employee_array[], int length){
	//Here we retrieve data from user on how much the employees have worked
	for(int i = 0; i < length; i++){
		std::cout << "How many hours did employee  " << i+1 << " work." << std::endl;
		std::cin >> employee_array[i];
	}	
		
	//Here we calculate the average
	float average_pp = 0;
	for(int i = 0; i < length; i++){
		average_pp += (float)employee_array[i]/length;	
		std::cout << "Inside func:"<< average_pp << std::endl;
	}		
	return average_pp;
}
/********
 *Function name: add_list()
 *......
********/

//I want to add the elements in the first and second array and out it in a new array

void add_list(char first[], char second[], int total[], int length){
	for(int i = 0 ; i < length; i++){
		total[i] = first[i] + second[i];
	}
	for(int i = 0; i < length; i++){	
		std::cout << "index: " << i << ": " <<total[i] << std::endl;
	}
}

/********************
 *Function name: selection_sort()
 *
 *
 ********************/

void selection_sort(int array[], int length){
	
	int start_search = 1; 
	for (int i = 0; i < length; i++ ){
		swap(array ,i , min_elem(array,i, length));
		std::cout << array[i] << std::endl;
	}
	for(int k = 0;k < length; k++){
		std::cout << array[k] << std::cout;
	}	
}

/********************
 *Function name: minimum()
 *Description: This function finds the minimum between two values
 *
 ********************/
//I want to find the smallest element in an array
int min_elem(int array[],int start, int length_array){
	int k = 0;
	for(int i = start - 1; i < length_array; i++){
		if(array[start] > array[i]){
			k = i;	
		}else{
			k = start - 1; 
		}
	}

	return array[k];
}

/**********************
 *Function name: swap()
 *Description: This function swaps eleminates in an array
 *Pre-conditions: Note that this only works for integer arrays
 *********************/

void swap(int array[], int m, int n){
	//this will swap elements in the array
	int temp = array[m];
	array[m] = array[n];
	array[n] = temp;
}
