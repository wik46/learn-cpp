/*
 * Filename: counting_iterations_ex1.cpp 
 * Author: Wikus
 * Date: August 26, 2020.
 * Description: Using counting principles with repetition to determine the 
 * 		number of iterations in the inner most loop.
 *
 */

#include <iostream> 

int main(){

// How many iterations are in the innermost loop?
// Give your answer in terms of n.

	int n = 10;
	int counter = 0;
	// Note that you should be able to count the number of iterations without help from c++.
	for(int k = 1; k <= n; k++){ 
		for(int j = 1; j <= k; j++){ // note the the number of iterations in the middle loop is dependant
						//  on the size of k.
			for(int i = 1; i <= j; i++){ // The #iterations is dependant on the size of j
				std::cout << "[inner loop]." << std::endl;
				counter++;
			}
		}
	}
		std::cout << "The inner loop iterated " << counter << " times when n=" << n << "."  << std::endl;
}

// Solve the problem without C++.
// =============================
//
// When k = 1
// 	j = 1
// 	i = 1	-> only one iteration
//	(1 iteration)
//
// When k = 2
// 	j = 1
// 	i = 1 -> one iteration
// 	j = 2
// 	i = 1
// 	i = 2 -> 2 iterations
//	(1+2 iterations)
//
// When k = 3
// 	j = 1
// 	i = 1 -> 1 iteration
// 	j = 2
// 	i = 1
// 	i = 2 -> 2 iterations
// 	j = 3
// 	i = 1
// 	i = 2
// 	i = 3 -> 3 iterations.
//	(1+2+3 iterations)
//	.
//	.
//	.
//
// When k = n
// 	.
// 	.
// 	.
// 	i = n -> iterations.
// 	(1+2+...+n iterations)
//
// Total number of iterations of the innerloop.
// ===========================================
//
//  (1 + (1+2) + (1+2+3) + ... + (1+2+3+...+n)) =  sum(from i = 1 to n) (i(i+1)/2)
