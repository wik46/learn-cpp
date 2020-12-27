/*
 *	Filename: implementation.c
 *	Author: Wikus
 *	Date: August 28. 2020
 *	Description: learning how to create a binary search tree.
 *
 */

#include "implementation.h"

#include <stdlib.h>
#include <stdio.h>


/* 
 * Function name: find()
 * Description: This function will return the element of the key inserted. It 
 * 		will make use of a binary searh algorithm
 * */

/* 
 * Function name: insert()
 * Description: This function will insert a node at the correct position. This function
 * 		assumes that the node already has a value and a key.
 * Parameters: node*
 * Pre-conditions: This function can only insert nodes into the tree if they are initialized.
 * Post-conditions: This function will return 1 on successful insertion and 0 on failure.
 * */

// NB!! This node must be allocated on the stack.
short insert(BinarySearchTree* bst, node* nd){
	// Firts we create a temoprary variables.
	// It is necessary to keep track of where the parent is so that when the
	// position to insert is found, we can update the BST appropriatly.
	node* parent = NULL;
	// This will act as the node that I am currently searching.
	node* tmp = bst->root;
	// This will search for the position to insert the node so that the BST property is maintained.
	while(tmp != NULL){
		// We set the parent for each iteration of the loop.
		parent = tmp;
		// Case 1: If the key is less than the tmp one we go to the left sub-branch.
		if(tmp->key < nd->key){
			tmp = tmp->left_child;
		// Case 2: If the key is greater or equal to the tmp node, we go to
		// 		the right sub-branch.
		}else if(tmp->key >= nd->key ){
			// We go towards the right child's tree.
			tmp = tmp->right_child;
		}else{
			// This means that we either don't have a value for node->key
			// or that there is no value for the current node's key.
			printf("*** Error: Ensure that node has a valid key value.\n");
			return 0;
		}
	}
	// We can now savely insert the node, becuase when the loop breaks we know that we found
	// 	the position to insert the node.
	if(parent = NULL){
		// Case 1: After search we realize that we have an empty tree.
		bst->root = nd;			
	}else if(parent->left_child == NULL){
		// Case 2: Add the node as a left child.
		parent->left_child = nd;
	}else{
		// Case 3: Add a node as a right child.
		parent->right_child = nd;
	}
	// 
	// Now we return success.
	return 1; 
	
}
/* 
 * Function name: remove()
 *
 * */


