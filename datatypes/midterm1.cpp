/***************************************
*Program Filename: midterm1.cpp
*Author: Wikus
*Date: 9 July 2020
*Description: Practise for the midterm
*Input
*Output
***************************************/

#include <iostream> /* Any statement with a # infront is called a preprocessor statement in C++
			 Preprocessor statements occurs before the compiler compiles the source code .*/
#include <string>
#define Macro_name "_Hello I am a macro_" // We are using the preprocessor statement #define to define a macro (one way of defininf a constant).

using namespace std;

int main(){
	int tester_1, tester_2;		/* this line of code is a variable declaration only. We are telling 
					the compiler that the variable exist but we are not assigning any value to the variable*/ 	
	const string my_const_str = "-I am a constant string-";

	cout << "Enter number: ";
	cin >> tester_1;
	if(tester_1 > 19 && tester_1 < 99){
		cout << "X is between 9 and 99.\a\n";  /* Note the escape character (\) and the 'n' used to indicate
							c++ that I want a newline after the statements.*/
	}

	cout << "My macro: " << Macro_name << endl;
	cout << "My constant string: " << my_const_str << endl;

	// Question 18 Midterm1 sample question
	tester_2 = tester_2 + 30;
	cout << "Is this garbage: " << tester_2 << endl; 

	// Question 19
	char ch1 = 65, ch2 = '0'; //The statement is not legal. You cannot use double quotation marks to declare a char ( char ch2 = "a";)
	cout << "Question 19: " << endl;
	cout << "ch1: " << ch1 << " and ch2: " << ch2 << endl;
	
	// Question 25
	
	int user_num;
	do{ 		
		cout << "Please enter a number between 2 and 5 (inclusively).\n";
		cin >> user_num;
	} while(user_num < 2 || user_num > 5);
	
	// Question from flashcards
	int num1;
	num1 = 3/ static_cast<int>(4.5+6.4);
	cout << "num1: (expecting 0) " << num1 << endl;
	cout << "++++++++++++++++++++++++++\n";
	
	// Last queation from sample midterm
	cout << "Code from last question of the test.\n";
		
	int tmp;
	double result;
	cout << "Please enter a number greater than 10\n";
	cin >> tmp;
	tmp *= 12;
	if(tmp > 200){
		result = 2.5;
		cout << "You are lucky!\n";
	} else {
		result = 4.5;
		cout << "Not a lucky number\n";
	}
	double my_num = 3.5;
	if (my_num + 1 == 4.5) {
 		cout << "mysterious code: " << endl;
   		double my_num = -25.125;
  		cout << my_num << endl;
	}


 	return 0;
}
