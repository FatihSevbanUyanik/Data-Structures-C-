# Make file to compile source code

CC=g++
CFLAGS=-c -Wall

all: hw

hw: main.o sorting.o
	$(CC) main.o sorting.o  


main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp



sorting.o: sorting.cpp
	$(CC) $(CFLAGS) sorting.cpp


clean:
	rm *o 21602486_hw1
