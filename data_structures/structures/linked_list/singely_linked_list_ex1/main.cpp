/*
 * File name: main.cpp
 * Author: Wikus
 * Description.
 *
 *
 *
 * */

// A singlely linked list can be thought of an array that contains elements.
// We call the elements in the array nodes.
// This single node(element) contains a value and a pointer.
// The value is the value of the data and the pointer points to the next node(element) in 
// the list.
//
// Example: Think of creating a media player
// We want to play one song after the other. So if the current song is playing (data), then we can use
// 	that song to select the next one because the current song also has a pointer to the next song.
//

#include "interface.h"

int main(){

	LinkedList ll;

	// Inserting data into the first node of the list.
	int data_ex = 4;
	ll.insert_head(data_ex);
	ll.insert_head(3);
	ll.insert_head(2);

	ll.insert_position(10,1);
	ll.insert_position(50,3);
}

