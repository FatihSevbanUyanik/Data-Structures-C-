//
// Created by FatihPC on 12/8/2018.
//

#ifndef LINKEDLIST_LINKEDLISTADT_H
#define LINKEDLIST_LINKEDLISTADT_H

typedef int ListItemType;

struct ListNode {
    ListItemType nodeItem;
    ListNode *next;
};

class LinkedListADT {

public:
    LinkedListADT();
    LinkedListADT(LinkedListADT &aList);
    ~LinkedListADT();

    bool isEmpty() const;
    int getLength() const;
    bool retrieve(int index, ListItemType &dataItem);
    bool insert(int index, ListItemType newItem);
    bool remove(int index);
    void displayReverseOrder();

private:

    int size;
    ListNode *head;
    ListNode *find(int index) const;
    void displayReverseOrder(ListNode *iterator);
};


#endif //LINKEDLIST_LINKEDLISTADT_H
