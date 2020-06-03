//
// Created by FatihPC on 9/25/2019.
//

#include "LinkedList.h"

LinkedList::LinkedList() {
    size = 0;
    head = nullptr;
}

int LinkedList::getLength() const {
    return size;
}

bool LinkedList::isEmpty() const {
    return size == 0;
}

ListNode* LinkedList::find(int index) {
    ListNode *ptr = head;

    for (int i = 1; i < index; i++) {
        ptr = ptr->next;
    }

    return ptr;
}

bool LinkedList::insert(int index, ListItemType newItem) {
    bool success = 0 < index && index <= size + 1;

    if (success) {
        size++;
        ListNode *newNode = new ListNode;
        newNode->nodeItem = newItem;

        if (index == 1) {
            newNode->next = head;
            head = newNode;
        }
        else {
            ListNode *prev = find(index-1);
            ListNode *cur = prev->next;
            prev->next = newNode;
            newNode->next = cur;
        }
    }

    return success;
}

bool LinkedList::remove(int index) {
    bool success = 0 < index && index <= size;

    if (success) {
        size--;
        if (index == 1) {
            ListNode *temp = head;
            head = head->next;
            temp->next = nullptr;
            delete temp;
        }
        else {
            ListNode *prev = find(index-1);
            ListNode *cur = prev->next;
            prev->next = cur->next;
            cur->next = nullptr;
            delete cur;
        }
    }

    return success;
}

bool LinkedList::retrieve(int index, ListItemType &dataItem) {
    bool success = 0 < index && index <= size;

    if (success) {
        ListNode *temp = find(index);
        dataItem = temp->nodeItem;
    }

    return success;
}

void LinkedList::removeDuplicates() {
    ListNode *prev = head;
    ListNode *cur = prev->next;

    while (cur != nullptr) {
        if (prev->nodeItem != cur->nodeItem) {
            prev = cur;
            cur = cur->next;
        }
        else {
            prev->next = cur->next;
            cur->next = nullptr;
            delete cur;
            cur = prev->next;
            size--;
        }
    }

}

void LinkedList::reverse() {
     ListNode *ptr1 = nullptr;
     ListNode *ptr2 = head;
     ListNode *ptr3 = head->next;

     while (ptr3 != nullptr) {
         ptr2->next = ptr1;
         ptr1 = ptr2;
         ptr2 = ptr3;
         ptr3 = ptr3->next;
     }

    ptr2->next = ptr1;
    head = ptr2;
}

void LinkedList::displayList() {
    ListNode *temp = head;
    cout << "-----------------------------------------" << endl;
    cout << "[ ";

    for (int i = 1; i <= size; i++) {
        cout << temp->nodeItem << " ";
        temp = temp->next;
    }

    cout << "]" << endl;
    cout << "-----------------------------------------" << endl;
}

void LinkedList::reverseRecursive() {
    reverseRecursive(nullptr, head);
}

void LinkedList::reverseRecursive(ListNode *prev, ListNode *cur) {
    if (cur == nullptr) {
        head = prev;
        return;
    }
    reverseRecursive(cur, cur->next);
    cur->next  = prev;
}

LinkedList::~LinkedList() {
    while (size > 0) {
        remove(1);
    }
}