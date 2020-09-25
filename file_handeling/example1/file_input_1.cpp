/* **********************************************
 * Filename: file_input1.cpp 
 * Author: Wikus
 * Date: Septemeber 23, 2020.
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

// A stream is an object.
// A stream is an abstraction that represents a device on which input and output operations are performed
// Once a filestream is opened, any operations performed on the stream object is reflected in the file.

// The newly created file is stored in the same directory as the program.
//

#include <iostream>
#include <fstream>

int main(){
	// Create an instance of an ifstream object.
	// ### Note that you need the file sample_data.txt in the same directory for 
	// 	this program to work.
	std::ifstream infile("sample_data.txt");

	// The case when we cannot open the file.
	if(!infile){
		std::cerr << "The program is unable to read the file." << std::endl;
	}

	// infile returns 0 at the end of the file.
	while(infile){
		std::string data;
		getline(infile, data);
		std::cout << data << std::endl;
	}	
	// I am explicitly closing the the file.
	infile.close();
	return 0;
}
