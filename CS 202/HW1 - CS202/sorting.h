/**
* Title : Sorting Object
* Author : Fatih Sevban Uyanık
* ID: 21602486
* Section : 1
* Assignment : 1
* Description : Contains all sorting methods.
*/

#ifndef HW1_SORTING_H
#define HW1_SORTING_H

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

class sorting {
public:
    void quickSort(int *arr, int f ,int l, int &compCount, int &moveCount);
    void insertionSort(int *arr, int size, int &compCount, int &moveCount);
    void hybridSort(int *arr, int size, int &compCount, int &moveCount);
    void printArray(int *arr, int size);
    void performanceAnalysis();

private:
    int partition(int *arr, int f ,int l, int &compCount, int &moveCount);
    void hybridSort(int *arr, int f ,int l, int &compCount, int &moveCount);
};


#endif //HW1_SORTING_H
