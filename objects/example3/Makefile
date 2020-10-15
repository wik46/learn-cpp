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

$(exe_file): driver.o Point.o Line.o Point.h Line.h
	$(gcc) $(gccflags) driver.o Point.o  Line.o -o $(exe_file)

driver.o: driver.cpp Point.h Line.h
	$(gcc) $(gccflags) -c driver.cpp 

Point.o: Point.cpp Point.h
	$(gcc) $(gccflags) -c Point.cpp

Line.o: Line.cpp Line.h
	$(gcc) $(gccflags) -c Line.cpp

clean:
	rm -f *.out *.o $(exe_file)
	
