//
// Created by FatihPC on 1/5/2019.
//

#include "StackList.h"

StackList::StackList() {
    topPtr = nullptr;
}

StackList::StackList(const StackList &aStack) {

    if (!aStack.isEmpty()) {

        topPtr = new StackNode;
        topPtr->item = aStack.topPtr->item;
        StackNode *replicatorPtr = topPtr;

        for (StackNode *iterativePtr = aStack.topPtr->next; iterativePtr != nullptr ; iterativePtr = iterativePtr->next) {
            replicatorPtr->next = new StackNode;
            replicatorPtr = replicatorPtr->next;
            replicatorPtr->item = iterativePtr->item;
        }

        replicatorPtr->next = nullptr;
    }

    else topPtr = nullptr;
}

StackList::~StackList() {
    while (!isEmpty())
        pop();
}

bool StackList::isEmpty() const {
    return topPtr == nullptr;
}

bool StackList::push(StackItemType newItem) {
    StackNode *newNode = new StackNode;
    newNode->item = newItem;
    newNode->next = topPtr;
    topPtr = newNode;
    return true;
}

bool StackList::pop() {
    bool success = !isEmpty();

    if (success) {
        StackNode *temp = topPtr;
        topPtr = topPtr->next;
        temp->next = nullptr;
        delete temp;
    }

    return success;
}

bool StackList::pop(StackItemType &stackTop) {
    bool success = !isEmpty();

    if (success) {
        StackNode *temp = topPtr;
        stackTop = temp->item;
        topPtr = topPtr->next;
        temp->next = nullptr;
        delete temp;
    }

    return success;
}

bool StackList::getTop(StackItemType &stackTop) const {
    bool success = !isEmpty();

    if (success)
        stackTop = topPtr->item;

    return success;
}