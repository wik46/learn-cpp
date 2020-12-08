/* ***************************************************************************************
 * Filename: summary.cpp
 * Author: Lodewyk Jansen van Rensburg
 * Date: December 7, 2020.
 * Description: This program will print out a summary of all the
 * 		time complexity and space complexity cases for various 
 * 		array sorting algorithms.
 * 
 * **************************************************************************************/

#include <iostream>
#include <iomanip>
// See function definition below.
void print_header();

// Each sorting algorithm will have a time_comlplexity struct and a space_complexity
// 	member.
struct time_complexity{
	// Best case.
	std::string m_best_case;
	// Average case.
	std::string m_ave_case;
	// Worst case.
	std::string m_worst_case;
};
// This function will take in a time_complexity instance and output it to the screen.
void print_time_complex(time_complexity* t_c){
	std::cout << std::setw(20) <<  
	t_c->m_best_case << '\t' << t_c->m_ave_case  
	<< '\t' << t_c->m_worst_case << std::endl;
	return;
}


// 1. This will be a class that all the different algorithms inheret from.
class Sort_algos{
	// This will be the name of the algorithm.
	std::string m_name;
	// This will store the time complexities
	// 	associated with the standard implementation
	// 	of the algorithm.
	time_complexity time_c;
public:
	// The constructor will create the algorithm such that it has the correct time
	// 	complexity. 
	Sort_algos(std::string n, std::string b, std::string a, std::string w)
	:m_name{n}
	{
		// Setting the members of the time_complexity struct.
		time_c.m_best_case = b;
		time_c.m_ave_case = a;
		time_c.m_worst_case = w;	
	}
	// This function will ouput the time_complaexity data.
	void time_c_out(){
		// See definition above
		print_time_complex( &time_c );		
	}	
	// This function returns the name of the algorithm.
	std::string get_name(){ return m_name;}
};

// This not declare as a friend functino because friends functions do not get inherted
// 	by derived classes, therefore I take this unorthodox approach.
// Now this function will be used to output any child of the Sort_algos class.
std::ostream& operator<<( std::ostream& stream_out, Sort_algos& s_ptr){
	// This will call the member that streams the time_complexity data.
	stream_out << s_ptr.get_name() << ":\n";
	s_ptr.time_c_out();
	// Still need to return the stream passed as an argument.
	return stream_out;		
}

// Classes that derive from Sort_algos.
// 1. Insertion Sort.
class InsertionSort: public Sort_algos{
public:
	InsertionSort():Sort_algos( "Insertion Sort", "omega(n)", "theta(n^2))", "O(n^2)")
	{}
};

// 2. Selection Sort.
class SelectionSort: public Sort_algos{
public:
	SelectionSort():Sort_algos( "Selection Sort", "omega(n^2)", "theta(n^2))", "O(n^2)")
	{}
};

// 3. Merge Sort.
class MergeSort: public Sort_algos{
public:
	MergeSort():Sort_algos( "Merge Sort", "omega(nlog(n))", "theta(nlog(n)))", "O(nlog(n))")
	{}
};

// 4. Quick Sort.
class QuickSort: public Sort_algos{
public:
	QuickSort():Sort_algos( "Quick Sort","omega(nlog(n))", "theta(nlog(n)))", "O(n^2)")
	{}
};

// 5. Bubble sort.
class BubbleSort: public Sort_algos{
public:
	BubbleSort():Sort_algos( "Bubble Sort" ,"omega(n^2)", "theta(n^2))", "O(n^2)")
	{}
};

// 6. Heap Sort.
class HeapSort: public Sort_algos{
public:
	HeapSort():Sort_algos( "Heap Sort", "omega(nlog(n))", "theta(nlog(n)))", "O(nlog(n))")
	{}
};


int main(){
	// Test run.
	const short size = 6;
	Sort_algos** algo_array = new Sort_algos*[size];
	// Storing the different algorithms.
	algo_array[0] = new InsertionSort;
	algo_array[1] = new SelectionSort;
	algo_array[2] = new MergeSort;
	algo_array[3] = new QuickSort;
	algo_array[4] = new BubbleSort;
	algo_array[5] = new HeapSort;

	// This is just a well formatted header for the program
	print_header();
	// The purpose of the program is to display all the different time complexities
	// 	to the user.
	for(int i = 0; i < size; i++){
		std::cout << *(algo_array[i]) << std::endl;
	}
	std::cout << "=======================================================" 
	<< std::endl;

	// Freeing the memory used by 
	for(int i = 0; i < size; i++){
		delete algo_array[i];
	}
	delete[] algo_array;
	return 0;
}
/* ***************************************************************************************
 * Function name: print_header()
 * Description: This function is used to print a nice header for the output.
 * Parameters: -
 * Pre-conditions: -
 * Post-conditions: -
 * **************************************************************************************/
void print_header(){
	// This creates a time_complexity object for the headers.
	time_complexity t_c;
	t_c.m_best_case = "Best Case";
	t_c.m_ave_case = "Average Case";
	t_c.m_worst_case = "Worst Case";
	// Initial header of the program.
	std::cout << std::endl;
	std::cout << "=======================================================\n" <<
		     "STUDYING TIME COMPLEXITY OF BASIC ALGORITHMS:\n" 
	          << "=======================================================\n";
	std::cout << std::endl;
	
	
	std::cout << std::setw(20) <<  
	t_c.m_best_case << '\t' << t_c.m_ave_case  
	<< '\t' << t_c.m_worst_case << 
	"\n=======================================================\n";
}
