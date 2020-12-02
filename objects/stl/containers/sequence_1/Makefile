## Author: Lodewyk Jansen van Rensburg

## Description: This makefile is used to compile the various
## 		container demonstration programs in inside the directory.

# Variables.
GCC = g++
GCCFLAGS = -std=c++11 -g

EXE_1 = run_list

# 1. Make cmd for intro_set.cpp
list: intro_list.cpp
	$(GCC) $(GCCFLAGS) intro_list.cpp -o $(EXE_1)


# Clean up
clean: 
	rm -f *.o *.out $(EXE_1)
