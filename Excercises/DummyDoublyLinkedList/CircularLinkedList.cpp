//
// Created by FatihPC on 12/12/2018.
//

#include "CircularLinkedList.h"
#include <iostream>
using namespace std;

CircularLinkedList::CircularLinkedList() {
    size = 0;
    tail = nullptr;
}

CircularLinkedList::CircularLinkedList(CircularLinkedList &aList) {

    size = aList.size;

    if (size == 0)
        tail = nullptr;

    else {

        tail = new Node;
        tail->nodeItem = aList.tail->next->nodeItem;
        Node *head = tail;

        for ( Node *iterativePtr = aList.tail->next->next ; iterativePtr != aList.tail->next  ; iterativePtr = iterativePtr->next) {
            tail->next = new Node;
            tail = tail->next;
            tail->nodeItem = iterativePtr->nodeItem;
        }

        tail->next = head;
    }

}

CircularLinkedList::~CircularLinkedList() {
    while (size != 0)
        remove(1);
}

bool CircularLinkedList::isEmpty() const {
    return size == 0;
}

int CircularLinkedList::getLength() const {
    return size;
}

Node* CircularLinkedList::find(int index) const {

    if (index == 0)
        return tail;

    else {
        Node *result = tail->next;

        for (int i = 1; i < index; ++i) {
            result = result->next;
        }

        return result;
    }

}

bool CircularLinkedList::retrieve(int index, ListItemType &dataItem) const {
    bool success = index <= size && index >= 1;

    if (success)
        dataItem = find(index)->nodeItem;

    return success;
}

bool CircularLinkedList::insert(int index, ListItemType newItem) {

    bool success = (index <= size + 1) && (index >= 1);

    if (success) {

        Node *newNode = new Node;
        newNode->nodeItem = newItem;

        if (size == 0) {
            tail =newNode;
            tail->next = tail;
        }

        else {
            Node *prev = find(index - 1);
            Node *cur = prev->next;

            prev->next = newNode;
            newNode->next = cur;
        }

        size++;

        if (size == index)
            tail = newNode;
    }

    return success;
}

bool CircularLinkedList::remove(int index) {

    bool success = (index <= size) && (index >= 1);

    if (success) {

        if (size == 1) {
            delete tail;
            tail = nullptr;
        }

        else {
            Node *prevNode = find(index - 1);
            Node *curNode  = prevNode->next;
            Node *nextNode = curNode->next;

            prevNode->next = nextNode;
            curNode->next = nullptr;
            delete curNode;

            if (index == size)
                tail = prevNode;
        }

        size--;
    }

    return success;
}
