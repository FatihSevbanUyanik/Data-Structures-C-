//
// Created by FatihPC on 12/8/2018.
//

#include "LinkedListADT.h"

#include <iostream>
using namespace std;

LinkedListADT::LinkedListADT() {
    size = 0;
    head = nullptr;
}

LinkedListADT::LinkedListADT(LinkedListADT &aList) {

    size = aList.size;

    if (size == 0)
        head = nullptr;

    else {

        head = new ListNode;
        head->nodeItem = aList.head->nodeItem;
        ListNode *newNodePtr = head;

        for (ListNode *iterativePtr = aList.head->next; iterativePtr != nullptr; iterativePtr = iterativePtr->next) {
            newNodePtr->next = new ListNode;
            newNodePtr = newNodePtr->next;
            newNodePtr->nodeItem = iterativePtr->nodeItem;
        }

        newNodePtr->next = nullptr;
    }
}

LinkedListADT::~LinkedListADT() {
    while (size != 0)
        remove(1);
}

bool LinkedListADT::isEmpty() const {
    return size == 0;
}

int LinkedListADT::getLength() const {
    return size;
}

ListNode* LinkedListADT::find(int index) const {

    ListNode *cur = head;

    for (int i = 1; i < index; i++)
        cur = cur->next;

    return cur;
}

bool LinkedListADT::retrieve(int index, ListItemType &dataItem) {

    bool success = index >= 1 && index <= size;

    if (success) {
        ListNode *desiredNodePtr = find(index);
        dataItem = desiredNodePtr->nodeItem;
    }

    return success;
}

bool LinkedListADT::remove(int index) {

    bool success = index >= 1 && index <= size;

    if (success) {

        if (index == 1) {
            ListNode *curNode = head;
            head = head->next;
            curNode->next = nullptr;
            delete curNode;
        }

        else {
            ListNode *prevNode = find(index - 1);
            ListNode *curNode = prevNode->next;
            ListNode *nextNode = curNode->next;

            prevNode->next = nextNode;
            curNode->next = nullptr;
            delete curNode;
        }

        size--;
    }
    return success;
}

bool LinkedListADT::insert(int index, ListItemType newItem) {

    bool success = index >= 1 && index <= size + 1;

    if (success) {

        ListNode *newNode = new ListNode;
        newNode->nodeItem = newItem;
        size++;

        if (index == 1) {
            newNode->next = head;
            head = newNode;
        }

        else {
            ListNode *prevNode = find(index - 1);
            ListNode *curNode = prevNode->next;

            prevNode->next = newNode;
            newNode->next = curNode;
        }
    }

    return success;
}

void LinkedListADT::displayReverseOrder() {
    displayReverseOrder(head);
}

void LinkedListADT::displayReverseOrder(ListNode *iterator) {
    if (iterator != nullptr) {
        displayReverseOrder(iterator->next);
        cout << iterator->nodeItem << endl;
    }
}



