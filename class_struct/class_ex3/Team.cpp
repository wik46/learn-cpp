/*
 * File name: Team.cpp
 * Author: Wikus.
 * Decription: The implementation of the Team class. 
 * Date August 22, 2020.
 */

#include <iostream>
#include "Team.h"
#define default_players 20


// The default constructor.
Team::Team(std::string name){
		m_name = name;
		m_type_of_sport = "default";
		m_coach_name = "default";
		m_type_of_sport = "default";
		m_num_players = default_players;
		m_list_players = new Player[m_num_players];
}

// The constructor.
Team::Team(std::string name, int team_size){
		// This constructor copies values to the members after they
		// had been created. It does not initialize the members.
		m_name = name;
		m_type_of_sport = "default";
		m_coach_name = "default";
		m_type_of_sport = "default";
		m_num_players = team_size;
		m_list_players = new Player[m_num_players];
}


// The destructor.
Team::~Team(){
// This is to delete the array of Players.
	//delete[] m_list_players;
}

/* *****************
 * Function Name:
 * Description:
 * Parameters:
 * Pre-Conditions:
 * Post-Conditions:
 * ****************/
void Team::PrintInfo(){
	std::cout << "Name: " << m_name << "\n\tb) Type of sport: " << m_type_of_sport 
	<< "\n\tc) Coach Name: " << m_coach_name << "\n\td) Number of Players: "<< m_num_players
	 << std::endl;
}

// This is used to set the type of sport the team playes.
void Team::SetType(std::string type){
	m_type_of_sport = type;
}
// This sets the name of the coach.
void Team::SetCoach(std::string name){
	m_coach_name = name;
}
// This is to read the name of the team.
std::string Team::GetTeamName(){
	return m_name;
}

// Access control is only on per-class basis not per-object basis.
void Team::CopyFrom(Team* team0){
	m_name = team0->m_name;
	m_type_of_sport = team0->m_type_of_sport;
	m_coach_name = team0->m_coach_name;
	m_num_players = team0->m_num_players;
//	m_list_players = team0->m_list_players;
}

void Team::Delete(){
	delete[] m_list_players;
}
