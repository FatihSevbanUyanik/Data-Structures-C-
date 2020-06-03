//
// Created by FatihPC on 12/13/2018.
//

#ifndef RECURSION_CIRCULARDOUBLYDUMMYLINKEDLIST_H
#define RECURSION_CIRCULARDOUBLYDUMMYLINKEDLIST_H

typedef int ListItemType;

struct Node {
    int nodeItem;
    Node *predecessor;
    Node *successor;
};

class CircularDoublyDummyLinkedList {

public:
    CircularDoublyDummyLinkedList();
    CircularDoublyDummyLinkedList(CircularDoublyDummyLinkedList &aList);
    ~CircularDoublyDummyLinkedList();

    bool isEmpty() const;
    int getLength() const;
    bool retrieve(int index, ListItemType &dataItem) const;
    bool insert(int index, ListItemType newItem);
    bool remove(int index);

private:
    Node* find(int index) const;
    int size;
    Node *head;
};


#endif //RECURSION_CIRCULARDOUBLYDUMMYLINKEDLIST_H
