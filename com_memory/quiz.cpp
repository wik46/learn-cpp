#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
	string my_str;
	unsigned int num_letters;
	cout << "Please give me a string: " << endl;
	getline(cin, my_str);

	cout << "How many letters would you like to move: " << endl;
	cin >> num_letters;
	if (num_letters > my_str.length()) {
		cout << "Oh no!" << endl;
		cout << "There aren't that many letters in the string." << endl;
		exit(0); // exit immediately
	}

	// now you need to move the requested number of letters
	// 	// from the back of the string to the front of the string
	// 		string dest_str = ""; // this is the string that will hold the result
	

#if 0
string dest_str = "" ;
int  k=0;
for (int i = 0; i < my_str.length(); i++){
	if (num_letters < my_str.length()){
		dest_str.push_back(my_str[num_letters]);	
		num_letters++;
	}else{
		dest_str.push_back(my_str[k]);
		k++;
	}
}
#endif
	//


	//
string dest_str = "";
int k=0;
for (int i = 0; i < my_str.length(); i++){
	if( num_letters < my_str.length()){
		dest_str.push_back(my_str[num_letters]);
		num_letters++;
	}else{
		dest_str.push_back( my_str[k]);
		k++;
	}
}






//
 						// display the two strings
 							cout << "Your original string was:" << endl;
 								cout << my_str << endl;
 								cout << "Your newly rearranged string is:" << endl;
 			cout << dest_str << endl;
	
	 											return 0;
	 											}
