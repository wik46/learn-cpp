/* ****
 * Filename: main_read_data.cpp
 * Author: Wikus
 * Date: September 27, 2020.
 * Description: This is the driver file of my program.
 * 		This program is practise to study file handeling
 * */

#include "wizard.h"

#include <iostream>
#include <fstream>
#include <cstdlib>


int main(){
	// Creating my stream object.
	std::fstream file("wizards.txt");
	// NB Always make sure your file opened properly.
	if(!file){
		std::cout << "Error file not open." << std::endl;
		exit(EXIT_FAILURE);
	}
	
	int number_of = 0;
	file >> number_of;
	Wizard* school_of_wizards = new Wizard[number_of];

	int i = 0;
	while(file){
		file >> school_of_wizards[i].name >> school_of_wizards[i].id 
		>> school_of_wizards[i].password>> school_of_wizards[i].position_title 
		>> school_of_wizards[i].beard_length;
		i++;
	}
	
	print_info(&(school_of_wizards[4]));
	// Alway close your file.
	file.close();
	
	delete[] school_of_wizards;
	return 0;
}
