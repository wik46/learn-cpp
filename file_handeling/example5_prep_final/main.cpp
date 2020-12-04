/* **************************************************************************************
 * Filename: main.cpp
 * Author: Lodewyk Jansen van Rensburg
 * Date: December 2, 2020
 * Description: Studying how to handle files in C++.
 * Input:
 * Output:
 * **************************************************************************************/


#include "book.h"
#include <iostream>
#include <fstream>

// File I/O for CS 162 final.



int main(){
	// Creating an file stream object to be associated with a file.
	// Any operations we perform on the std::fstream object will be reflected
	// 	on the file itself.
	std::fstream file; 
	/* does not live in this directory, the program
	will creat a new file called 'new_file.txt'*/
	// Ways of opening the file.
	// 1. Open and discard all info that was inside the file.
	file.open("new_file.txt",std::ios::out);
	file << "Some data" << std::endl;
	
	
	return 0;
}
