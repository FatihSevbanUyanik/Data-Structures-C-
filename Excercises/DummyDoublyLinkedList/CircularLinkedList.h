//
// Created by FatihPC on 12/12/2018.
//

#ifndef DUMMYDOUBLYLINKEDLIST_CIRCULARLINKEDLIST_H
#define DUMMYDOUBLYLINKEDLIST_CIRCULARLINKEDLIST_H

typedef int ListItemType;

struct Node {
    ListItemType nodeItem;
    Node *next;
};

class CircularLinkedList {

public:
    CircularLinkedList();
    CircularLinkedList(CircularLinkedList &aList);
    ~CircularLinkedList();

    bool isEmpty() const;
    int getLength() const;

    bool retrieve(int index, ListItemType &dataItem) const;
    bool insert(int index, ListItemType newItem);
    bool remove(int index);

private:
    Node* find(int index) const;
    int size;
    Node *tail;
};


#endif //DUMMYDOUBLYLINKEDLIST_CIRCULARLINKEDLIST_H
