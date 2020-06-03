//
// Created by FatihPC on 12/13/2018.
//

#ifndef RECURSION_ARRAYLIST_H
#define RECURSION_ARRAYLIST_H

typedef int ListItemType;

class ArrayList {

public:
    ArrayList();
    ArrayList(ArrayList &arrayList);
    ~ArrayList();

    bool isEmpty() const;
    int getLength() const;
    bool retrieve(int index, ListItemType &dataItem) const;
    bool insert(int index, ListItemType newItem);
    bool remove(int index);

private:
    int translate(int index) const;
    int MAX_SIZE = 100;
    int size;
    ListItemType *array;
};


#endif //RECURSION_ARRAYLIST_H
