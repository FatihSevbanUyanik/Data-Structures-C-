//
// Created by FatihPC on 11/26/2019.
//

#include "Heap.h"

Heap::Heap() {
    size = 0;
}

bool Heap::heapIsEmpty() const {
    return size == 0;
}

void Heap::heapDelete(HeapItemType &rootItem) {
    if (heapIsEmpty()) {
        cout << "EMPTY HEAP: DELETION NOT POSSIBLE" << endl;
        return;
    }
    rootItem = items[0];
    items[0] = items[--size];
    heapRebuild(0);
}

void Heap::heapRebuild(int root) {
    int child = 2 * root + 1;

    if (child < size) {
        int rightChild = child + 1;
        if (rightChild < size && items[child] < items[rightChild]) {
            child++;
        }

        if (items[root] < items[child]) {
            int temp = items[child];
            items[child] = items[root];
            items[root] = temp;
            heapRebuild(child);
        }
    }
}

void Heap::heapInsert(const HeapItemType &newItem) {
    if (size < 1000) {
        items[size] = newItem;
        int current = size++;
        int parent = (current - 1) / 2;

        while (current > 0 && items[parent] < items[current]) {
            int temp = items[current];
            items[current] = items[parent];
            items[parent] = temp;
            current = parent;
            parent = (current - 1) / 2;
        }
    }
}

void Heap::print() {
    cout << "----------------------------------------" << endl;
    cout << "[ ";
    for (int i = 0; i < size; i++) {
        cout << items[i];
        if (i != size - 1) {
            cout << ", ";
        }
    }
    cout << " ]" << endl;
    cout << "----------------------------------------" << endl;
}
