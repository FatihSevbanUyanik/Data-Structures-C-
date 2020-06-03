//
// Created by FatihPC on 12/14/2018.
//

#include "LinkedList.h"

LinkedList::LinkedList() {
    size = 0;
    head = nullptr;
}

LinkedList::LinkedList(LinkedList &aList) {

    size = aList.size;

    if (size == 0)
        head = nullptr;

    else {
        head = new Node;
        head->dataItem = aList.head->dataItem;
        Node *replicatorPtr = head;

        for (Node *iterativePtr = aList.head->next; iterativePtr != nullptr ; iterativePtr = iterativePtr->next) {
            replicatorPtr->next = new Node;
            replicatorPtr = replicatorPtr->next;
            replicatorPtr->dataItem = iterativePtr->dataItem;
        }

        replicatorPtr->next = nullptr;
    }
}

LinkedList::~LinkedList() {
    while (!isEmpty())
        remove(1);
}

bool LinkedList::isEmpty() const {
    return size == 0;
}

int LinkedList::getLength() const {
    return size;
}

Node* LinkedList::find(int index) const {
    Node *result = head;

    for (int i = 1; i < index; i++)
        result = result->next;

    return result;
}

bool LinkedList::retrieve(int index, ListItemType &dataItem) const {
    bool success = index >= 1 && index <= size;

    if (success)
        dataItem = find(index)->dataItem;

    return success;
}

bool LinkedList::insert(int index, ListItemType newItem) {
    bool success = index <= (size + 1) && index >= 1;

    if (success) {
        Node *newNode = new Node;
        newNode->dataItem = newItem;

        if (index == 1) {
            newNode->next = head;
            head = newNode;
        }

        else {
            Node *prev = find(index - 1);
            Node *cur  = prev->next;

            newNode->next = cur;
            prev->next = newNode;
        }

        size++;
    }
    return success;
}

bool LinkedList::remove(int index) {

    bool success = index <= (size + 1) && index >= 1;

    if (success) {

        if (index == 1) {
            Node *cur = head;
            head = head->next;
            cur->next = nullptr;
            delete cur;
        }

        else {
            Node *prevNode = find(index - 1);
            Node *curNode  = prevNode->next;
            Node *nextNode = curNode->next;

            prevNode->next = nextNode;
            curNode->next = nullptr;
            delete curNode;
        }

        size--;
    }

    return success;
}


