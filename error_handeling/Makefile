## Author: Wikus Jansen van Rensburg
## Date: December 6, 2020.
## Description: This is the build system used for the error_handeling/ directory.
## =======================================================================================


## =======================================================================================
#  Variables:
## =======================================================================================
GCC = g++
GCCFLAGS = -std=c++11 -g

EXE_FILE1 = intro1
EXE_FILE2 = intro2
EXE_FILE3 = intro3
EXE_FILE4 = intro4

EXE_FILE5 = print_statements 
EXE_FILE6 = stack_unwinding1
EXE_FILE7 = std_exception

## =======================================================================================

## =======================================================================================
#  Targets:
## =======================================================================================
# 1. Introduction file 1:
$(EXE_FILE1): intro1.cpp
	$(GCC) $(GCCFLAGS) intro1.cpp -o $(EXE_FILE1)

# 2. Introduction file 2:
$(EXE_FILE2): intro2.cpp
	$(GCC) $(GCCFLAGS) intro2.cpp -o $(EXE_FILE2)

# 3. Introduction file 3:
$(EXE_FILE3): intro3.cpp
	$(GCC) $(GCCFLAGS) intro3.cpp -o $(EXE_FILE3)

# 4. Introduction file 4:
$(EXE_FILE4): intro4.cpp
	$(GCC) $(GCCFLAGS) intro4.cpp -o $(EXE_FILE4)

# 5. Introduction file 5:
$(EXE_FILE5): print_statements.cpp
	$(GCC) $(GCCFLAGS) print_statements.cpp -o $(EXE_FILE5)

# 6. Introduction file 6:
$(EXE_FILE6): stack_unwinding1.cpp
	$(GCC) $(GCCFLAGS) stack_unwinding1.cpp -o $(EXE_FILE6)

# 7. Introduction file 7:
$(EXE_FILE7): std_exception.cpp
	$(GCC) $(GCCFLAGS) std_exception.cpp -o $(EXE_FILE7)



# To clean the program
clean:	
	rm -f *.out $(EXE_FILE1) $(EXE_FILE2) $(EXE_FILE3) $(EXE_FILE4) $(EXE_FILE5) $(EXE_FILE6) $(EXE_FILE7) 
## =======================================================================================
