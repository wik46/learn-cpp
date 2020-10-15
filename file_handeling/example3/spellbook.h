/* **************************************************************************************
 * Filename: spellbook.h
 * Author: Lodewyk Jansen van Rensburg
 * Date
 * Description: This is the header file for the spellbook struct. It contains the 
 * 		definition of the spell and spellbook struct. This file also contains 	
 * 		all the function prototypes of the functions defined in spellbook.cpp 
 * 
 *
 * **************************************************************************************/

#ifndef SPELLBOOK_H
#define SPELLBOOK_H

#include <iostream>

// There will be multiple spells inside one spell book.
struct Spell{
	std::string name;
	float success_rate;
	std::string effect;
};

struct Spellbook{
	std::string title;
	std::string author;
	int num_pages;
	int edition;
	int num_spells;
	Spell* s;
};


// This function will insert the spells into the array.
// The integer is the number of spells that the spellbook has.
void insert_spell_into_spellbook(Spellbook*, int);
#endif
