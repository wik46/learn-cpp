/* ***************************************************************************************
 * Filename: intro_map.cpp
 * Author: Lodewyk Jansen van Rensburg
 * Date: December 1, 2020.
 * Description: This is a program to demostrate the use of the std::map template
 * 		class defined inside the C++ Standard Template Library.
 * **************************************************************************************/

// =======================
// std::map
// =======================


// Lives inside this header file.
#include <map>

#include <iostream> /* To perform basic console input and ouput*/
#include <iomanip> /* This is to used std::setw() */

// What is it?
/*
	std::map is an associative container defined in the STL library.
	The charateristics of the associative containers are that they automatically
	sort the datapoints that you insert to the contianer (by default in ascending order).

	Insering datapoints/ elements:
		- use pair_insert( key_value, data_value)
	
	A map can be thought of as a tuple ( value, key).
	No two mapped values can have the same key value.
		- But two different keys can have the same value.
	Value:
	    - Each datapoint/ element associates a unique key with a value at the key.
	Keys:
	    - The elements in the container are sorted by there key.
	    - You access the value of the datapoint using the key.

	Note: Maps are generally implemented as binary search trees.

*/

// ** Note that the type of iterator used is a:

// 	- bi-directional iterator.

// 1. Used inside remove_if().
bool is_12(int);

int main(){
	std::cout << "#################################" << std::endl;
	std::cout << "std::map Program." << std::endl;
	std::cout << "#################################" << std::endl;
	std::cout << "1. Iterator: bi-directional" << std::endl;
	std::cout << "2. Type of associative container." << std::endl;
	std::cout << "#################################\n" << std::endl;


	// I Methods of contruction:
	// ============================
	std::cout << "\nI Methods of construction: " << std::endl;	
	std::cout << "===========================" << std::endl;	
	std::cout << "1. Consruct an empty list and set data afterwards."<< std::endl;
	std::cout << "2. Consruct an empty list and set data using pair< key type, val type>()."<< std::endl;
	// 1. Default constructor. (empty map)
	/*	< key type, data/map type> */
	std::map<char,int> empty_map;
	// 1.2: Inserting the data into the empty std::map.
	empty_map['a'] = 1;
	empty_map['b'] = 2;
	empty_map['r'] = 10; // If I use the key 'r' I will get access to 10.
	// 2. Using pair_insert and insert().
	std::map<std::string, float> map_2;
	// Inserting the elements into the map container.
	// Note that I need to use the pair<>() to create data points
	// 	to insert into my map.
	map_2.insert( std::pair<std::string, float>("first_key", 10) );
	map_2.insert( std::pair<std::string, float>("seconde_key", 20) );
	map_2.insert( std::pair<std::string, float>("third_key", 2) );
	map_2.insert( std::pair<std::string, float>("random_key", 12323.232) );



	// II: Manipulation of data.
	// --------------------------
	// B. State of the container.
	// --------------------------
	std::cout << "\nII State of the container: " << std::endl;	
	std::cout << "==============================" << std::endl;	
	// 1. .empty() returns true if size = 0, else returns false.
	std::cout << "\nempty_map.empty() : (true/false) " << empty_map.empty() << std::endl;
	std::cout << "map_2.empty() : (true/false) " << map_2.empty() << std::endl;
	// 2. Returns the number of elements in the container.
	std::cout << "empty_map.size() : " << empty_map.size() << std::endl;
	std::cout << "map_2.size() : " << map_2.size() << std::endl;
	
	// ----------------------------------
	std::cout << "================================================================" << std::endl;	
	std::cout << "\nNote that how the iterators are used "
	<< "to print the keys and the mapped values: " << std::endl
	<< "The container has a member variable 'first' (the key) and 'second' the mapped value\n";	
	std::cout << "================================================================" << std::endl;	
	

	// ----------------------------------
	// C. Changing data in the container.
	// ----------------------------------
	std::cout << "\nIII Manipulation of data: " << std::endl;	
	std::cout << "==============================" << std::endl;	
	// 1. .insert() adds the element to the map, butmust be used with pair<>().
	// Note: This is the only insertion needed because the data
	// 	 gets sorted automatically.
	std::cout << "After inserting -10, 40, 12 using .insert( pair<>() ): "<< std::endl;
	// Using a for-each loop to iterate through the container.
	for(auto it = empty_map.begin(); it != empty_map.end(); it++){
		std::cout << it->first << " : "<< it->second << std::endl;
	
	}
	
	// ----------------------------------
	// D. Removing data in the container.
	// ----------------------------------
	std::cout << "\nIV Removing data: " << std::endl;	
	std::cout << "==============================" << std::endl;	
	// You can gain access by using the key.
	map_2.erase("random_key");
	map_2.erase("first_key");
	std::cout << "After removing 'first_key' and 'random_key' using .erase( key_name ): \n"<< std::endl;
	// Using a for-each loop to iterate through the container.
	for(auto it = map_2.begin(); it != map_2.end(); it++){
		std::cout << it->first << " : "<< it->second << std::endl;
	}

	std::cout << std::endl << "*** End of std::map demonstration ***"
	<< std::endl << std::endl;

	return 0;
}


