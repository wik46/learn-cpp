/*************************************************
 *Program Filename: .cpp
 *Author: Wikus
 *Date: 
 *Desription:
 *Input:
 *Output:
 ************************************************/

#include <iostream>
#include <cstdio>
#include <string>
/*
	TYPES OF MEMORY ALLOCATION
	==========================

STATIC (ON THE STACK)
Static memory allocation happens for static and global variables. 
Memory for these types of variables is allocated once when your program is run and persists throughout the life of your program.

AUTOMATIC (MEMORY GETS FREED WHEN OUT OF SCOPE)
Automatic memory allocation happens for function parameters and local variables. 
Memory for these types of variables is allocated when the relevant block is entered, and freed when the block is exited, as many times as necessary.

DYNAMIC MEMORY (ON THE HEAP)
Dynamic memory allocation is a way for running programs to request memory from the operating system when needed. 
This memory does not come from the program limited stack memory -- instead, it is allocated from a much larger pool of 
memory managed by the operating system called the heap. On modern machines, the heap can be gigabytes in size.
