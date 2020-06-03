//
// Created by FatihPC on 1/5/2019.
//

#include "StackArray.h"

Stack::Stack() {
    top = -1;
    items = new StackItemType[100];
}

bool Stack::isEmpty() const {
    return top < 0;
}

bool Stack::getTop(StackItemType &stackTop) const {
    bool success = !isEmpty();

    if (success)
        stackTop = items[top];

    return success;
}

bool Stack::pop() {
    bool success = !isEmpty();

    if (success)
        top--;

    return success;
}

bool Stack::pop(StackItemType &stackTop) {
    bool success = !isEmpty();

    if (success)
        stackTop = items[top--];

    return success;
}

bool Stack::push(StackItemType newItem) {
    bool success = top < MAX_STACK;

    if (success)
        items[++top] = newItem;

    return success;
}