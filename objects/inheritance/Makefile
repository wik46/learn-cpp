## Author: Wikus Jansen van Renburg.
## Description: This Makefile is used inside the inheritance/ diretory
# 		to ease the compilation process.

# Variables
EXE_FILE1 = quiz1

GCC = g++
GCC_FLAGS = -g -std=c++11

# Targets:

# 1. Making the quiz1 program
quiz1: quiz1.cpp
	$(GCC) $(GCCFLAGS) quiz1.cpp -o $(EXE_FILE1)

# Cleaning up all the files:
clean: 
	rm -f *.out *.o $(EXE_FILE1)
