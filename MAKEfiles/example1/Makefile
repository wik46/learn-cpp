all: app.exe
	
app.exe: main.o int_array.o float_array.o 
	g++ main.o int_array.o float_array.o -o app.exe
main.o: main.cpp
	g++ -c main.cpp -o main.o
int_array.o: int_array.cpp
	g++ -c int_array.cpp -o int_array.o
float_array.o: float_array.cpp
	g++ -c float_array.cpp
clean:
	rm *o app.exe 

