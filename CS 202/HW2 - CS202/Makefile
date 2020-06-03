# Make file to compile source code

CC=g++

CFLAGS=-c -Wall

all: hw

hw: main.o NgramTree.o TreeNode.o KeyedItem.o
	$(CC) main.o NgramTree.o TreeNode.o KeyedItem.o -o hw2

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

NgramTree.o: NgramTree.cpp
	$(CC) $(CFLAGS) NgramTree.cpp

TreeNode.o: TreeNode.cpp
	$(CC) $(CFLAGS) TreeNode.cpp
	
KeyedItem.o: KeyedItem.cpp
	$(CC) $(CFLAGS) KeyedItem.cpp

clean:
	rm *o 21602486_hw2
