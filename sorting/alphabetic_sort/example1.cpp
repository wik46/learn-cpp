/*
 * filename: exampe1.cpp
 * Author: Wikus
 * Description: This file is used to learn how to implement my own type of
 * 		sorting algorithm for an array of strings.
 *
 * */


#include <iostream>
// swap() is used inside quick_sort().
void swap(std::string* a, std::string* b){
	std::string tmp = *a;
	*a = *b;
	*b = tmp;
}

// is_before() will return true if the first argument is listed before the second argument
// 	alphabetically.
bool is_before(std::string a_str, std::string b_str){
	for(int i = 0; i < a_str.length() && b_str.length(); i++){
		if(tolower(a_str[i]) < tolower(b_str[i]) ){
			return 1;
		}else if(tolower(a_str[i]) > tolower(b_str[i]) ){
			// a_str is not listed higher than b_str.
			return 0;
		}
	}
	// This can be when identical strings are entered or the case for strings
	// 	like "jog" and "jogger" where "jog" is before "jogger".
	return 1;
}
// This function is a quick sort implementation.
void quick_sort(std::string* str_ar,int left, int right ){
	// Base case. There is no need to sort an array of length 1.
	if(right - left <= 0){
		return;	
	}
	// Here I am getting the pivot value. I am taking the last element in the
	// 	array.
	std::string pivot = str_ar[right];
	// This helps in swapping the correct index.
	int tracker = left;
	for(int i = left; i <= right; i++){
		if(is_before(str_ar[i], pivot)){
			swap(&str_ar[i], &str_ar[tracker]);
			tracker++;
		}
		std::cout << i << std::endl;
	}// Remeber the values of tracker is pivot + 1 here becuase.
	// Sorting the left subarray.
	quick_sort(str_ar, left, tracker - 2);
	// Sorting the right subarray.
	quick_sort(str_ar, tracker, right);
}


int main(){

      std::string name_ar[] = {"SharaSweetland" 
      ,"ReginaHallett"
      ,"VincenzoMccaster"
      ,"GaylordTon"
      ,"DarwinSisk"
      ,"LaveraLacomb"
      ,"EddieBoyko"
      ,"DelWeatherbee"
      ,"ElsieStahler"
      ,"BeatriceCerrato"
      ,"AleidaMaynez"
      ,"JaimeJarret"
      ,"NeldaTope"
      ,"TimothMauffray"
      ,"TisaFerrill"
      ,"FeliceArchuleta"
      ,"KelsiSapienza"
      ,"PaigeHay"
      ,"MinervaDrager"
      ,"Annmariealdovinos"
      ,"SibylHungerford"
      ,"StephenieCrabtree"
      ,"RubenDeberry"
      ,"SusanMincks"
      ,"AshtonFein"
      ,"AiEdinger"
      ,"RebeckaAlcara"
      ,"MoraAlvelo"
      ,"ErmaSciortino"
      ,"ShanaAlbarado"
      ,"RendaFrenkeli"};

     	std::string s_1 = "", s_2 = "";
	while(s_1 != "exit"){
		std::cout << "Word one: ";
		std::cin >> s_1;
		std::cout << "Word two: ";
		std::cin >> s_2;
		
		if(is_before(s_1, s_2)){
			std::cout << s_1 << " is before " << s_2 << std::endl;
		}else{
			std::cout << s_1 << " is not before " << s_2 << std::endl;
		}
		std::cout << "Enter 'exit' to quit the program." << std::endl;
	}

	// This is a demonstration of my quick sort function for an array of strings.
	std::string example1[]  = {"geeks", "for", "geeks", "quiz"};
	std::string example2[] = {"Anton", "Janco", "apple", "kite"};	
	int num_elements = 31;
	quick_sort(name_ar, 0, num_elements - 1);
	// Printing the data.
	for(int i = 0; i < num_elements; i++){
		std::cout << i << ")" << name_ar[i] << std::endl;
	}

	return 0;
}
