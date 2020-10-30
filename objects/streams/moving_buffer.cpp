// Autor: Wikus
// Filename: moving_buffer.cpp
// Date: October 26, 2020
// Description: This file is used to study how the istream class work.
// Learning resource: learncpp 18.2

#include <fstream>
#include <iostream>
#include <iomanip>

int main(){
	// INPUT:
	// Data does no go directly from our input device to the program, it gets
	// stored by the os inside a temporary memory storage called a buffer.
	// OUTPUT:
	// Data don't flow directly from the program to the output device. It gets stored
	// in the buffer first.
	
	std::fstream file;
	file.open("files/cout.txt", std::ios::out);
	// Backup stream buffers for cout and cin.
	std::streambuf* stream_buffer_cout = std::cout.rdbuf();
	std::streambuf* stream_buffer_cin = std::cin.rdbuf(); // This function returns the streambuffer to cin.
	// Backup stream buffer
	std::streambuf* stream_buffer_file = file.rdbuf();

	// This sets the streambuf of cout to the streambuf of the fstream object, file.
	std::cout.rdbuf(stream_buffer_file);
	
	int num_lines = 10;
	for(int i = 0; i < num_lines; i++){
		// This stream obects is set to to the file buffer.
		// That is why I can use it to output to the file and not the screen.	
		std::cout << "This is using ostream." << std::endl; 
		file << "This is using fstream." << std::endl;
	}
	// Remember to return the cout to its normal buffer.
	std::cout.rdbuf(stream_buffer_cout);

	file.close();
	return 0;
}
