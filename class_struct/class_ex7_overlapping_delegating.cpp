 /**************************************************
 *Program Filename: class_ex5.cpp
 *Author: Wikus
 *Date: 22 August 2020
 *Description: Learning how to use th create a log function to print types of errors
 *Input
 *Output
 *************************************************/

#include <iostream>
#include <assert.h>


// The constructor serves two purposes.
// 1. Firstly it is use to create and instance of a class called an object.
// 2. The programmer can use it to instantiate its member variables.
// - Remeber that a member variable that is a class, this class will be created before the body of the
// 	outer class executes. The inner class member's constructor will be call first.

// Overlapping and Delegating Constructors.
// ========================================
//

class Team{
private:
	std::string m_name;
	int m_size;
	std::string* m_player_list;
	char m_team_rank; // A, B, C ... team.

public:
	// The first constructor.
	Team(std::string name, int size)
	:m_name(name), m_size(size)
	{
		// the array will be used to store the player names.
		m_player_list = new std::string[size];	
	
	}
	// My second constructor.
	// I still want all the functionality of my first constructor and more.
	Team(char team_rank ,std::string name = "", int size = 0)
	// Delegating constructors available from c++11.
	: Team(name, size) // This is my delegating constructor.
	{
		m_team_rank = team_rank;
		std::cout << "The second constructor was called." << std::endl;
	}
	
	// The destructor.
	~Team(){
		delete[] m_player_list;
	
	}
	// This function is used to insert a player name into the 
	// 	list of player names.
	void SetPlayer(std::string name, int number){
		assert(number >= 0 && number < m_size);
		m_player_list[number] = name;
	}
	// This function returns the player's name.
	std::string GetName(int number){
		return m_player_list[number];
	}
	// This funtion is used to print the team.
	void print_team(){
		for(int i = 0; i < m_size; i++){
			std::cout << i+1 << "). " << m_player_list[i] << std::endl; 
		}
	}
	// This function is used so that the user can insert the names.
	void user_set_names(){
		for(int i  = 0; i < m_size; i++){
			std::cout << "Enter player " << i+1 << "'s name." << std::endl;
			getline(std::cin, m_player_list[i]);  
		}
	}
};

int main(){
	
	Team Menlopark('A', "First team", 16);
	
	Menlopark.SetPlayer("Jaco Britz", 1);
	Menlopark.user_set_names();
	Menlopark.print_team();
	std::cout << Menlopark.GetName(1) << std::endl;
		
	return 0;
}
