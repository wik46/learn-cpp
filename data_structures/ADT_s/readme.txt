Date: December 26, 2020.
Description: This is a quick summary on how to remember the difference
		between data structures and abstract data types.
Author: Lodewyk Jansen van Resnburg.

What is the difference?
----------------------

Our world has many problemns to solve. As a programmer, we need containers
to store data and an efficient way to gain access to, and read/write from/to
the data. The data is needed to solve the problem. This container is an
abstract data type. The user is not concerned with how the data is stored,
how the functions used alongside are implemented.

Now these abstract data types are built on top of data structures. The two most 
common linear datastructures are dynamic arrays, and linked lists. We refer
to them as the data structure used to implement the abstract data type.

When we study these containers we are concerned with the runtime of:
--------------------------------------------------------------------
1. Finding a new element,
2. Inserting a new element, and
3. Removing an element.

We study three linear data structures in this directory.
--------------------------------------------------------
1. Stack (LIFO)
- Two basic operations:
	* push - adds an element to the container.
	* pop - removes and element from the container.
- Decription:	
	- A linear data structure where push() will ad the particular
	  element to the front of the container and pop() will remove the 
	  top most element. 
	- Can be built on top of a dynamic array or a linked list.
	- When built on the top a dynamic array remember that we add/remove elements
	  easily from the back of the array. Therefore the stack will have its
	  first as the tail of the array.
2. Queue (FIFO)
- Two basic operations:
	* enqueue - Add an  element to the back of the queue.
	* deueue - Remove an element from the front of the queue.
Description:
	- A linear data structure where the first element to be inserted
	  will also be the first element to be removed from the container.

3. Deque ( double ended queue. )
- Description:
	- A queue where we can add and remove data from the front and 
	- back of the queue.


We study the following non-linear data structure:
-------------------------------------------------

1. Binary Search Tree.
	- Must follow the Binary Search Tree Property:
		* For any node N in the binary search tree, the value of node N must 
		  be greater than all the nodes in N's left subtree, and a smaller or equal to 
		  the values in the right subtree of N.
	- See CS 261 course notes for full list of terminology regarding trees, binaray trees, and
	  binary search trees.
	-------------------
	- Basic operations:
	-------------------
		*
