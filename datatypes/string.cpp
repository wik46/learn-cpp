/************************************************
*Program filename: string.cpp
*Author: Wikus
*Date: 11 July
*Description: Strings in cpp
*Input:
*Output:
************************************************/

#include <iostream>
#include <string>

int main(){
	std::string user_name;
	const char* name= "Wikus";
	std::cout << name << std::endl;

	char name2[5] = {'W','i','k','u','s'};
	std::cout << name2 << std::endl;
	name2[2] = 'a';
	std::cout << name2 << std::endl; 

	
	std::string my_array[5];
	for(int i = 0; i < 5; i++){
		getline(std::cin,user_name);
		my_array[i] = user_name;
	}
	std::cout << my_array << " and " << my_array[4] << std::endl;
}

