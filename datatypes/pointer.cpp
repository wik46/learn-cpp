/************************************************
 *Program File Name: pointer.cpp
 *Author: Wikus
 *Date 10 July 2020
 *Description: studying pointers 
 *Input:
 *Output: 
 ************************************************/

#include <iostream>
#include <string>


using namespace std;

float global = 2.334;

class Player1 {
	public:
	int x_pos , y_pos , speed;
};

int main(){

	Player1 player;
	player.speed = 10;
	cout << player.speed << endl;
	

	int  var = 5;
	double* pointer = (double*)&var; // must cast it to an double* pointer
	cout << pointer << endl;	
	
	int var2 = 10;
	int* pointer2 = &var2;
	cout << "Memory address: " << pointer2 << endl;
	
	*pointer2 = 20;
	cout << "Changed value of pointer: " << var2 << endl;
	cout << "Self reference: " <<&var << endl;

	string my_char = "abcdefg";
	string* pointer3 = &my_char;	
	cout << "Memory address char: " << pointer3 << endl;
	return 0;
}
