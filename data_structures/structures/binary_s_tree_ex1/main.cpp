/*
 *	Filename: main.c
 *	Author: Wikus
 *	Date: December 26, 2020
 *	Description: learning how to create a binary search tree.
 *
 */

//
// IN PROGRESS>>
//

// Next step is to create a function that inserts the nodes into the tree.
#include "implementation.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char** argv){
	// We create space in memory for a node.
	node* n0 = (struct node*) malloc( sizeof(struct node) );
	node* n1 = (struct node*) malloc( sizeof(struct node) );
	node* n2 = (struct node*) malloc( sizeof(struct node) );
	node* n3 = (struct node*) malloc( sizeof(struct node) );
	node* n4 = (struct node*) malloc( sizeof(struct node) );
	
	// We initialize the value.	
	n0->value = "Name4";
	n1->value = "Name10";
	n2->value = "Name3";
	n3->value = "Name9";
	n4->value = "Name14";
	
	n0->key = 4;
	n1->key = 10;
	n2->key = 3;
	n3->key = 9;
	n4->key = 14;
	
	n0->left_child = NULL;
	n1->left_child = NULL;
	n2->left_child = NULL;
	n3->left_child = NULL;
	n4->left_child = NULL;
	
	n0->right_child = NULL;
	n1->right_child = NULL;
	n2->right_child = NULL;
	n3->right_child = NULL;
	n4->right_child = NULL;

	// We print to see if the tree is succesful.
	

	// Lastly we free memory of the nodes.
	free(n0);
	free(n1);
	free(n2);
	free(n3);
	free(n4);
	return 0;
}


