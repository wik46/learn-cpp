/*
 * 	Filename:
 * 	Author:
 * 	Date:
 * 	Description:
 *
 * */

#include <iostream>
#include "implementation.h"

int main(){

	LinkedList list1("first list");
	list1.insert_head(5);
	list1.print();
	// (data, position)
	list1.insert_position(4,1);
	list1.insert_position(10,2);
	list1.print();
	list1.insert_position(13,3);
	list1.insert_position(50,1);
	list1.print();	
	
	LinkedList list2("second list");
	for(int i = 0; i < 10; i++){
		list2.insert_position(i*i*10,i);
	}
	list2.print();
	//ll.delete_entire();
	return 0;
}
