//
// Created by FatihPC on 9/25/2019.
//

#ifndef LINKEDLISTADT_LINKEDLIST_H
#define LINKEDLISTADT_LINKEDLIST_H

#include <iostream>
using namespace std;

typedef int ListItemType;

struct ListNode {
    ListItemType nodeItem;
    ListNode *next;
};

class LinkedList {
public:
    LinkedList();
    ~LinkedList();

    bool isEmpty() const;
    int getLength() const;
    bool retrieve(int index, ListItemType &dataItem);
    bool insert(int index, ListItemType newItem);
    bool remove(int index);
    void displayList();
    void removeDuplicates();
    void reverseRecursive();
    void reverse();

private:
    int size;
    ListNode *head;
    ListNode* find(int index);
    void reverseRecursive(ListNode *prev, ListNode *cur);
};


#endif //LINKEDLISTADT_LINKEDLIST_H
