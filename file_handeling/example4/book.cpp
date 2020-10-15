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

#include "book.h"
#include <iostream>

// This function lets me print the contents of the book.
void print_info(Book* bk){
	std::cout << "Title: " << bk->title << std::endl;
	std::cout << "Publication data: " << bk->pub_date<< std::endl;
	std::cout << "Number of Pages: " << bk->pages << std::endl;
	std::cout << "Number of Authors: " << bk->num_authors << std::endl;
	for(int i = 0; i < bk->num_authors; i++){
		std::cout << i << ") " << bk->authors[i] << std::endl;
	}
}	

// This function prints all the names of the books in the library.
void print_names(Library* lib){
	for(int i = 0; i < lib->num_of_books; i++){
		std::cout << i << ") " << (lib->bk_ar[i]).title << std::endl;
	}
}

// Delete the dynamic array of authors.

