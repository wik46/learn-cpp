/* **************************************************************************************
 * Filename: time_conversion3.cpp
 * Author: Lodewyk Jansen van Rensburg
 * Date: December 23, 2020
 * Description: These are all example questions from hackerrank.com. 
 * 		The purpose of the file is to study for an interview test.
 * *********************************************************************************** */
#include <iostream>
#include <cstdlib>
#include <string>
/*
 	Question:
	------------
	Given a time in 12 -hour AM/PM format, convert it to military (24-hour) time.
	Note: - 12:00:00AM on a 12-hour clock is 00:00:00 on a 24-hour clock. 
	- 12:00:00PM on a 12-hour clock is 12:00:00 on a 24-hour clock.

*/

/* **************************************************************************************
 * This function is not finished. It stills needs to be fixed. 
 * Test case fails: 12:00:00AM does not turn into 
 * Test case fails: 12:00:00PM should not change.
 * *********************************************************************************** */
std::string time_conversion(std::string s){
	// This will be the variable where we store the new time format.
	std::string temp_s( s.length() - 2, ' ');
	// We only need to convert the time if it has a "PM" string at the end.
	// Case when the first digits needs to change.
	if(s[s.length() - 2] == 'P'){
		// step 1: convert the firts two digits into integer format.
		int f_dig = (s[0] - 48 ) * 10;
		int s_dig = s[1] - 48;
		int total_dig = f_dig + s_dig;
		// We adjust it to military time.
		total_dig += 12;
		// step 2: Make sure that the time does not exceed 23:00.
		if(total_dig >= 24){
			total_dig -= 24;
		}
		// step 3: Convert the digits back to character format.
		s_dig = total_dig % 10;
		f_dig = (total_dig - s_dig) / 10 ;
		// We convert it to ascii.
		s[0] = f_dig + 48;
		s[1] = s_dig + 48;
	}
	// We need to return the time without the string of alphanumeric digits at the
	// end. We dont want to add the string as well, therefore we loop two less 
	// iterations.
	for(int i = 0; i < s.length() - 2; i++){
		temp_s[i] = s[i];
	}
	// Last step is to assign the temporary string to the original string.
	s = temp_s;
	// Three ways to return a variable:
	// - By copy : Very memory expensive but we can return a local varaible by copy.
	// - By reference: Returns and alias to a variable. NB! Cannot return if created
	// 		   in an inner scope.
	// - By pointer: Returns an address of the variable. You cannot return an 
	// 		  address of a locally created variable.
	// This is a local copy becuase the string was passed by copy as function
	// argument.
	return s;
}


int main(){
	// These are just a few testing strings.
	std::string test1 = "10:00:15PM";
	std::string test2 = "12:23:15PM";
	std::string test3 = "11:45:15PM";
	std::string test4 = "10:00:15AM";
	std::cout << std::endl;
	// Test cases output.
	std::cout << "1.) " << test1 << " and new format: " << time_conversion(test1)
	<< std::endl;
	std::cout << "2.) " << test2 << " and new format: " << time_conversion(test2)
	<< std::endl;
	std::cout << "3.) " << test3 << " and new format: " << time_conversion(test3)
	<< std::endl;
	std::cout << "4.) " << test4 << " and new format: " << time_conversion(test4)
	<< std::endl;

	return 0;

}
