/* **********************************************
 * Filename: 
 * Author: Wikus
 * Date: Septemeber 23, 2020.
 * Description: Studying how to read from and write
 * 		to file using ifstream, ofstream, and
 * 		fstream.
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

#include <iostream>
// This header file contains the defintion for the necessary stream objects for writing to and reading from file.
#include <fstream>

int main(){
	std::string user_input = "";
	// I creating an instance of an ofstream object.
	std::ofstream myfile("user_runtime_input.txt");

	std::cout << "Please entere the first line of the text file: " << std::endl;
	getline(std::cin, user_input);
	myfile << user_input;
	std::cout << "User data inserted." << std::endl;
	myfile.close();
	std::cout << "File closed" << std::endl << std::endl;
	return 0;
}	
