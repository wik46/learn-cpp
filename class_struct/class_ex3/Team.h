/*
 * File name: team.h
 * Author: Wikus Jansen van Rensburg
 * Description: This is another example on learning class
 * Aug 22, 2020.
 */

#ifndef TEAM_H
#define TEAM_H

#include <iostream>
#include "Player.h"
//#include <iostream>
// Private and Public Member access.
//



class Team{
private: // This is done by default but it makes it clearer.
// declare member variables private unless you have good reason not to.
// 	The name of the team.
	std::string m_name;
	// The type of sport team.
	std::string m_type_of_sport;
	// The coaches name.
	std::string m_coach_name;
	// The number of players on the team.
	int m_num_players;
	// The array containing the players.
	Player* m_list_players;
public:
	// The default constructor
	Team(std::string/*20*/);
	// user specifies the size of the team.
	Team(std::string, int size);
	// Destructor
	~Team();
	// Reading to.
	// Prints infor regarding the team.
	void PrintInfo();
	// Sets the type of sport the team playes.
	void SetType(std::string);
	// Sets the name of the coach.
	void SetCoach(std::string name);

	// Reading from
	std::string GetTeamName();

	// Acces works per class basis not per object basis. Two objects of the same class can have access
	// 	to each other's members.
	// Note that although the members are private I can still access the b
	// This is to create a dublicate of a class
	void CopyFrom(Team* team_0);
	// Delete the array of players.
	void Delete();
	
};

#endif
