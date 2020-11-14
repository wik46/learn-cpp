/* **************************************************************************************
 * Filename: sort_by_list_general.cpp.
 * Author: Wikus
 * Date: October 29, 2020.
 * Description: The purpose of this program is the study methods of sorting based on a 
 * 		given string. This is the clean version of sort_by_list.cpp
 * Input: -
 * Output: -
 * **************************************************************************************/

// +++++++++++++++++++
// Not ready for use.
// +++++++++++++++++++

// This program sorts a an array of strings in order specified by another list/string.
// Learning resourse is GeeksForGeeks
#include <iostream>

/* **************************************************************************************
 * Function name: sort_str_by_pat().
 * Description: This function takes in an array of strings and sorts them based on
 * 		the pattern that you provide as the second argument. This is a general
 * 		version of the function used for any array of strins or other
 * 		container where you want to sort it based on a pattern.
 * 		This can be very usefull if you want to sort classes by some category.
 * Parameters: string*, string.
 * Pre-conditions: - 
 * Post-condition: The string that the string pointer is pointing to is ordered
 * 		   according to the pattern of the string entered in the second argument.
 * **************************************************************************************/
void sort_str_by_pat(std::string* str, std::string pattern){
	// The maximum.
	const short max = 26;
	int number_of[max] = {0}; 

	// This counts the number of the same char in the string.
	for(int i = 0; i < (*str).length(); i++){
		// Initially al the values in the array is set to zero.
		number_of[(*str)[i] - 'a']++;
	}	
	// Note I set sort the string.
	int index = 0;
	for(int i = 0; i < pattern.length(); i++){
		for(int j = 0; j < number_of[pattern[i] - 'a']; j++){
			(*str)[index++] = pattern[i];
		std::cout << "eee";
		}
	}
}

// This is just a function that prints out the array.
void print(std::string* array, int size){
	for(int i = 0; i < size; i++){
		std::cout << i + 1 << ".) " << array[i] << std::endl;
	}
	return;
}

// The driver code for my program.
int main(){
	// This main function is the demonstration on how to use the function.
	const int length = 20;
	std::string pattern2 = "mdpb";
	std::string str_ar[length] = {"b99","r","maandag","police","pp","r","3", "m", "b", "p"};
	// Before sort.
	std::cout << std::endl;
	std::cout << "Before sort: " << std::endl;
	print(str_ar, length);
	// Now let us sort the array by the pattern specified.
	sort_str_by_pat(str_ar, pattern2);
	std::cout << std::endl;
	std::cout << "After sort: " << std::endl;
	// Now let us print out the pattern.
	print(str_ar, length);
	return 0;
}
