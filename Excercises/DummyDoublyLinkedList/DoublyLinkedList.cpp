//
// Created by FatihPC on 12/12/2018.
//

#include "DoublyLinkedList.h"

DoublyLinkedList::DoublyLinkedList() {
    size = 0;
    head = new Node;
    head->predecessor = nullptr;
    head->successor = nullptr;
}

DoublyLinkedList::DoublyLinkedList(DoublyLinkedList &aList) {

    size = aList.size;
    head = new Node;
    head->predecessor = nullptr;
    Node *replicator = head;

    for (Node *iterativePtr = aList.head->successor; iterativePtr != nullptr ; iterativePtr = iterativePtr->successor) {
        Node *previousNode = replicator;

        replicator->successor = new Node;
        replicator = replicator->successor;

        replicator->predecessor = previousNode;
        replicator->nodeItem = iterativePtr->nodeItem;
    }

    replicator->successor = nullptr;
}

DoublyLinkedList::~DoublyLinkedList() {
    while (size != 0)
        remove(1);
}

bool DoublyLinkedList::isEmpty() const {
    return size == 0;
}

int DoublyLinkedList::getLength() const {
    return size;
}

Node* DoublyLinkedList::find(int index) const {

    if (index == 0)
        return head;

    else {
        Node *result = head->successor;

        for (int i = 0; i < index; i++)
            result = result->successor;

        return result;
    }
}

bool DoublyLinkedList::retrieve(int index, ListItemType &dataItem) const {
    bool success = index <= size && index >= 1;

    if (success)
        dataItem = find(index)->nodeItem;

    return success;
}

bool DoublyLinkedList::insert(int index, ListItemType newItem) {

    bool success = index >= 1 && index <= size + 1;

    if (success) {

        Node *newNode = new Node;
        newNode->nodeItem = newItem;

        Node *prev = find(index - 1);
        Node *cur  = prev->successor;

        prev->successor = newNode;
        newNode->predecessor = prev;

        if (cur != nullptr) {
            cur->predecessor = newNode;
            newNode->successor = newNode;
        } else {
            newNode->successor= nullptr;
        }

        size++;
    }

    return success;
}

bool DoublyLinkedList::remove(int index) {

    bool success = index >= 1 && index <= size;

    if (success) {

        Node *prev = find(index - 1);
        Node *cur  = prev->successor;
        Node *next = cur->successor;

        if (index != size) {
            prev->successor = next;
            next->predecessor = prev;

            cur->predecessor = nullptr;
            cur->successor = nullptr;
        }

        else {
            prev->successor = nullptr;
            cur->predecessor = nullptr;
        }

        delete cur;
        size--;
    }

    return success;
}