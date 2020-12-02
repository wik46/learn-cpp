## Author: Lodewyk Jansen van Rensburg

## Description: This makefile is used to compile the various
## 		container demonstration programs in inside the directory.

# Variables.
GCC = g++
GCCFLAGS = -std=c++11 -g

EXE_1 = run_set
EXE_2 = run_map

# 1. Make cmd for intro_set.cpp
set: intro_set.cpp
	$(GCC) $(GCCFLAGS) intro_set.cpp -o $(EXE_1)

# 2. Make cmd for intro_map.cpp
map: intro_map.cpp
	$(GCC) $(GCCFLAGS) intro_map.cpp -o $(EXE_2)


# Clean up
clean: 
	rm -f *.o *.out $(EXE_1) $(EXE_2)
