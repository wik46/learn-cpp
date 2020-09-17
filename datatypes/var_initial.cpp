/***************************************
 *Program Filename: var_initial.vpp
 *Author: Wikus
 *Date: 10 July 2020
 *Description: Understanding the types of variabel initialization
 *Input
 *Output
 **************************************/

#include <iostream>

using namespace std;

int main(){

	//Types of initialization
	
	//1. Copy initialization
	int copy = 1;
	//2. Direct initialization
	int direct(2); 
	//3. Brace initialization
	/* the parenthesis does not work on all data types therefore brace initialization was created*/
	int brace1{3}, brace2 = {4};
	/* If you use brace initialization, declaring variable of type int and setting it the value will give a warning and not just truncate the int*/
	int not_int{4.9};
 	cout << "Not an interger: " << not_int;
	// Zero initialization
	int zero{};
	

	cout << "copy, direct, brace1, brace2, zero: " << copy  << " " << direct << " " <<brace1  << " " << brace2 << " " << zero << endl;
	
	return 0;
}
