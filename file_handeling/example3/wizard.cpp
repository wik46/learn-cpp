/* **************************************************************************************
 * Filename: wizard.cpp
 * Author: Lodewyk Jansen van Rensburg
 * Student ID: 934 309 717
 * Date:
 * Desctiption: This is the implementation file for my wizard
 * 		struct. Any functions that manipulate the data of a wizard
 * 		will be defined in this file
 * **************************************************************************************/


#include "wizard.h"

/* **************************************************************************************
 * Function name: print_info()
 * Description: Outputs all the data of one wizard to the screen.
 * Parameters: Wizard*
 * Pre-conditions: The instance of a wizard must contain data and not garbage.
 * Post-conditions: The data that the Wizard pointer is pointing to is printed to 
 * 			the screen.
 * **************************************************************************************/
void print_info(Wizard* wiz){
	std::cout << "Name: " << wiz->name << std::endl;
	std::cout << "Id: " << wiz->id << std::endl;
	std::cout << "Password: " << wiz->password << std::endl;
	std::cout << "Class standing: " << wiz->position_title << std::endl;
	std::cout << "Beard length: " << wiz->beard_length << "m."<< std::endl;

}
