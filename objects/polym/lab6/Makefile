# ###
# Filename: Makefile.
# Author: Lodewyk Jansen van Rensburg.
# Student ID: 934 309 717.
# Date: November 3, 2020.
# Description: This is the Makefile for the program used to study inheritance.
# Lab6: Inheritance.
# ###


# Variable.

EXE_FILE = application

GXX = g++

GXXFLAGS  = -std=c++11 -g

# Targets.

$(EXE_FILE): Application.o Shape.o Circle.o Rectangle.o
	$(GXX) $(GXXFLAGS) Application.o Shape.o Circle.o Rectangle.o -o $(EXE_FILE)

Application.o: Application.cpp 
	$(GXX) $(GXXFLAGS) -c Application.cpp

Shape.o: Shape.cpp Shape.h
	$(GXX) $(GXXFLAGS) -c Shape.cpp

Circle.o: Circle.cpp Circle.h
	$(GXX) $(GXXFLAGS) -c Circle.cpp
Rectangle.o: Rectangle.cpp Rectangle.h
	$(GXX) $(GXXFLAGS) -c Rectangle.cpp

clean: 
	rm -f *.out *.o $(EXE_FILE)
