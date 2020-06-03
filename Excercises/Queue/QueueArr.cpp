//
// Created by FatihPC on 1/5/2019.
//

#include "QueueArr.h"

QueueArr::QueueArr() {
    items = new QueueItemType[MAX_QUEUE];
    back  = MAX_QUEUE - 1;
    front = 0;
    count = 0;
}

bool QueueArr::isEmpty() const {
    return count == 0;
}

bool QueueArr::getFront(QueueItemType &queueFront) const {
    bool success = !isEmpty();

    if (success)
        queueFront = items[front];

    return success;
}

bool QueueArr::enqueue(QueueItemType newItem) {
    bool success = count < MAX_QUEUE;

    if (success) {
        back = (++back) % MAX_QUEUE;
        items[back] = newItem;
        count++;
    }

    return success;
}

bool QueueArr::dequeue() {
    bool success = !isEmpty();

    if (success) {
        front = (++front) % MAX_QUEUE;
        count--;
    }

    return success;
}

bool QueueArr::dequeue(QueueItemType &queueFront) {
    bool success = !isEmpty();

    if (success) {
        queueFront = items[front];
        front = (++front) % MAX_QUEUE;
        count--;
    }

    return success;
}
