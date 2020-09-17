/************************************************
 *Program Filename: rand_num.cpp
 *Author: Wikus
 *Date 9 July 2020
 *Description: Practising random number for midterm1
 *Input:
 *Output:
 ************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){

	srand(time(NULL));
	
	int i = 1;
	int rand_number;	
	do{
		rand_number = rand() % 10 +1;		
		cout << i << endl;
		i++;
		
	}while (rand_number != 10);
	cout << "It took " << i << " attempts to find 5.\n";
	
	int k;
	for (k=100 ; k > i; k--){
		cout << "k: " << k << endl;
	}
	cout << "Final k value: " << k << endl;
	return 0;
}
