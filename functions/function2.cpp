/***************************************
 *Program Filename: function1.cpp 
 *Author: Wikus
 *Date: 31 July 2020
 *Description: Your function can accept and return paramters
		by - value
		   - address/pointer
		   - reference	
 *Input:
 *Output:
 ***************************************/

#include <iostream>
#include <cstdlib>

int fib_rec(int n){
	if(n <= 1){
		return n;
	}
	return fib_rec(n-1) + fib_rec(n-2);
		
}

int fib_it(int n){
	int current = 1, temp, old = 1;
	if(n <= 1){
		return n;
	}	
	for(int i = 1; i < n; i++){
		temp = current;
		current = current + old;
		old = temp;
	}
	return old;
}

int main(){
 	int my_int = 6; 
	std::cout << "Recursive: " << fib_rec(my_int) << " and Iterative: " << fib_it(my_int) << std::endl;
	return 0;
}
