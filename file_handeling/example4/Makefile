# This is the Makefile for example4 of File handeling.
#

# Variables
CXX = g++
CXXFLAGS = -c -std=c++11

exe_file = book_app

# Targets and dependancies.

$(exe_file): main.o book.o 
	$(CXX) -std=c++11 main.o book.o -o $(exe_file)

main.o: main.cpp 
	$(CXX) $(CXXFLAGS) main.cpp
book.o: book.cpp 
	$(CXX) $(CXXFLAGS) book.cpp

clean:
	rm -f *.o *.out $(exe_file)
