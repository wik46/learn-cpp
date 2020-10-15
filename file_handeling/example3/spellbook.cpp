/* **************************************************************************************
 * Filename: spellbook.cpp
 * Author: Lodewyk Jansen van Rensburg
 * Date
 * Description: This is the implementation file for the spellbook struct. Any functions
 * 		that are associated with a spellbook will be defined in this file.
 * 
 *
 * **************************************************************************************/

#include "spellbook.h"
#include <iostream>

/* **************************************************************************************
 * Function name: insert_spell_into_spellbook()
 * Deascription:This function will insert the spells into the array.
 * 			The integer is the number of spells that the spellbook has.
 * Parameters: Spellbook*, int.
 * Pre-conditions:
 * Post-condition:
 * **************************************************************************************/ 
// Caution: ### This function allocates dynamic memory.###
void insert_spell_into_spellbook(Spellbook* bk_ptr, int num_of_spells){
	// One of the members of the struct Spellbook will
	// 	keep track of the size of the array on the heap.
	bk_ptr->num_spells = num_of_spells;
	// Creating a place to store all my spells.
	bk_ptr->s = new Spell[num_of_spells];
}


