/****************************************************
 *Function: convert_to_int()
 *Description: Takes in a string that contains numbers and returns an integer
 *Parameters:
 *Pre-Conditions:
 *Post-Conditions:
 ***************************************************/

#include <iostream>
#include <typeinfo>

#if 0
int main(){
	
	int power_of(int num_in, int power);
	int convert_to_int(std::string num_as_str);


	
	std::string string_num;
	std::getline(std::cin,string_num);
	int new_int = convert_to_int(string_num);

	std::cout << new_int + 10<<  std::endl;	
} 

#endif

/*to_power is used inside the convert_to_string() to make use of the decimal number system*/
int power_of(int num_in, int power){
	int num_worker = num_in;
	if(power < 1){   // The function is only needed for powers greater or equal to 0
		return 1;
	}
	for(int i = 1;  i < power; i++){
		num_in *= num_worker;
	}
	return num_in;
}


int convert_to_int(std::string num_as_str){
	// rember to initialize variable. (give a value at declartion in order to avoid undefined behaviour)
	int num_as_int = 0, k = num_as_str.length() - 1;

	for(int i = 0; i < num_as_str.length(); i++ ){
		num_as_int += (num_as_str[i]  - 48)*power_of(10,k); /*The using the base 10 number system to sum all the different digits*/ 	
		k--;
	}
	
	return num_as_int;
}

