 /**************************************************
 *Program Filename: struct_cs161.cpp
 *Author: Wikus
 *Date: August 10, 2020
 *Description: This file was made after my cs 161 lecture on structs.
		This is very informative. 
 *Input
 *Output
 **************************************************/


#include <iostream> //Remember all that the #inlcude statement does is copy and paiste

// A. Define a struct outside a function


//The -> (arrow operator) is the same as (*ptr).textbook

//Keywords: int,double, struct, class, return, break, static, new.... ( Words that have special meaning to the compiler)

// The keyword struct: announces that this is a structure type definition;wq

// The identifier Book: is the name of the struct
// The name of a structure data type is called a struct tag. This tag can be any legal identifier but not a keyword

// A struct definition is always outside a function.
// A stuct is only for member variables whereas a class is for member variables and member functions(methods).

struct Book{
	// Member variables
	unsigned int num_pages;
	unsigned int pub_date;
	std::string title;
	std::string author1;
	std::string* authors; // A want to store all the authors names in a array of strings. (authors = new string[num_of_authors]

}; // Remeber the semi colon after the curly brace


int main(){
	
	// Example 1
	// =========
	// Declating a variable of type Book and giving it a name textbook
	Book textbooks[10]; // I am declaring an array that contains 10 variables of type Book.
				// The name of my array is textbooks.

	// Here I am setting the values of all ten textbooks in the array.
	// Note that the index i is next to the variable of type Book
	for(unsigned int i = 0; i < 10; i++){
		textbooks[i].num_pages = 100; // All the ten textbooks will have 100 pages.
		textbooks[i].pub_date = 1967 + i; // The books were published in different years.
	}

	// Working with the sixth element in the array of textbooks.
	textbooks[5].title = "Lord of the Rings";
	// I am declaring a pointer to a type Book.
	std::string author_name = "J.R.R Tolkien";
	// The member variable author is of type string*, therefore textbooks[5].authors is of type string*
	textbooks[5].authors = &author_name;
	// This is pointer to the entire textbook.
	Book* my_ptr_5 = &textbooks[5];
	my_ptr_5 ->authors = &author_name;

	std::cout << textbooks[5].title << " was written by " << *(my_ptr_5->authors) << " / " << *(textbooks[5].authors)<< " and the book contains " 
	<< textbooks[5].num_pages << " number of pages, and the publication date was: " << textbooks[5].pub_date << std::endl;

	// Example 2
	// ========
	//
	
	Book story_book;
	// I am creating a pointer of type Book. so 
	Book* my_ptr = &story_book;
	(*my_ptr).author1 = "James Dickons";

	std::cout << "The name of the author is: " << my_ptr->author1 << std::endl; // my_ptr->author1 is the same as (*my_ptr).author.	
	std::cout << "The same code: " << (&story_book)->author1 << std::endl;
	
	return 0;
}


