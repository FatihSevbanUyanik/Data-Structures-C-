//
// Created by FatihPC on 12/12/2018.
//

#ifndef DUMMYDOUBLYLINKEDLIST_DOUBLYLINKEDLIST_H
#define DUMMYDOUBLYLINKEDLIST_DOUBLYLINKEDLIST_H

typedef int ListItemType;

struct Node {
    ListItemType nodeItem;
    Node *successor;
    Node *predecessor;
};

class DoublyLinkedList {

    DoublyLinkedList();
    DoublyLinkedList(DoublyLinkedList &aList);
    ~DoublyLinkedList();

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


#endif //DUMMYDOUBLYLINKEDLIST_DOUBLYLINKEDLIST_H
