//
// Created by FatihPC on 12/14/2018.
//

#ifndef RECURSION_LINKEDLIST_H
#define RECURSION_LINKEDLIST_H

typedef int ListItemType;

struct Node {
    ListItemType dataItem;
    Node *next;
};

class LinkedList {

public:
    LinkedList();
    LinkedList(LinkedList &aList);
    ~LinkedList();

    bool isEmpty() const;
    int getLength() const;
    bool retrieve(int index, ListItemType &dataItem) const;
    bool insert(int index, ListItemType newItem);
    bool remove(int index);

private:
    Node* find(int index) const;
    Node *head;
    int size;
};


#endif //RECURSION_LINKEDLIST_H
