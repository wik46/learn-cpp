#
#	This is a Makefile for my class_ex3 project.
#	Author: Wikus
#

# Variables and Targets
#

# Variables.

GXX = g++
GXXFLAGS = -Wall -g

# Targets.

main: Team.o
	$(GXX) $(GXXFLAGS) -o main main.o Team.o

main.o: Team.h Player.h

Team.o: Player.h
