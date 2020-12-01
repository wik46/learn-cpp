/*
 * filename: exampe1.cpp
 * Author: Wikus
 * Description: This file is used to learn how to implement my own type of
 * 		sorting algorithm for an array of strings.
 *
 * */

#include "student_db.h"
#include <iostream>
// swap() is used inside quick_sort().
void swap(student* a, student* b){
	student tmp = *a;
	*a = *b;
	*b = tmp;
}

/* **************************************************************************************
 * Function name: is_before()
 * Description: This function determines if the first argument is listed before the second 
 * 		arguments alphabetically.
 * Parameters: string, string.
 * Pre-conditions: This function makes used of the function tolower().
 * Post-conditions: If the first argument is listed before the second argument 
 * 		    	alphabetically or if the arguments are 
 * 			identical, then the function will return true.
 * 		    Else return false.	
 * **************************************************************************************/
// is_before() will return true if the first argument is listed before the second argument
// 	alphabetically.
bool is_before(std::string a_str, std::string b_str){
	for(int i = 0; i < a_str.length() && b_str.length(); i++){
		if(tolower(a_str[i]) < tolower(b_str[i]) ){
			return 1;
		}else if(tolower(a_str[i]) > tolower(b_str[i]) ){
			// a_str is not listed higher than b_str.
			return 0;
		}
	}
	// This can be when identical strings are entered or the case for strings
	// 	like "jog" and "jogger" where "jog" is before "jogger".
	return 1;
}

/* **************************************************************************************
 * Function name: quick_sort_strings()
 * Description: This function accepts an array of structs and sorts the array
 * 		by the specified string members in alphabetical order.
 * Parameters: struct*, int, int.
 * Pre-conditions: This function needs an array of structs that contains string member
 * 			variables.
 * Post-conditions: The array passed in as the firts argument
 * 			is sorted alphabetically by the string members of the struct.
 * **************************************************************************************/
// This function is a quick sort implementation.
void quick_sort_strings(student* str_ar,int left, int right){
	// Base case. There is no need to sort an array of length 1.
	if(left >= right){
		return;	
	}
	// Here I am getting the pivot value. I am taking the last element in the
	// 	array.
	std::string pivot = str_ar[right].last_name;
	// This helps in swapping the correct index.
	int tracker = left;
	for(int i = left; i <= right; i++){
		//std::cout << str_ar[i].last_name << std::endl;
		if(is_before(str_ar[i].last_name, pivot)){
			swap(&str_ar[i], &str_ar[tracker]);
			tracker++;
		}
	}// Remeber the values of tracker is pivot + 1 here becuase.
	// Sorting the left subarray.
	quick_sort(str_ar, left, tracker - 2);
	// Sorting the right subarray.
	quick_sort(str_ar, tracker, right);
}


int main(){
	student s1;
	s1.last_name = "znton";
	student s2;
	s2.last_name = "Rugbynv";
	student s3;
	s3.last_name = "Rugantonv";
	student s4;
	s4.last_name = "Jacu";

	int size = 4;
	student* ar = new student[size];
	ar[0] = s1;
	ar[1] = s2;
	ar[2] = s3;
	ar[3] = s4;
	 
	quick_sort_strings(ar, 0,3);
	
	std::cout << std::endl;
	for(int i = 0; i < 4; i++){
		std::cout << ar[i].last_name << std::endl;
	}
	return 0;
}
