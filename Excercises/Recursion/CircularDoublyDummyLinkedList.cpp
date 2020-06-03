//
// Created by FatihPC on 12/13/2018.
//

#include "CircularDoublyDummyLinkedList.h"

CircularDoublyDummyLinkedList::CircularDoublyDummyLinkedList() {
    size = 0;
    head = new Node;
    head->predecessor = head;
    head->successor = head;
}

CircularDoublyDummyLinkedList::CircularDoublyDummyLinkedList(CircularDoublyDummyLinkedList &aList) {
    size = aList.size;
    head = new Node;
    Node *replicatorPtr = head;

    for (Node *iterativePtr = aList.head->successor ; iterativePtr != aList.head ; iterativePtr = iterativePtr->successor) {
        Node *previousNode = replicatorPtr;

        replicatorPtr->successor = new Node;
        replicatorPtr = replicatorPtr->successor;

        replicatorPtr->nodeItem = iterativePtr->nodeItem;
        replicatorPtr->predecessor = previousNode;
    }

    replicatorPtr->successor = head;
    head->predecessor = replicatorPtr;
}

CircularDoublyDummyLinkedList::~CircularDoublyDummyLinkedList() {
    while (!isEmpty())
        remove(1);
}

bool CircularDoublyDummyLinkedList::isEmpty() const {
    return size == 0;
}

int CircularDoublyDummyLinkedList::getLength() const {
    return size;
}

Node* CircularDoublyDummyLinkedList::find(int index) const {

    if (index == 0)
        return head;

    else {
        Node *iterativePtr = head->successor;

        for (int i = 1; i < index; i++)
            iterativePtr = iterativePtr->successor;

        return iterativePtr;
    }
}

bool CircularDoublyDummyLinkedList::retrieve(int index, ListItemType &dataItem) const {
    bool success =  index <= size && index >= 1;

    if (success)
        dataItem = find(index)->nodeItem;

    return success;
}

bool CircularDoublyDummyLinkedList::insert(int index, ListItemType newItem) {
    bool success = index <= (size + 1) && index >= 1;

    if (success) {
        Node *newNode = new Node;
        newNode->nodeItem = newItem;

        Node *prev = find(index - 1);
        Node *cur  = prev->successor;

        newNode->predecessor = prev;
        prev->successor = newNode;

        newNode->successor = cur;
        cur->predecessor = newNode;
        size++;
    }
    return success;
}

bool CircularDoublyDummyLinkedList::remove(int index) {
    bool success = index <= size && index >= 1;

    if (success) {
        Node *prev = find(index - 1);
        Node *cur  = prev->successor;
        Node *next = cur->successor;

        prev->successor = next;
        next->predecessor = prev;

        cur->predecessor = nullptr;
        cur->successor = nullptr;
        size--;
    }
    return success;
}