//
// Created by FatihPC on 11/26/2019.
//

#include "Heap.h"

Heap::Heap(int maxSize) {
    items = new ServerRequest[maxSize];
    curSize = 0;
}

bool Heap::heapIsEmpty() const {
    return curSize == 0;
}

void Heap::heapInsert(const ServerRequest &newItem) {
    if (curSize < maxSize) {
        items[curSize] = newItem;
        int place = curSize++;
        int parent = (place-1) / 2;

        while ((place > 0 && items[place].getPriority() > items[parent].getPriority()) ||
               (place > 0 && items[place].getPriority() == items[parent].getPriority() &&
               items[place].getTimeOfRequest() < items[parent].getTimeOfRequest())) {
            ServerRequest temp = items[parent];
            items[parent] = items[place];
            items[place] = temp;
            place = parent;
            parent = (place-1) / 2;
        }
    }
}

void Heap::heapDelete(ServerRequest &rootItem) {
    if (heapIsEmpty()) {
        return;
    }
    rootItem.setId(items[0].getId());
    rootItem.setPriority(items[0].getPriority());
    rootItem.setProcessTime(items[0].getProcessTime());
    rootItem.setTimeOfRequest(items[0].getTimeOfRequest());
    items[0] = items[--curSize];
    heapRebuild(0);
}

void Heap::heapRebuild(int root) {
    int child =  2 * root + 1;

    if (child < curSize) {
        int rightChild = child + 1;

        if ((rightChild < curSize && items[rightChild].getPriority() > items[child].getPriority()) ||
            (rightChild < curSize && items[rightChild].getPriority() == items[child].getPriority() &&
            items[rightChild].getTimeOfRequest() < items[child].getTimeOfRequest())) {
            // assign right child.
            child = rightChild;
        }
        if ((items[child].getPriority() > items[root].getPriority()) ||
            (items[child].getPriority() == items[root].getPriority() &&
            items[child].getTimeOfRequest() < items[root].getTimeOfRequest())) {
            // swap nodes.
            ServerRequest temp = items[child];
            items[child] = items[root];
            items[root] = temp;
            heapRebuild(child);
        }
    }
}

void Heap::print() {
    cout << "----------------------------------------" << endl;
    cout << "[ ";
    for (int i = 0; i < curSize; i++) {
        cout << items[i].getId()            << ", " <<
                items[i].getPriority()      << ", " <<
                items[i].getTimeOfRequest() << ", " <<
                items[i].getProcessTime()   << " ";
        if (i != curSize - 1) {
            cout << "| ";
        }
    }
    cout << " ]" << endl;
    cout << "----------------------------------------" << endl;
}

int Heap::getSize() {
    return curSize;
}
