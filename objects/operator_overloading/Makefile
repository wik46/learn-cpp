## =======================================================================================
## Author: Wikus Jansen van Rensburg
## Date: December 6, 2020
## Directions for use:
# 	* type the following command in the commandline
# 		make file_name
# 	* Type the name of the .cpp file without the extention to compile the
# 		file
# 	* This will create an executable with the same name.
## =======================================================================================

## =======================================================================================
## Variables:
## =======================================================================================
GCC = g++
GCCFLAGS = -std=c++11 -g

EXE_FILE1 = start_operator_overl
EXE_FILE2 = Normal_function_overload1
EXE_FILE3 = Friend_function_overload2
## =======================================================================================

## =======================================================================================
## Targets:
## =======================================================================================
# 1. Introduction file:
$(EXE_FILE1): start_operator_overl.cpp
	$(GCC) $(GCCFLAGS) start_operator_overl.cpp -o $(EXE_FILE1)

# 2. Normal function overload file:
$(EXE_FILE2): Normal_function_overload1.cpp
	$(GCC) $(GCCFLAGS) Normal_function_overload1.cpp -o $(EXE_FILE2)

# 3. Friend function overload file:
$(EXE_FILE3): Friend_function_overload2.cpp
	$(GCC) $(GCCFLAGS) Friend_function_overload2.cpp -o $(EXE_FILE3)

## =======================================================================================
# Clean up all the files.
clean:
	rm -f *.out *.o $(EXE_FILE1) $(EXE_FILE2) $(EXE_FILE3)
