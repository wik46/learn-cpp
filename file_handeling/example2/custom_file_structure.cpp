/* ******************************************
 * Filename: custom_file_stucture.cpp
 * Author: Wikus
 * Date: September 24, 2020
 * Description: Studying how to create a custom file
 * 		structure when taking data as an input and storing 
 * 		it inside a file.
 *
 * ******************************************/

// Resource used: https://www.youtube.com/watch?v=iGWhPwh3n-o
// YouTube Channel: Buckys C++ Programming Tutorials - 66 - Creating a custom file structure.

// Why store data in a file?
// 
// Because a program that cannot save information when it has terminated is not valueable.
// Example: Excel saves your spreadsheets to a file so that you can reuse them.
// 		Any video games saves the user progress to an external file so that 
// 		the game does not have to start from level 1 everytime the console/PC
// 		was switched off.

// Remeber : 1. Here we output data to the screen ---- cout << " ... "; 
//	     2. Here we output data to a file ---- file_object << " ... ";

#include <iostream>
#include <fstream>

// ofstream and ifstream is inside the std namespace.

int main(){

	// Creating an instance of an ofstream object that represents the file.
	std::ofstream file_1("format_file.txt");
	
	// .is_open() is a member of the ofstream class. It returns true if any file is
	// 	associated with the object file_1. Returns false otherwise.
	// It is good practise to make sure that the file is "open" before trying to 
	// 	perform operations on the data.
	if(file_1.is_open()){
		// This will let the user enter a header for the file.
		std::string title;
		std::cout << "Enter a title for the file." << std::endl;
		getline(std::cin, title);
		// Saving the title to the first line of the file.
		file_1 << "User entered title: " << title << std::endl;

		
		std::cout << "Enter in the following format: ID-number, name, and date of birth."<<std::endl;
		std::cout << "To close the file after all the data is entered, press ctr+D." << std::endl;
	
		// These variables will be used to temporarily store the data before it is saved
		// 	inside the file.
		std::string ID, name, birth_date;
		
		std::cout << "1. ID, 2. name, and 3. birth date.\n";
		// This loop will execute untill the EOF (end of file buttons are pressed.) 
		while(std::cin >> ID >> name >> birth_date){
			// Now I am saving the data in a custom format so that I 
			// 	can easily retrieve it for later use.
			
			// Think of the "<<" operators like when used for cout.
			// In stead of outputting to the screen, I am ouputting to a file.
			std::cout << "1. ID, 2. name, and 3. birth date.\n";
			file_1 << ID << ' ' << name << ' '<< birth_date << std::endl;
		}
		std::cout << "Your data is saved in the file." << std::endl;
		// It is good practise to close all the file used.
		file_1.close();
	}
	
	return 0;
}

