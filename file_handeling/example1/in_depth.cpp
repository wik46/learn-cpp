/* **********************************************
 * Filename: in_depth.cpp 
 * Author: Wikus
 * Date: October 23, 2020.
 * Description: Studying how to read from and write
 * 		to file using ifstream, ofstream, and
 * 		fstream.
 * Note: This program needs the file sample_data.txt.
 * *********************************************/

// Sources used to study.
// ======================
// https://www.learncpp.com/cpp-tutorial/186-basic-file-io/
// http://www.cplusplus.com/doc/tutorial/files/

// A file is used to store data permanently.


#include <iostream>
#include <fstream>

int main(){
	// Part one: Create data.
	const char* file_name = "files/data.txt";
	// This is the type of the variable that tells .open() how to open the file.
	std::ios_base::openmode normal = std::ios_base::out;
	std::ios_base::openmode append_to_file = std::ios_base::app;
	std::fstream file_out;
	file_out.open(file_name, normal | append_to_file);
	
	// This returns the stream buffer of file_out.
	std::streambuf* file_buffer = file_out.rdbuf();
	// This backups the stream buffer of cout.
	std::streambuf* cout_buffer = std::cout.rdbuf();
	// This sets the cout objects to use the filestream buffer.
	std::cout.rdbuf(file_buffer);

	int num_lines = 10;
	// Note that I now can use the cout to output to the screen.
	std::cout << num_lines << std::endl;
	for(int i; i < num_lines; i++){
		// Or I can still use the fstream object.
		file_out << i + 1 << " " <<  "Data ... ." << std::endl;
	}
	// This returns the cout buffer to itself.
	std::cout.rdbuf(cout_buffer);
	file_out.close();
	
	file_out.open(file_name,std::ios_base::in);
	if(!file_out){
		std::cerr << "The program is unable to read the file." << std::endl;
	}

	// infile returns 0 at the end of the file.
	while(file_out){
		std::string data;
		getline(file_out, data);
		std::cout << data << std::endl;
	}	
	// I am explicitly closing the the file.
	file_out.close();
	return 0;
}
