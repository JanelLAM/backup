edit: main.o timer.o
	g++ -o edit main.o timer.o

timer.o: timer.h
	g++ -o timer.o -c timer.cpp
main.o:  timer.h
	g++ -o main.o -c main.cpp
clean: 
	rm edit main.o timer.o
