/* **********************************************
 * Filename: file_handeling_basic.cpp 
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
#include <fstream>


int main(){
	// We are creating a file called sample_data.txt.
	std::ofstream myfile("sample_data.txt");

	// The file sample_data.txt will have three lines of charaters.
	myfile << "This was my very first program writing data to a file\n";
	// I am inserting this string of characters on the first line of the text file.
	myfile << "This is the first line" << " and the second part" << "\n";
	// This line of charaters will be inserted on the second line of the text file.
	myfile << "This is the second line. " << "\n";

	// The instance of ofstream myfile will be destroyed by the constructor once myfile goes 
	// 	out of scope. 
	// But it is good practise to close a file.
	myfile.close();
	return 0;
}
