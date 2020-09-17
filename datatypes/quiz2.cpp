/*Program filename:
 *Author:
 *Desription:
 *Date: Tuesday 7 July 2020
 *
 *
 *
 */
 
 #include <iostream>

using namespace std;

int main(){

	int user_num = 3, correct_num = 6;

//Note that this loop will run infinitly many times 
	
	do{
		cout << "Give a number between 1 and 10.\n";
		cin >> user_num;
	}while(user_num = correct_num);  // Remember the semi-colon !!!
	return 0;
}
