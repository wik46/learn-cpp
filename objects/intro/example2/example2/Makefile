# Filename: Makefile
# This make file is used for the point and line program.
# Author: Wikus
# Date: October 11, 2020.
#

# Variables

gcc = g++
gccflags = -std=c++11 -g -Wall

exe_file = math_app

# Targets.

$(exe_file): driver.o Point.o friends.o 
	$(gcc) $(gccflags) driver.o Point.o friends.o -o $(exe_file)

driver.o: driver.cpp 
	$(gcc) $(gccflags) -c driver.cpp 

Point.o: Point.cpp Point.h
	$(gcc) $(gccflags) -c Point.cpp

friends.o: friends.cpp friends.h
	$(gcc) $(gccflags) -c friends.cpp

clean:
	rm -f *.out *.o $(exe_file)
	
