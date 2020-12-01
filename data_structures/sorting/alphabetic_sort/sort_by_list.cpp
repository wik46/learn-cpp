/*
 * Filename: sort_by_list.cpp.
 * Author: Wikus
 * Date: October 11, 2020.
 * Description: The purpose of this program is the study methods of sorting based on a 
 * 		given string.
 * Input: -
 * Output: -
 * */

// This program sorts a an array of strings in order specified by another list/string.
// Learning resourse is GeeksForGeeks


#include <iostream>

struct person{
	std::string name{"default"};
};

	
/*
 * Function name: sort_by_pat().
 * Description: This function takes in a pa
 * Parameters: string*, string.
 * Pre-conditions: - 
 * Post-condition: The string that the string pointer is pointing to is ordered
 * 		   according to the pattern of the string entered in the second argument.
 * */


void sort_str_by_pat(std::string* str, std::string pattern){
	person* people = new person[20];

	// The maximum.
	const short max = 26;
	int number_of[max] = {0}; 
	// This counts the number of the same char in the string.
	for(int i = 0; i < (*str).length(); i++){
		// Initially al the values in the array is set to zero.
		number_of[(*str)[i] - 'a']++;
	}
	
	// Not I set sort the string.
	int index = 0;
	for(int i = 0; i < pattern.length(); i++){
		for(int j = 0; j < number_of[pattern[i] - 'a']; j++){
			(*str)[index++] = pattern[i];
		}
	}
}

// This function swaps to person structs.
void swap(person* p1, person* p2){
	person tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
	
/* **************************************************************************************
 * Function name: sort_by_pattern().
 * Description: This algorithm is designed to sort an array of people based on a specified 
 * 	       string of letters. The array of persons will be sorted by the order of the 
 * 	       characters in the string.
 * Parameters: struct*, int, string.
 * Pre-conditions: The struct array passed as the first argument of the function needs
 * 		   to contain data. This function makes used of the swap function.
 * Post-conditions: The struct array is sorted according to the pattern of strings
 * 			passed in as the third argument of the function.
 * **************************************************************************************/
void sort_by_pattern(person* people, int length, std::string pattern){	
	if(people != NULL && length > 0){
		int index = 0;
		for( int i = 0;i < pattern.length(); i++){
			// length is the length of the person array.
			for(int j = 0; j < length; j++){
				if((people[j].name)[0] == pattern[i]){
					swap(&people[index], &people[j]);
				index++;
				}
			}
		}
	}else{
		std::cout << "[sort_by_pattern()]: The array passed into the function"
		<< " does not contain data or the length of the array is incorrect."
		<< std::endl;
	}
}	
// This function is used to print an array of people.
void print_ar(person* p_ar, int length){
	for(int i = 0; i < length ; i++){
		std::cout<< i << ".) " << p_ar[i].name << std::endl;
	}
}

// The driver code for my program.
int main(){
	int length = 20;
	std::string pattern2 = "mdpb";
	person* people = new person[length];
	
	
	people[15].name = "bichael";
	people[9].name = "pichael";
	people[2].name = "michael";
	people[0].name = "michael";
	people[3].name = "michael";
	people[7].name = "michael";
	people[18].name = "michael";
	people[9].name = "michael";
	people[4].name= "pacques";
	people[10].name  = "barel";
	people[1].name = "marius";
	// Before sorting attempt.
	print_ar(people, length);
	std::cout << std::endl;
	sort_by_pattern(people, length,"pdbm");

	print_ar(people, length);

#if 0	
	// This algorithm is designed to sort an array of people based on a specified 
	// 	string of letters.
	int index = 0;
	for( int i = 0;i < pattern2.length(); i++){
		for(int j = 0; j < length; j++){
			if((people[j].name)[0] == pattern2[i]){
				swap(&people[index], &people[j]);
				index++;
			}
		}
	}
#endif
	delete[] people;
	return 0;
}
