//
// Created by FatihPC on 1/5/2019.
//

#ifndef STACK_STACK_H
#define STACK_STACK_H

const int MAX_STACK = 100;
typedef char StackItemType;

class Stack{

public:
    Stack();
    bool isEmpty() const;
    bool push(StackItemType newItem);
    bool pop();
    bool pop(StackItemType& stackTop);
    bool getTop(StackItemType& stackTop) const;

private:
    // array of stack items
    StackItemType *items;
    // index to top of stack
    int top;
};

#endif //STACK_STACK_H