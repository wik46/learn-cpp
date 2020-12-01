/* *
 * Filename: student_db.h
 * Author: Lodewyk Jansen van Rensburg.
 * Description:
 * Input:
 * Output:
 * */

#ifndef STUDENT_DB_H
#define STUDENT_DB_H

#include <fstream>
#include <iostream>

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

// Create an array of students.
student* create_student_db(int);

// Get data from
void get_student_db_info(student*, int, std::fstream&);

// Opens th file and makes sure that is is opened correctly.
void get_and_open_user_file(std::fstream* fin);

// This function is used to swap the values of two integers.
void swap(int* a, int* b);

// Sorts the id numbers of the students.
void quick_sort(student* s_ar, int first, int last);

// This function used quick_sort() to help sort the students by id.
void sort_by_id(student_array* all_st);
// This function writes all the data in the student array to a file
// 	associate with fout.
void write_to(student_array* all_st, std::fstream* fout);

// This deletes the student array created by create_student(). 
void delete_student_db_info(student* ar_of_s);

#endif
