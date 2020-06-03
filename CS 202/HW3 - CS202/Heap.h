//
// Created by FatihPC on 11/26/2019.
//

#ifndef HW3_PRIORITYQUEUEHEAP_H
#define HW3_PRIORITYQUEUEHEAP_H

#include <iostream>
#include "ServerRequest.h"

using namespace std;

class Heap {
public:
    Heap(int maxSize);
    bool heapIsEmpty() const;
    void heapInsert(const ServerRequest& newItem);
    void heapDelete(ServerRequest& rootItem);
    int getSize();
    void print();
protected:
    void heapRebuild(int root);

private:
    ServerRequest *items;
    int curSize;
    int maxSize;

};


#endif //HW3_PRIORITYQUEUEHEAP_H
