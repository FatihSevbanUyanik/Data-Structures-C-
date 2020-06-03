//
// Created by FatihPC on 11/27/2019.
//

#include "PriorityQueue.h"

PriorityQueue::PriorityQueue(int maxSize) {
    heap = new Heap(maxSize);
}

bool PriorityQueue::pqIsEmpty() const {
    return heap->heapIsEmpty();
}

void PriorityQueue::pqInsert(const ServerRequest &newItem) {
    heap->heapInsert(newItem);
}

void PriorityQueue::pqDelete(ServerRequest &priorityItem) {
    heap->heapDelete(priorityItem);
}

void PriorityQueue::print() {
    heap->print();
}

int PriorityQueue::getSize() {
    return heap->getSize();
}

