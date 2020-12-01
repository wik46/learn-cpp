/* ***************************************************************************************
 * Filename: with_struct.cpp
 * Author: Lodewyk Jansen van Rensburg.
 * Description:
 * Input:
 * Output:
 * **************************************************************************************/

#include <iostream>
#include <fstream>

// This struct will represent a single student.
struct student{
	long int id_num{0};
	std::string first_name{""};
	std::string last_name{""};
	std::string major{""};
};

// This struct is used so that the size of the student array is contained
// in the same object as the name of the array.
struct student_array{
	student* s_ar{NULL};
	int num_students{0};
};


// Get data from
/*
 * Function name: swap()
 * Description: This function is used to swap the values of two integers.
 * Parameters: int*, int*
 * Pre-conditions:
 * Post-conditions:
 */
void swap(long int* a,long int* b){
	long int tmp = *a;
	*a = *b;
	*b = tmp;
}	

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
			swap(&(s_ar[i].id_num), &(s_ar[tracker].id_num));
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
void delete_student_db_info(student* ar_of_s){
	if(ar_of_s != NULL){
		delete[] ar_of_s;
	}
}

