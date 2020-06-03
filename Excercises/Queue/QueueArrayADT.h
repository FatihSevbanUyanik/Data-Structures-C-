//
// Created by FatihPC on 9/27/2019.
//

#ifndef QUEUE_QUEUEARRAYADT_H
#define QUEUE_QUEUEARRAYADT_H

#include <iostream>
using namespace std;

const int MAX_QUEUE = 5;
typedef int QueueItemType;

class QueueArrayADT {
public:
    QueueArrayADT();
    // Queue operations:
    bool isEmpty() const;
    bool enqueue(QueueItemType newItem);
    bool dequeue();
    bool dequeue(QueueItemType& queueFront);
    bool getFront(QueueItemType& queueFront) const;

private:
    QueueItemType *items;
    int front;
    int back;
};


#endif //QUEUE_QUEUEARRAYADT_H
