//
// Created by FatihPC on 9/27/2019.
//

#ifndef QUEUE_QUEUELISTADT_H
#define QUEUE_QUEUELISTADT_H

typedef int QueueItemType;

class QueueListADT {
public:
    QueueListADT();
    ~QueueListADT();
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


#endif //QUEUE_QUEUELISTADT_H
