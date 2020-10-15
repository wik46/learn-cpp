/* **************************************************************************************
 * Filename:
 * Author: Wikus
 * Date: September 30, 2020
 * Description: Studying how to handle files in C++.
 * Input:
 * Output:
 * **************************************************************************************/

#include "book.h"
#include <iostream>
#include <fstream>

int main(){
	Book bk;
	print_info(&bk);
	
	
	// Step 1: Create the stream object
	std::fstream f;
	
	// Step 2: Open the file.
	
	f.open("book1.txt",std::ios::in);
	
	//	This opens the file at the end (ate)
	//	f.open("book.txt", std::ios::ate); // For input/output capability.
	
	//	f.open("book.txt", std::ios::in); // For read only (input stream).
	//	f.open("book.txt", std::ios::out); // For write only (output stream)
	
	// 3. Make sure the file was opened correctly.
	
	if(f.is_open()){
		// 4. Work with the data from the file.
		std::string* tmp = new std::string[1000];
		for(int i = 0; !f.eof(); i++){
			std::getline(f,tmp[i],',');
			std::cout << i << ") " << tmp[i] << std::endl;
		}
		std::cout << "\nRound 2\n" << std::endl;
		f.seekg(0, std::ios::beg); // Changes the read pointer to 0 units from the begining.
		for(int i = 0; !f.eof(); i++){
			std::getline(f,tmp[i],',');
			std::cout << i << ") " << tmp[i] << std::endl;
		}
		f.close();
		f.open("book1.txt",std::ios::app|std::ios::out);	
	
		f.seekp(0, std::ios::end);
		f << ",The new line inserted";
	
		delete[] tmp;
	}else{
		std::cout << "File did not open." << std::endl;
		return 1;
	}
	// 5. Close the file to keep the pypline open.
	f.close();
	
	if(bk.authors != NULL){
		std::cout << "Array of authors deleted." << std::endl;
		delete[] bk.authors;	
	}
	return 0;
}
