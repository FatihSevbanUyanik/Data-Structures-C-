//
// Created by FatihPC on 11/26/2019.
//

#ifndef HEAPDS_HEAP_H
#define HEAPDS_HEAP_H

#include <iostream>
using namespace std;

typedef int HeapItemType;

class Heap {
public:
    Heap();				// default constructor
    // copy constructor and destructor are supplied by the compiler

    bool heapIsEmpty() const;
    void heapInsert(const HeapItemType& newItem);
    void heapDelete(HeapItemType& rootItem);
    void print();

protected:
    void heapRebuild(int root);		// Converts the semiheap rooted at
    // index root into a heap
private:
    HeapItemType items[1000];	// array of heap items
    int          size;            	// number of heap items
};



#endif //HEAPDS_HEAP_H
