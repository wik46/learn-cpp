// Autor: Wikus
// Date: October 26, 2020
// Description: This file is used to study how the istream class work.
// Learning resource: learncpp 18.2

#include <iostream>
#include <iomanip>

class Buffer{
	char* m_buffer;
	int m_size;
public:
	Buffer(int size = 5): m_size{size}{
		m_buffer = new char[m_size]; 
	}
	// This function is the overloaded << operator.
	friend std::ostream& operator<<(std::ostream&, const Buffer&);
	// This function is the overloaded >> operator.
	friend std::istream& operator>>(std::istream&, Buffer&);
	// The destructor.
	~Buffer(){
		if(m_buffer != NULL){
			delete[] m_buffer;
		}
	}
	
	// Copy constructor.
	// Assignment operator overload.
};
// A friend function has acces to the classes private members.
// This is a friend of the class
std::ostream& operator<<(std::ostream& stream_out, const Buffer& buf){
	stream_out << "Buffer: " << buf.m_buffer << std::endl;
	stream_out << "Size: " << buf.m_size << std::endl;
	return stream_out;
}
// This is another friend of the class Buffer.
std::istream& operator>>(std::istream& stream_in, Buffer& buf){
	// This assumes that the stream_in object does not exceed the buffersize.
	stream_in >> buf.m_buffer;
	return stream_in;
}

int main(){

	// I am creating a buffer of size 10.
	Buffer buf1(100);
	// The problem is that I cannot assume that the user will only enter a 10 char string.
	// There will be major problems if the user enters a string greate that 10!!!
	int num_char  = 10;
	//setw(10) will only read 9 characters, the last one is the termination charater.
	std::cin >> std::setw(num_char) >> buf1;	
	std::cout << buf1 << std::endl;
	return 0;
};
