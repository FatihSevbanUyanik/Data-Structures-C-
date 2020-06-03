//
// Created by FatihPC on 11/27/2019.
//

#ifndef HW3_PRIORITYQUEUE_H
#define HW3_PRIORITYQUEUE_H

#include "Heap.h"
#include "ServerRequest.h"

class PriorityQueue {
public:
    PriorityQueue(int maxSize);
    bool pqIsEmpty() const;
    void pqInsert(const ServerRequest& newItem);
    void pqDelete(ServerRequest& priorityItem);
    void print();
    int getSize();
private:
    Heap *heap;
};


#endif //HW3_PRIORITYQUEUE_H
