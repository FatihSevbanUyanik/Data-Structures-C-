//
// Created by FatihPC on 12/13/2018.
//

#include "ArrayList.h"
#include <iostream>
using namespace std;

ArrayList::ArrayList() {
    array = new ListItemType[MAX_SIZE];
    size = 0;
}

ArrayList::ArrayList(ArrayList &arrayList) {

    array = new ListItemType[MAX_SIZE];
    size = arrayList.size;

    for (int i = 0; i < size; i++)
        array[i] = arrayList.array[i];
}

ArrayList::~ArrayList() {
    delete [] array;
    cout << "Items deleted" << endl;
}

bool ArrayList::isEmpty() const {
    return size == 0;
}

int ArrayList::getLength() const {
    return size;
}

int ArrayList::translate(int index) const {
    return index - 1;
}

bool ArrayList::remove(int index) {

    bool success = index <= size && index >= 1;

    if (success) {
        for (int i = index; i < size; i++)
            array[translate(i)] = array[translate(i+1)];

        size--;
    }

    return success;
}

bool ArrayList::retrieve(int index, ListItemType &dataItem) const {

    bool success =  index <= size && index >= 1;

    if (success)
        dataItem = array[translate(index)];

    return success;
}

bool ArrayList::insert(int index, ListItemType newItem) {

    bool success = index <= size + 1 && index >= 1;

    if (success) {
        for (int i = size; i >= index; i--)
            array[translate(i+1)] = array[translate(i)];

        array[translate(index)] = newItem;
        size++;
    }

    return success;
}
