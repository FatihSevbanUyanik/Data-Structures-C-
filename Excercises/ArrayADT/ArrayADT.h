//
// Created by FatihPC on 9/22/2019.
//

#ifndef ARRAYADT_ARRAYADT_H
#define ARRAYADT_ARRAYADT_H

#include <iostream>
using namespace std;

class ArrayADT {

public:
    ArrayADT();
    void add(int item);
    void insert(int index, int item);
    void remove(int index);
    void displayArray();
    void linearSearch(int value);
    void get(int index);
    void set(int index, int value);
    void reverseArray();
    void getAverage();
    void isSorted();
    ~ArrayADT();

private:
    int maxSize;
    int length;
    int *array;

    void printError(string error);
    void swap(int index1, int index2);
};


#endif //ARRAYADT_ARRAYADT_H
