/*************************************************
 *Program Filename: pointers1.cpp
 *Author: Wikus
 *Date: 13 June 2020
 *Desription: Learning pointers from the one lonely coder
 *Input:
 *Output:
 ************************************************/

//=========================
//Resource is wikibooks c++
//==========================


#include <iostream>
#include <cstdio>
#include <string>

void null_ptr(std::string* temp_ptr){
	//this creates a copy of the memory address
	// but I am still changin the content at the memory address
	*temp_ptr = "Bye";
}

int main(){
	std::string prog_str = "Hello";
	std::string* ptr = &prog_str;
	std::cout << "before: " << *ptr << std::endl;
	null_ptr(&prog_str);
	std::cout<< "after: " << *ptr << std::endl;
	
	return 0;
}
