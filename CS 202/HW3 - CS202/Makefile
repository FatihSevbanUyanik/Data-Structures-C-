# Make file to compile source code

CC=g++

CFLAGS=-c -Wall

all: hw

hw: main.o FileReader.o PriorityQueue.o ServerRequest.o Heap.o Computer.o
	$(CC) main.o FileReader.o PriorityQueue.o ServerRequest.o Heap.o Computer.o -o hw3

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

FileReader.o: FileReader.cpp
	$(CC) $(CFLAGS) FileReader.cpp

PriorityQueue.o: PriorityQueue.cpp
	$(CC) $(CFLAGS) PriorityQueue.cpp
	
ServerRequest.o: ServerRequest.cpp
	$(CC) $(CFLAGS) ServerRequest.cpp
	
Heap.o: Heap.cpp
	$(CC) $(CFLAGS) Heap.cpp
	
Computer.o: Computer.cpp
	$(CC) $(CFLAGS) Computer.cpp	

clean:
	rm *o 21602486_hw3
