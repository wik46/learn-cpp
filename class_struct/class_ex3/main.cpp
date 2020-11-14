/*
 * File name: main.cpp
 * Author: Wikus.
 * Decription: The implementation of the Team class. 
 * Date August 22, 2020.
 */

#include <iostream>
#include "Team.h"
#include "Player.h"


int main(){
	Team first_team("Blue Bulls");
	first_team.SetType("Rugby");
	first_team.SetCoach("Sylvester");	
	first_team.PrintInfo();
	return 0;
}
