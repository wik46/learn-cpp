// Autor: Wikus
// Date: October 26, 2020
// Description: This file is used to study how the istream class work.
// Learning resource: learncpp 18.2

#include <iostream>
#include <iomanip>

int main(){
	
	// A. std::cin >>
	// This method of obtaining input ignores white spaces.
	// B. cin.get() ignores new characters.
	// C cin.getline() works exacly like cin.get() but reads newline charaters
	// as well.
	// D. std::getline() is not part of the istream class and lives inside the
	// string headerfile.
	int size = 11;
	char buffer[size];
	// Read up to 10 new characters.
	std::cin.get(buffer, size);
	std::cout << buffer << std::endl;
	
	// Whys don't this second part get called?
	// Read up to 10 new characters.
	std::cin.get(buffer, size);
	std::cout << buffer << std::endl;

	// Solution:
	// cin.get() does no read new line charaters. 
	// So you it read untill the new line and then stopped.
	// The second cin.get saw that there is still some input inside
	// the stream and tried to get it. But is started with a new line
	// charater so the second cin.get() stopped.
	return 0;
}
