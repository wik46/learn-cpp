Author: Wikus Jansen van Rensburg
Date: December 7, 2020.
Description:
	This directory is created prior to taking any analysis of algorithms class.
	The purpose of this directory is to study a few basic algorithms:	
		** Stable sort: When 2 elements that have the same rank before
				sorting maintains the same rank.
				Think about is like this:
					* Lets say you have a person object that has a name and
					  a surname as seperate strings. Now you sort the array
					  of people first by surnames. Then you sort all the people
					  with the same surnames by name. You want the people
					  surname to remain higher precedence in the sorting rank. You dont want to change
					  the order such that the name are no alphabetical and the surnames are not.
					* A stable sorting algorithm will maintian you order you want,
					  but an unstable sorting algorithm is not gaurenteed to have the
					  desired sort by surname then name order. 
		1. Bubble Sort:
			* Stable algorithm
			* Runtime complexity: O(n^2)
			* Simple to implement.
			* Idea: repeatedly swap elements if they are in the wrong order.
			* In-place: No significant extra spaced needed.
		2. Selection Sort:
			* Not stable on standard implementation.
			* Runtime complexity: O(n^2)
			* Consistand runtime.
			* Idea: Puts smallest element in right place and then sorts the rest of
				array excluding the inserted at left element.
			* In-place: No significant extra space needed.
		3. Insertion Sort:
			* Stable.
			* Best on smaller data sets.
			* Runtime complexity: O(n^2)

		4. Merge Sort: Divide and Conquer Algorithm.
			* Two parts: 
				- Devide the structure untill you have n pieces of single datapoints.
				- Conquer the structure by merging the n pieces in order using a two finger
				   alforithm.
				- Stable.
				- Often used for large datasets.
