/* ***************************
* File name: continue_vs_break.cpp 
* Author: Wikus
* Date: August 7, 2020
* Decription: This is an example of the continue keyword
* intput : -
* output : -
* **************************/

#include <iostream>

int main(){

	std::string my_string = "The cat jumped over the dog.";
	// This loop removes all the spaces.

	for(int i = 0; i < my_string.length(); i++){
		if(my_string[i]== ' '){
			continue; // The rest of the code will not run and the next iteration of the loop will start
		}
		std::cout << my_string[i];
	}
	std::cout << std::endl; // Note that this is outside of the body of the loop


	return 0;
}
