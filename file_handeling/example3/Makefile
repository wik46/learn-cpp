# This is a Makefile for my main_read_file.cpp program.

gcc = g++

exe_file = store_from_file

# Here is where I created the target.

$(exe_file): main_read_data.o wizard.o
	$(gcc) main_read_data.o wizard.o -o $(exe_file)

main_read_data.o: main_read_data.cpp 
	$(gcc) -c main_read_data.cpp

wizard.o: wizard.cpp
	$(gcc) -c wizard.cpp

clean:
	rm -f *.out *.o $(exe_file)
