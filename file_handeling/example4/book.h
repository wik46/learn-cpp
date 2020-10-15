/* **************************************************************************************
 * Filename: book.h
 * Author: Wikus
 * Date: September 30, 2020
 * Description: Studying how to handle files in C++.
 * 		The interface file for the main program.
 * Input:
 * Output:
 * **************************************************************************************/

// The code for the book struct is from a CS 162 class at Oregon State University.

#ifndef BOOK_H
#define BOOK_H

#include <iostream>

struct Book{
	unsigned int pages{0};
	unsigned int pub_date{0};
	std::string title{"Default"};
	unsigned int num_authors{0};
	std::string* authors{NULL};
};

struct Library{
	Book* bk_ar{NULL};
	int num_of_books{0};
};

// Prints the info of a single book.
void print_info(Book*);

// This function prints all the names of the books in the library.
void print_names(Library*);

#endif
