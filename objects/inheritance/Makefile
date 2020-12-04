## Author: Wikus Jansen van Renburg.
## Description: This Makefile is used inside the inheritance/ diretory
# 		to ease the compilation process.

# Variables
EXE_FILE1 = quiz1
EXE_FILE2 = quiz2
EXE_FILE3 = quiz3

GCC = g++
GCC_FLAGS = -std=c++11 -g

# Targets:

# 1. Making the quiz1 program
quiz1: quiz1.cpp
	$(GCC) $(GCC_FLAGS) quiz1.cpp -o $(EXE_FILE1)

# 2. Making the quiz2 program
quiz2: quiz2.cpp
	$(GCC) $(GCC_FLAGS) quiz2.cpp -o $(EXE_FILE2)

# 3. Making the quiz3 program
quiz3: quiz3.cpp
	$(GCC) $(GCC_FLAGS) quiz3.cpp -o $(EXE_FILE3)

# Cleaning up all the files:
clean: 
	rm -f *.out *.o $(EXE_FILE1) $(EXE_FILE2) $(EXE_FILE3)
