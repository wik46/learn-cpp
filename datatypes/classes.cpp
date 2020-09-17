/************************************************
 *Program Filename: classes.cpp
 *Author: Wikus
 *Date: 9 July 2020
 *Description: Classes and Structures
 ***********************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>


using namespace std;

// classes are a type. We are creating a new type Player

// Classes are by default private. So only function inside the class can acces the variables
// Functions inside classes are called methods.

class Player{
public: //I need to make the visibility public on oreder to access the variables in my class	
	
// Variables that are made from class types are called objects
// A new object variable is called an instance.
	int x_pos, y_pos;
	int speed;

	void move(int xa, int ya){

	x_pos = x_pos + xa*speed;
	y_pos = y_pos + ya*speed;
	

	}
};  //  Remeber the semi-colon after the definition 


int main(){

	Player player1, player2;  // So here we instantioated two new Player objects.
	player1.speed = 10;
	player2.x_pos = 92;
	player2.speed = 50;
	player2.y_pos = -10;
	cout << "Player1 speed: " << player1.speed << endl;
	cout << "Player2 x_pos: " << player2.x_pos << endl;
	
	cout << "Before: Player 2 x_pos " << player2.x_pos << " and y_pos " << player2.y_pos << endl;

	player2.move(4,6);
	cout << "After: Player 2 x_pos " << player2.x_pos << " and y_pos " << player2.y_pos << endl;
	return 0;
}
