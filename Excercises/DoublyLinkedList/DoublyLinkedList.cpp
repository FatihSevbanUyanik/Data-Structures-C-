//
// Created by FatihPC on 12/9/2018.
//

#include "DoublyLinkedList.h"

#include <iostream>
using namespace std;


DoublyLinkedList::DoublyLinkedList() {
    size = 0;
    head = nullptr;
}

DoublyLinkedList::DoublyLinkedList(DoublyLinkedList &doublyLinkedList) {

    size = doublyLinkedList.size;

    if (size != 0) {

        head = new ListNode;
        head->nodeItem = doublyLinkedList.head->nodeItem;
        head->predecessor = nullptr;

        ListNode *nodeAdderPtr = head;
        nodeAdderPtr = head;

        for (ListNode *iterativePtr = doublyLinkedList.head->successor; iterativePtr != nullptr ; iterativePtr = iterativePtr->successor) {

            ListNode *previousNode = nodeAdderPtr;

            nodeAdderPtr->successor = new ListNode;
            nodeAdderPtr = nodeAdderPtr->successor;

            nodeAdderPtr->predecessor = previousNode;
            nodeAdderPtr->nodeItem = iterativePtr->nodeItem;
        }
    }

    else {
        head = nullptr;
    }

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

ListNode* DoublyLinkedList::find(int index) const {

    ListNode *iterativePtr = head;

    for (int i = 1; i < index; i++)
        iterativePtr = iterativePtr->successor;

    return iterativePtr;
}

bool DoublyLinkedList::retrieve(int index, ListItemType &dataItem) {

    bool success = (index >= 1) && (index <= size);

    if (success) {
        ListNode *correspondingListNode = find(index);
        dataItem = correspondingListNode->nodeItem;
    }

    return success;
}

bool DoublyLinkedList::remove(int index) {

    bool success = (index >= 1) && (index <= size);

    if (success) {

        if (index == 1) {

            if (size == 1) {
                head->successor = nullptr;
                head->predecessor = nullptr;
                delete head;
                head = nullptr;
            }

            else {
                ListNode *cur = find(index);
                ListNode *next = cur->successor;

                next->predecessor = nullptr;
                head = next;

                cur->successor = nullptr;
                delete cur;
            }
        }

        else if (index == size) {
            ListNode *cur = find(index);
            ListNode *prev = cur->predecessor;

            prev->successor = nullptr;
            cur->predecessor = nullptr;
            delete cur;
        }

        else {
            ListNode *cur = find(index);
            ListNode *prev = cur->predecessor;
            ListNode *next = cur->successor;

            prev->successor = next;
            next->predecessor = prev;

            cur->successor = nullptr;
            cur->predecessor = nullptr;
            delete cur;
        }

        size--;
    }

    return success;
}

bool DoublyLinkedList::insert(int index, ListItemType newItem) {

    bool success = (index >= 1) && (index <= size + 1);

    if (success) {

        ListNode *newNodePtr = new ListNode;
        newNodePtr->nodeItem = newItem;

        if (index == 1) {

            if (size != 0) {
                newNodePtr->successor = head;
                newNodePtr->predecessor = nullptr;

                head->predecessor = newNodePtr;
                head = newNodePtr;
            } else {
                newNodePtr->predecessor = nullptr;
                newNodePtr->successor = nullptr;
                head = newNodePtr;
            }
        }

        else if (index == size + 1) {
            ListNode *prev = find(index - 1);
            prev->successor = newNodePtr;
            newNodePtr->predecessor = prev;
            newNodePtr->successor = nullptr;
        }

        else {

            ListNode *cur = find(index);
            ListNode *prev = cur->predecessor;

            prev->successor = newNodePtr;
            newNodePtr->predecessor = prev;

            newNodePtr->successor = cur;
            cur->predecessor = newNodePtr;
        }
        size++;
    }

}




