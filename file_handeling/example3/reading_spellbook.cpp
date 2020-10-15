/* ****
 * Filename: reading_spellbook.cpp
 * Author: Wikus
 * Date: September 27, 2020.
 * Description: This is the driver file of my program.
 * 		This program is practise to study file handeling
 * */

#include "spellbook.h"
#include "wizard.h"

#include <iostream>
#include <fstream>
#include <cstdlib>

int main(){
	// Creating my stream object.
	std::fstream file("spellbooks.txt");
	// NB Always make sure your file opened properly.
	if(!file){
		std::cout << "Error file not open." << std::endl;
		exit(EXIT_FAILURE);
	}
	
	int number_of = 0;
	file >> number_of;
	Spellbook* Library = new Spellbook[number_of];
	int i = 0;
	while(!file.eof()){
		file >> Library[i].title >> Library[i].author >> Library[i].num_pages 
		>> Library[i].edition >> Library[i].num_spells;
		// Creates an array of spells for each book.
		//insert_spell_into_spellbook(&(Library[i]), Library[i].num_spells);	
		// Creating a place to store all my spells.
		std::cout << Library[i].num_spells << " ---" << std::endl;
		
		Library[i].s = new Spell[Library[i].num_spells];
		// This loops saves the data of each spell.
		for(int k = 0; k < Library[i].num_spells; k++){
			file >> ((Library[i]).s)[k].name >> 
				((Library[i]).s)[k].success_rate >> 
				 ((Library[i]).s)[k].effect; 
		
			std::cout << (Library[i].s)[k].effect << std::endl;
		}
		i++;
		if(i== 8){
			break;
		}
	}
	
	// Alway close your file.
	file.close();
	// Always delete dynamic memory.
	for(int i = 0; i < number_of; i++){
			delete[] Library[i].s;
		
	}
	// Free the memory of each array of spells inside the spellbook before freeing the memory
	// 	of Library.
	delete[] Library;
	return 0;
}
