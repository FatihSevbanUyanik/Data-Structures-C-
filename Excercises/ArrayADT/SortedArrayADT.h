//
// Created by FatihPC on 9/22/2019.
//

#ifndef ARRAYADT_SORTEDARRAYADT_H
#define ARRAYADT_SORTEDARRAYADT_H

#include <iostream>
using namespace std;

class SortedArrayADT {
public:
    SortedArrayADT();
    void add(int item);
    void remove(int index);
    void displayArray();
    void linearSearch(int value);
    void binarySearchIterative(int value);
    void binarySearchRecursive(int value);
    void get(int index);
    void getAverage();
    ~SortedArrayADT();

private:
    int maxSize;
    int length;
    int *array;
    int binarySearchRecursive(int start, int end, int value);
    void printError(string error);
    void swap(int index1, int index2);
};


#endif //ARRAYADT_SORTEDARRAYADT_H
