 /**************************************************
 *Program Filename: struct_ex1.cpp
 *Author: Wikus
 *Date: 18 July 2020
 *Description: Learning how to use th create a log function to print types of errors
 *Input
 *Output
 **************************************************/


#include <iostream> //Remember all that the #inlcude statement does is copy and paiste

//Keywords: int,double, struct, class, return, break, static, new.... ( Words that have special meaning to the compiler)

// The keyword struct: announces that this is a structure type definition;wq

// The identifier CDAccount: is the name of the struct
// The name of a structure data type is called a struct tag. This tag can be any legal identifier but not a keyword

//A struct definition is always outside a function.
struct CDAccount{
	//The identifiers declared inside the braces are called the member names 
	double balance = 0;
	double i_rate = 0;
	int term = 0; // the number of monthd
	std::string account_holder ;
	//functions defined inside a struct/class is called a method
	
	// One way of creating a function that you want to use is creating it inside the struct
	// The syntax is easier
	
	void GetData(){
//This is onlye the make the output look better
		std::cout << "=================================" << std::endl;
		std::cout << "Please enter the following data for " << account_holder << "'s account. " << std::endl;
		std::cout << "=================================" << std::endl;
		std::cout << "Enter account balance: $" << std::endl;
	// notice that I can use the variables without the name of the struct
		std::cin >> balance;
		std::cout << "Enter account interest rate: " << std::endl;
		std::cin >> i_rate;
		std::cout << "How many months untill maturity?: " << std::endl;
		std::cin >> term;
	}
	//2nd function declared inside my struct
	int calc(int balance, int rate, int term){
		double rate_frac = rate/100;
		double interest = balance*rate_frac * (term/12);
		balance = balance + interest;
		return  balance;
	}
};


// note that this function is declared outside the scope of the struct , the syntax differs.
// Remember this function does not know which struct you are reffering to.
	//remember the &
void GetName(CDAccount& the_account){
	std::cout << "Please enter the account holder's name: " << std::endl;
	std::cin >> the_account.account_holder;
}

int main(){
	// remember that a struct/class are user defined data types
	// So I need to a create a variable of type CDAccount	
	CDAccount your_account, my_account;
	
	//these functions are defined outside the struct	
	GetName(your_account); 
	GetName(my_account);	

	//these are methods (a function defined inside the scope of the struct)
	your_account.GetData();
	my_account.GetData();

	std::cout << your_account.account_holder << "'s account and  balance: " << your_account.balance << std::endl;
	std::cout << my_account.account_holder <<"'s account and balance: " << my_account.balance << std::endl;
	return 0;
}
