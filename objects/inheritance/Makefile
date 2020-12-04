## Author: Wikus Jansen van Renburg.
## Description: This Makefile is used inside the inheritance/ diretory
# 		to ease the compilation process.

# Variables
EXE_FILE1 = quiz1
EXE_FILE2 = quiz2
EXE_FILE3 = quiz3
EXE_FILE4 = big_three_part1
EXE_FILE5 = big_three_part2_1
EXE_FILE6 = big_three_part2_2


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

# 4. Making the big_three_part1 program
big_three_part1: big_three_part1.cpp
	$(GCC) $(GCC_FLAGS) big_three_part1.cpp -o $(EXE_FILE4)

# 5. Making the big_three_part2_1 program
big_three_part2_1: big_three_part2_1.cpp
	$(GCC) $(GCC_FLAGS) big_three_part2_1.cpp -o $(EXE_FILE5)

# 6. Making the big_three_part2_2 program
big_three_part2_2: big_three_part2_2.cpp
	$(GCC) $(GCC_FLAGS) big_three_part2_2.cpp -o $(EXE_FILE6)

# Cleaning up all the files:
clean: 
	rm -f *.out *.o $(EXE_FILE1) $(EXE_FILE2) $(EXE_FILE3) $(EXE_FILE4) $(EXE_FILE5) $(EXE_FILE6)
