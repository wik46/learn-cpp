## Author: Lodewyk Jansen van Rensburg.
## Date: December 1, 2020.
## Description: 
		This is a directory used to study the basic types of containers defined
		inside the C++ Standard Template Library.
		There are 3 categories for types of containers:
			1. Sequence containers:
			- These containers keep the order of elements that the user
			  specified. It does not change the order in wich the elements
			  are inside the container. Examples of such containers are
				* std::array, ( basic static array class, allows random access)
				* std::vector, ( dynamic array, allows random access)
				* std::list, ( doubly linked list, no random access )
					- Each node has a next pointer and a prev pointer.
				* std::foward_list, (singely linked list, no random access)
					- Each node only has a next pointer.	
				* std::deque ( double ended queu class, a dynamic array that can grow 
						from both ends.)
			
			2. Associative Containers:
			- Thes containers order the elements after they have been inserted into
			  the container. NB! If you insert user-defined types you must ensure that
			  the operator<() us overloaded in order to use container.
				TYPES: All are followed by an undordered version of the constainer.
				* std::set
				* std::unordered_set
			
				* std::map 
				* std::unordered_map
			
				* std::multiset
				* std::unordered_multiset
			
				* std::multimap
				* std::unordered_multimap
			3. Container Addapters:
			- These containers are an application of the above mentioned containers.
			- They are data structures that are very commonly used, therefore
			  they have been defined over the the two above mentioned containers.
			Examples of such containers are:
				
				* std::stack (LIFO): 
					     Underlying container is the std::deque by default, but it
					      can be changed to use std::vector or std::list. 
					     - Elements operate in a LIFO or FILO.
					     - All stacks are defined by two fundamental operations:
						Push: Add an element to the top of the stack.
						Pop: Remove an element fromt the top of the stack.
				 	     - That is the last element to be inserted into the
						container will be the first element to be removed.
					     - Or the first element inserted in the structure will
						be the last element to be removed.
				
				* std::queue (FIFO): 
					     Underlying container is std::deque by default, but can
					      be changed to std::vector or std::list.
					     - Elements operate with a FIFO or LILO procedure.
						^ Think of standing in a queue, the first person (datapoint)
						  to enter the queue will be the first person (datapoint)
						  to be helped (accessed).
					     - Two fundamental operations to access datapoints:
						^ Push: Datapoints are inserted at the end of the queue.
						^ Pop: Datapoints are removed from the front of the queue.
				
				* std::priority_queue: Similar to std::queue, except each time
							that a datapoint gets inserted (pushed)
							into the queue the containers sorts the queue.
						       Therefore, when you remove a datapoint (pop) from 
							the priority_queue you will receive the sorted
							queue s first datapoint. (Not the one that you
							inserted first.)

BASIC OPERATIONS THAT WE WANT TO PERFORM ON OUR CONTAINERS:
1. Container construction:

2. Iterate through:
	- for loop
	- while-loop
	- for-each loop
	- Using iterators provided in the <iterator> headerfile // More on iterators in iterator directory.

3. Sort the container: for sequence containers.
	
Take note:
	With the additions of C++11, all the associative containers have an unordered version of 
	the container. (https://www.cplusplus.com/reference/stl/)
