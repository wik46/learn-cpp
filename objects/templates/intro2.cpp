/* ***************************************************************************************
 * Filename: intro2.cpp
 * Author: Wikus
 * Date: December 3, 2020.
 * Description: 
 * Learning resource: Learn cpp 13.1 - 13.3
 * **************************************************************************************/
#include <iostream>

// 1. The basic use of classes templated.
// This will be a very basic dynamic array only to contrast the other way
// 	of using templated classes.

template <class T>
class Dynamic_array{
public: // Members are only public to help wit the ease of showing the example.

	// The member that will act as my raw array.
	T* m_array;		
	int m_size;
	// 1. Member function to get the length of the array and the array itself.
	// Mutators:
	// 2. More member functions to add, remove elements fromt the array.
	// Construction:
	Dynamic_array(int s = 1): m_array{ new T[s] },  m_size{ s }
	{
		std::cout << "[Dynamic_array]: Created with size " << m_size << std::endl;
		for(int i = 0; i < m_size; i++){
			m_array[i] = i;// i is chosen just to populate the array.	
		}
	}

	// Remember the big 3:
	~Dynamic_array(){
		// To delete dynamic memory when it was allocated.
		if(m_array){
			delete[] m_array;
			std::cout << "[Dynamic_array]: Destructed size: " << m_size << std::endl;
		}
		// End of destructor.
	}
};
// Static array version.
// Version 2 of using templates:
// This is very similar to how std::array is defined inside the STL.
template <class T, int N> // This allows me to specify the size of the static array.
class Static_array{
public:
// Members are public just for ease of example.
	// ** This creates an array on the stack therefore we do not
	// 	have to free it, the program will take care of it for us.
	T m_array[N];
	int m_size;
	// We know the size is N, so we use N as the size variable.
	// Accessor function.
	int GetSize(){ return N;}
	// The constructor is only used to populate the array.
	Static_array(): m_size{N}
	{
		for(int i = 0; i < N; i++){
			m_array[i] = i * 10; /* The times 10 is added to distinguish between
						the Dynamic_array and the Static_array */	
		}
		std::cout << "[Static_array]: Created with size " << N << std::endl;
	}	
};
// This is just a helper function that show the power of templates
// 	that can print any array that is passed onto it.
template <typename T>
void print_array(T* ar, int size){
	// This will print out all the elements of the array.
	for(int i = 0; i < size; i++){
		std::cout << ar[i] << std::endl;
	}
}


// Templates
int main(){
	// 1. Declaring the dynamic array that will contain integers.
	// Notice that with this I am creating a class that uses the keywoard new
	// 	to allocate a block of memory on the heap.
	Dynamic_array<int> ar_d(15);
	// 2. Declaring the static array where we need to specify the size of the array as 
	// 	a template argument as well.
	// Notice that here I am creating an array on the stack of size 10. 
	Static_array<float, 10> ar_s;
	
	// 3. Printing out the contents of both arrays.
	print_array(ar_d.m_array, ar_d.m_size);
	print_array(ar_s.m_array, ar_s.GetSize() );

	return 0;
};
