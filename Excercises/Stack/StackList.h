//
// Created by FatihPC on 1/5/2019.
//

#ifndef STACK_STACKLIST_H
#define STACK_STACKLIST_H

typedef char StackItemType;

class StackList{

public:
    StackList();
    StackList(const StackList& aStack);
    ~StackList();

    bool isEmpty() const;
    bool push(StackItemType newItem);
    bool pop();
    bool pop(StackItemType& stackTop);
    bool getTop(StackItemType& stackTop) const;

private:
    struct StackNode {            // a node on the stack
        StackItemType item;        // a data item on the stack
        StackNode    *next;        // pointer to next node
    };

    StackNode *topPtr;     // pointer to first node in the stack
};

#endif //STACK_STACKLIST_H