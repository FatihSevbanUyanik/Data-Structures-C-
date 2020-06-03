//
// Created by FatihPC on 12/9/2018.
//

#ifndef DOUBLYLINKEDLIST_DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_DOUBLYLINKEDLIST_H

typedef int ListItemType;

struct ListNode {
    ListItemType nodeItem;
    ListNode *predecessor;
    ListNode *successor;
};

class DoublyLinkedList {

public:
    DoublyLinkedList();
    DoublyLinkedList(DoublyLinkedList &doublyLinkedList);
    ~DoublyLinkedList();

    bool isEmpty() const;
    int getLength() const;
    bool retrieve(int index, ListItemType &dataItem);
    bool insert(int index, ListItemType newItem);
    bool remove(int index);

private:
    int size;
    ListNode *head;
    ListNode *find(int index) const;
};


#endif //DOUBLYLINKEDLIST_DOUBLYLINKEDLIST_H
