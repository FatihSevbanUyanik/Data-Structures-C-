//
// Created by FatihPC on 9/27/2019.
//

#include "QueueArrayADT.h"

QueueArrayADT::QueueArrayADT() {
    items = new QueueItemType[MAX_QUEUE];
    front = 0;
    back = 0;
}

bool QueueArrayADT::isEmpty() const {
    return front == back;
}

bool QueueArrayADT::getFront(QueueItemType &queueFront) const {
    bool success = !isEmpty();

    if (success) {
        queueFront = items[front];
    }

    return success;
}

bool QueueArrayADT::dequeue() {
    bool success = !isEmpty();

    if (success) {
        front = ++front % MAX_QUEUE;
    }

    return success;
}

bool QueueArrayADT::dequeue(QueueItemType &queueFront) {
    bool success = !isEmpty();

    if (success) {
        queueFront = items[front];
        front = ++front % MAX_QUEUE;
    }

    return success;
}

bool QueueArrayADT::enqueue(QueueItemType newItem) {
    bool success = ((back + 1) % MAX_QUEUE) != (front % MAX_QUEUE);

    if (success) {
        items[back] = newItem;
        back = ++back % MAX_QUEUE;
    }

    return success;
}