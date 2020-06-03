//
// Created by FatihPC on 1/5/2019.
//

#include "Queue.h"
#include <iostream>
using namespace std;

Queue::Queue() {
    backPtr  = nullptr;
    frontPtr = nullptr;
}

Queue::Queue(const Queue &Q) {

    if (Q.frontPtr != nullptr) {
        // replicating front node.
        frontPtr = new QueueNode;
        frontPtr->item = Q.frontPtr->item;
        backPtr = frontPtr;

        // replicating remaining items.
        for (QueueNode *iterativePtr = Q.frontPtr->next; iterativePtr != nullptr; iterativePtr = iterativePtr->next) {
            backPtr->next = new QueueNode;
            backPtr = backPtr->next;
            backPtr->item = iterativePtr->item;
        }

        backPtr->next = nullptr;
    }

    else { // Q has no items.
        frontPtr = nullptr;
        backPtr  = nullptr;
    }
}

Queue::~Queue() {
    while (!isEmpty())
        dequeue();
}

bool Queue::isEmpty() const {
    return frontPtr == nullptr;
}

bool Queue::enqueue(QueueItemType newItem) {
    // constructing new node.
    QueueNode *newNode = new QueueNode;
    newNode->item = newItem;
    newNode->next = nullptr;

    // queue is empty.
    if (isEmpty())
        frontPtr = newNode;

    else {
        // enqueueing new node.
        backPtr->next = newNode;
        newNode->next = nullptr;
    }

    backPtr = newNode;
    return true;
}

bool Queue::getFront(QueueItemType &queueFront) const {
    bool success = !isEmpty();

    if (success)
        queueFront = frontPtr->item;

    return success;
}


bool Queue::dequeue() {
    bool success = !isEmpty();

    if (success) {
        QueueNode *temp = frontPtr;

        if (frontPtr == backPtr) {
            frontPtr = nullptr;
            backPtr  = nullptr;
        }

        else frontPtr = frontPtr->next;

        temp->next = nullptr;
        delete temp;
    }

    return success;
}

bool Queue::dequeue(QueueItemType &queueFront) {
    bool success = !isEmpty();

    if (success) {
        QueueNode *temp = frontPtr;

        if (frontPtr == backPtr) {
            frontPtr = nullptr;
            backPtr  = nullptr;
        }

        else frontPtr = frontPtr->next;

        temp->next = nullptr;
        queueFront = temp->item;
        delete temp;
    }

    return success;
}