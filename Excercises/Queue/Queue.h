//
// Created by FatihPC on 1/5/2019.
//

#ifndef QUEUE_QUEUE_H
#define QUEUE_QUEUE_H

typedef int QueueItemType;

class Queue{

public:
    Queue();                     // default constructor
    Queue(const Queue& Q);       // copy constructor
    ~Queue();                    // destructor

    // Queue operations:
    bool isEmpty() const;
    bool enqueue(QueueItemType newItem);
    bool dequeue();
    bool dequeue(QueueItemType& queueFront);
    bool getFront(QueueItemType& queueFront) const;

private:
    // Node
    struct QueueNode{
        QueueItemType  item;
        QueueNode     *next;
    };

    // external references
    QueueNode *backPtr;
    QueueNode *frontPtr;
};

#endif //QUEUE_QUEUE_H