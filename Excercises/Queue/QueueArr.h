//
// Created by FatihPC on 1/5/2019.
//

#ifndef QUEUE_QUEUEARR_H
#define QUEUE_QUEUEARR_H


const int MAX_QUEUE = 10;
typedef int QueueItemType;

class QueueArr{

public:
    QueueArr();  // default constructor
    // copy constructor and destructor are
    // supplied by the compiler

    // Queue operations:
    bool isEmpty() const;
    bool enqueue(QueueItemType newItem);
    bool dequeue();
    bool dequeue(QueueItemType& queueFront);
    bool getFront(QueueItemType& queueFront) const;

private:
    QueueItemType *items;
    int           front;
    int           back;
    int           count;

};



#endif //QUEUE_QUEUEARR_H
