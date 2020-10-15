// This is the interface file (headerfile) for the wizard struct.
//

// You always need header guards.
#ifndef WIZARD_H
#define WIZARD_H

#include <iostream>
#include <string>
struct Wizard{
	std::string name;
	int id;
	std::string password;
	std::string position_title;
	float beard_length;
};

// This function prints information of a single Wizard.
void print_info(Wizard*);

#endif
