/***************************************
 *Program Filename: func_return_types.vpp 
 *Author: Wikus
 *Date: 17 July 2020
 *Description: Your function can accept and return paramters
		by - value
		   - address/pointer
		   - reference	
 *Input:
 *Output:
 ***************************************/

#include <iostream>

// Return types of functions
// 	by value
// 	by adress/pointer
// 		- You can not return local variables by address because
// 		they have local scope and will be deleted after the function call is completed
// 		and then you will have a pointer pointing to non-allocated memory (dangliing pointer)
// 	by reference.


/*
 * Function name: 
 * 
 */

int double_val(int integer_in){
	
	return integer_in * 2;
}
/*
 * Function name: 
 * 
 */

// You must return a variable, you cannot return a literal
int* return_ptr(int* int_ptr){
	int* fun_ptr = new int;	
	*fun_ptr = *int_ptr;
	return fun_ptr;
}
/*
 * Function name: 
 * 
 */
// You can not return local variable by reference
// Variable declared in the header of the function will also be restricted to the function scope

/* WHY YOU SHOULD NOT RETURN LOCAL VARIABLES
 * =========================================
int& return_ref(int int_in){
	int val = int_int;
	return val; 	// return a refernce to value here	
} // val gets destroyed here and you have a reference to nothing
*///========================================

int& return_ref(int var_in){
// I need to allocate a variable dynamically to be able to return a reference to it
//  	because the dynamically allocated variable does not have local scope
	int* pointer = new int;
	*pointer = var_in;
	return *pointer;
	
}

/*
 * Function name: 
 * 
 */


int main(){
	// Return by value
	// 	Nothing new than what you already know
	int main_int = 10;
	main_int = double_val(main_int);
	std::cout << "Return by value: " << main_int << std::endl;

	// Return by address
	// 	-Remeber that I van not return the address of a variable that I declared inside the function
	// 	because
	//
	// 	-But if I dynamically allocate memory I can return the address because the variable is not
	// 	deleted when my function is completed
	//	-Also remember the type that you declare in the function header is the type your function will
	//	return. ex int* function() - this function returns a pointer to an int
	int* pointer;
	pointer = return_ptr(&main_int);
	std::cout << "The address of main_int: " << pointer << " and value: " << *pointer << std::endl;
	
	// Return by reference
	// 	Same rules as for return by reference, you cannot return statically allocated memory
	//
	
	int ref_int = 12;	
	int fun_ref_int = return_ref(ref_int);

#if 0	
	// Before any modifications was made
	std::cout<< "[Before]:This int is return as a ref: " << fun_ref_int << " and this is my original int: " << ref_int << std::endl;
	// After modifications
	fun_ref_int  *= 20; // This will change the value of ref_int and fun_ref_int.

	std::cout<< "[After]:This int is return as a ref: " << fun_ref_int << " and this is my original int: " << ref_int << std::endl;
#endif	
	

	//=================================
	// New Topic: Copying
	//=================================
	//
	//
	//
	
	// A. Copying
	int a = 3;
	int b = a; // I am copying the value that a has into b. a and b is not connected in any way
	a += 3;
	std::cout << "a + 3:  " << a << " and b: " << b << std::endl;

	// B. Aliasing
	double num1 = 4;
	double& num2 = num1; // I am creating a reference of type double. Initialization must happen together with declaration
	num1 ++;
	std::cout << "num++ : " << num1 << " and num2: " << num2 << std::endl;
	

//Every time you allocate memory on the stack you need to delete it manually
	delete pointer;
	return 0;
}
