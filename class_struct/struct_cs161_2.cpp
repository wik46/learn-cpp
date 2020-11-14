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

struct Book{
// The program does not allocate memory for a struct after defintition, only after declaring your struct.
// The memory used by one struct is the sum of all the memory taken by the member variables.
	std::string title; // Assuming string size 24
	int num_pages; // size is 4 bytes
	unsigned int pub_date; // size is 4 bytes
	unsigned int num_authors; // size is 4 bytes
	// I want to create an dynamically alocated array that stores all the authors name
	// I do not know how many authora there are yet
	std::string*  authors;// size is 8 bytes, assuming this is a 64bit program

	// The size of one variable of type Book is 24+4+4+4+8 = 44.
};


// This is a function that displayes the info of a book.
void print_book_info(Book* ptr_type_book){
	std::cout << "The title of the book: " << ptr_type_book->title << std::endl;
	std::cout << "The book was published in: " << ptr_type_book->pub_date << std::endl;
}

// Another way of printing information to the screen.

void print_book_info(Book*** ptr_to_2d){
	// I am accepting a pointer to a 2d array of type books
	if(((*ptr_to_2d)[1][0]).num_authors > 0){
		for(int i = 0; i < ((*ptr_to_2d)[1][0]).num_authors; i++){
			std::cout << "The authors are: " << (*ptr_to_2d)[1][0].pub_date << std::endl;
		}
	//std::cout << "This is the memory address of the 2d array: " << ptr_to_2d << std::endl; 
	//std::cout << "This is the memory addres of the first element in the second row: " << &((*ptr_to_2d)[1][0]) << std::endl;	
	//std::cout << "This is the value at the first element of the second row: " << (*ptr_to_2d)[1][0]<< std::endl;
	
	}
}

// This function will create a 2d dynamically allocated array and return a 
// pointer to the first book in the array.
Book** create_2d_array(int row, int col){
	Book** name_of_array = new Book*[row]; // Now I have space to insert each column in the i'th row.
	// This ensures that each row contains the correct amount of columns.
	for(int j = 0; j < row; j++){
		name_of_array[j] = new Book[col]; // Each row can store col_size amount of variables of type book.
	}	
	return name_of_array;
}

// I am accpeting a pointer to a 2d array.
void delete_2darray(Book*** ptr, int num_row){

	for(int i = 0; i < num_row; i++)	
		delete[] (*ptr)[i]; // This is all the pointers that is the first element of each row.
	delete[] (*ptr); // Derefernecing a pointer to a variable of type Book**, gives me the 2d array.

}

int main(){

	int row = 5, col = 7;
	//Example 1: Create a 2d heap allocated array of type Book.
	Book** my_2dheap_array = new Book*[row];
	// Now I am creating an array to store in each row.
	for(int i = 0; i < row; i++){
		my_2dheap_array[i] = new Book[col];

		// Now I am setting each element in my 2d array.
		for(int j = 0; j < col; j++){
			my_2dheap_array[i][j].title = "Give me Liberty!";
			my_2dheap_array[i][j].pub_date = 1967;
		}
	}
	// my_2dheap_array is a 2d array containing 5*7 = 35 variables of type Book.

	print_book_info(&(my_2dheap_array[0][0]));
	
	Book*** ptr_to_2darray = &my_2dheap_array;
	delete_2darray(ptr_to_2darray, row);
	
	// Example 2: Using a function to create the array.
	Book** heap_array_2d = create_2d_array(row, col);
	
	Book*** ptr_1 = &heap_array_2d;

	(heap_array_2d[1][0]).num_authors = 1;
	//(heap_array_2d[1][0]).*authors = "John Hancock";
	(*ptr_1)[1][0].pub_date = 1881; 

	print_book_info(ptr_1);
	delete_2darray(&heap_array_2d, row);
	
	// Example 3.
	
	Book book_array; // Statically allocated 2d array.

	(book_array.authors) = new std::string[2];
	(book_array.authors)[0] = "Thomas";
	(book_array.authors)[1] = "Frank";
	
	std::cout << "Example 3: " <<	(book_array.authors)[1] << std::endl;
	delete[] book_array.authors;

	return 0;
}

