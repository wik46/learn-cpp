/*
 *	Filename: implementation.h
 *	Author: Wikus
 *	Date: August 28. 2020
 *	Description: learning how to create a binary search tree.
 *
 */

#ifndef IMPLEMENTATION_H
#define IMPLEMENTATION_H

#include <stdio.h>
#include <stdlib.h>

// Remember that a binary tree is a rooted tree where each parent may only
// 	have at most two children. The intitial/branch vertices/nodes are all the
// 	nodes with children.
// 	The terminal/branch vertices are the nodes/vertices that do not have any children.
// The data inside here will be stored inside the tree.
/*
 * 1. We rank the nodes according to a certain key.
 * */
struct node{
	// This will be the data stored, our tree will store names of people.
	char* value;
	// Here we have the key by which we will insert the nodes.
	int key;
	// This will be null if the node has no children.
	node* right_child;
	node* left_child;	 	
};

// This will be the binary search tree. This struct will be a wrapper around
// 	the BST.
struct BinarySearchTree{
	// This will represent the root of the tree.
	node* root;
	// We will later on define fields such as the number of nodes in the tree or
	// the height of the tree.
};


#endif
