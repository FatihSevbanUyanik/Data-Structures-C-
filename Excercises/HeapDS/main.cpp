#include <iostream>
#include "Heap.h"

int main() {

    Heap heap;
    heap.heapInsert(100);
    heap.heapInsert( 80);
    heap.heapInsert(120);
    heap.heapInsert( 90);
    heap.heapInsert( 70);
    heap.heapInsert(150);
    heap.print();

    int root;
    heap.heapDelete(root);
    heap.heapDelete(root);
    heap.heapDelete(root);

    heap.print();

    return 0;
}