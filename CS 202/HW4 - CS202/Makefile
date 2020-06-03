# Make file to compile source code

CC=g++

CFLAGS=-c -Wall

all: hw

hw: main.o ChainHashTable.o OpenHashTable.o OpenEntry.o ChainEntry.o FileReader.o
	$(CC) main.o ChainHashTable.o OpenHashTable.o OpenEntry.o ChainEntry.o FileReader.o -o hw4

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

ChainHashTable.o: ChainHashTable.cpp
	$(CC) $(CFLAGS) ChainHashTable.cpp
	
OpenHashTable.o: OpenHashTable.cpp
	$(CC) $(CFLAGS) OpenHashTable.cpp
	
OpenEntry.o: OpenEntry.cpp
	$(CC) $(CFLAGS) OpenEntry.cpp
	
ChainEntry.o: ChainEntry.cpp
	$(CC) $(CFLAGS) ChainEntry.cpp
	
FileReader.o: FileReader.cpp
	$(CC) $(CFLAGS) FileReader.cpp
	
clean:
	rm *o 21602486_hw4