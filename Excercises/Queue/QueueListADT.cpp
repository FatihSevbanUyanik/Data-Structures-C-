//
// Created by FatihPC on 9/27/2019.
//

#include "QueueListADT.h"

QueueListADT::QueueListADT() {
    backPtr = nullptr;
    frontPtr = nullptr;
}

bool QueueListADT::isEmpty() const {
    return frontPtr == nullptr;
}

bool QueueListADT::getFront(QueueItemType &queueFront) const {
    bool success = !isEmpty();

    if (success) {
        queueFront = frontPtr->item;
    }

    return success;
}

bool QueueListADT::enqueue(QueueItemType newItem) {
    QueueNode *newNode = new QueueNode;
    newNode->item = newItem;

    if (isEmpty()) {
        frontPtr = newNode;
        backPtr = newNode;
    } else {
        backPtr->next = newNode;
        backPtr = newNode;
    }

    return true;
}

bool QueueListADT::dequeue() {
    bool success = !isEmpty();

    if (success) {
        if (backPtr == frontPtr) {
            delete frontPtr;
            frontPtr = nullptr;
            backPtr = nullptr;
        }
        else {
            QueueNode *tmp = frontPtr;
            frontPtr = frontPtr->next;
            tmp->next = nullptr;
            delete tmp;
        }
    }

    return success;
}

bool QueueListADT::dequeue(QueueItemType &queueFront) {
    bool success = !isEmpty();

    if (success) {
        queueFront = frontPtr->item;

        if (backPtr == frontPtr) {
            delete frontPtr;
            frontPtr = nullptr;
            backPtr = nullptr;
        }
        else {
            QueueNode *tmp = frontPtr;
            frontPtr = frontPtr->next;
            tmp->next = nullptr;
            delete tmp;
        }
    }

    return success;
}

QueueListADT::~QueueListADT() {
    while (!isEmpty()) {
        dequeue();
    }
}