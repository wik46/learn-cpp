/* ***************************************************************************************
 * Filename: student_db.cpp
 * Author: Lodewyk Jansen van Rensburg.
 * Description:
 * Input:
 * Output:
 * **************************************************************************************/

#include "student_db.h"
#include <fstream>
#include <iostream>

/* **************************************************************************************
 * Function name: create_student_db();
 * Description: This function creates a dynamic array of students of a specified size.
 * Parameters: int.
 * Pre-conditions: -
 * Post-conditions: Returns the the pointer to the first element of a dynamic 
 * 			student array.
 * **************************************************************************************/
student* create_student_db(int num_students){
	return new student[num_students];
}
/* **************************************************************************************
 * Function name: get_student_db_info()
 * Description: This function retrieves information from the file associated with the
 * 		stream object passed in as reference to the function.
 * Parameters: student*, in, fstream&
 * Pre-conditions: The fstream object needs to be associated with a file prior
 * 			to the function calling the object.
 * Post-conditions: The data from the file associated with the stream object is stored in 
 * 			the array of students.
 * **************************************************************************************/
void get_student_db_info(student* s_ar, int num_students, std::fstream& fin){
	//s_ar = create_student_db(num_students);
	int i = 0;
	while(!fin.eof()){
		if(i == num_students){
		//	break;
		}	
		// s_ar[i].id_num is of type long int.
		fin >> s_ar[i].id_num;
		// Gathering data.
		fin >> s_ar[i].first_name >> s_ar[i].last_name 
		>> s_ar[i].major;
		i++;
	}	
}
/* ***
 * Function name: get_and_open_user_file()
 * Description:
 * Parameters:
 * Pre-conditions:
 * Post-conditions:
 * *****/

void get_and_open_user_file(std::fstream* fin){
	std::string input_data = "";
	std::cout << "Please enter the name of the file here: ";
	std::cin >> input_data;
	// This opens the file that the user provided.
	fin->open(input_data, std::ios::in);
	// This condition will make sure that the file entered by the
	// 	user exist and is opened correctly.
	if(fin->is_open()){
		std::cout << "File open succesfull." << std::endl;
		return;
	}else{
		std::cout << "File open unsuccessful." << std::endl << std::endl;
		get_and_open_user_file(fin);
		return;
	}
		
}
/*
 * Function name: swap()
 * Description: This function is used to swap the values of two integers.
 * Parameters: student*, student*
 * Pre-conditions:
 * Post-conditions:
 */
void swap(student* a,student* b){
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

/*
 * Function name: quick_sort()
 * Description: This is modified to take in an array of students and sort the students
 * 		by ID-number in ascending order.
 * Parameters:
 * Pre-conditions:
 * Post-conditions:
 */
void quick_sort(student* s_ar, int left, int right){
	// The base case. It is not needed to sort an array of length one.
	if(right - left <= 1){
		return;
	}
	// Getting my pivot point. All the elements smaller/ equal to the pivot point
	// 	will go to the left subarray and the rest will be at the right subarray.
	// I am taking the last element in the array as my pivot point.
	int pivot = s_ar[right].id_num;
	// This tracker will help me swap my elements in the array.
	int tracker = left;
	for(int i = left; i <= right; i++){
		if(s_ar[i].id_num <= pivot){
			swap(&(s_ar[i]), &(s_ar[tracker]));
			tracker++;
		}
		// Note that tracker will end on the value
		// will end with the value tracker = pivot + 1 becuase s_ar[].id_num <= pivot.
	}
	// Now I will recuresively call the function to sort the left and right subarray.
	// 1. Sorting the left subarray.
	quick_sort(s_ar, left, tracker - 2);
	// 2. Sorting the right subarray.
	quick_sort(s_ar, pivot, right);
}
	
/*
 * Function name: sort_by_id()
 * Description:
 * Parameters:
 * Pre-conditions:
 * Post-conditions:
 */
void sort_by_id(student_array* all_st){
	// This is to get the first index and the last index of the array.
	int f_index = 0;
	int l_index = all_st->num_students - 1;
	// An implementation of a quick sort algorithm.
	quick_sort(all_st->s_ar, f_index, l_index);
}

/*
 * Function name:
 * Description:
 * Parameters:
 * Pre-conditions:
 * Post-conditions:
 */



/*
 * Function name:
 * Description:
 * Parameters:
 * Pre-conditions:
 * Post-conditions:
 */
void write_to(student_array* all_st, std::fstream* fout){	
	// Inserting the student data.
	for(int i = 0; i < all_st->num_students;i++){
		*fout << all_st->s_ar[i].id_num
		<< ' ' << all_st->s_ar[i].first_name
		<< ' ' << all_st->s_ar[i].last_name
		<< ' ' <<all_st->s_ar[i].major << std::endl;
	}
}


/*
 * Function name:
 * Description:
 * Parameters:
 * Pre-conditions:
 * Post-conditions:
 */
void delete_student_db_info(student* ar_of_s){
	if(ar_of_s != NULL){
		delete[] ar_of_s;
	}
}

