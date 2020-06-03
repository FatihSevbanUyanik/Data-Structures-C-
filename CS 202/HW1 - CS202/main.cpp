/**
* Title : Main Program
* Author : Fatih Sevban Uyanık
* ID: 21602486
* Section : 1
* Assignment : 1
* Description : sorts sample arrays and analyses performance.
*/

#include <iostream>
#include "sorting.h"
using namespace std;

int main() {

    sorting sorting1;

    cout << endl;
    cout << endl;

    cout << "QUICK SORT" << endl;
    int arraySize1 = 12;
    int compCount1 = 0;
    int moveCount1 = 0;
    int arr1[] = {22, 11, 6, 7, 30, 2, 27, 24, 9, 1, 20, 17};
    sorting1.printArray(arr1, arraySize1);
    sorting1.quickSort(arr1, 0, arraySize1-1, compCount1, moveCount1);
    sorting1.printArray(arr1, arraySize1);
    cout << "--------------------------------------------------------" << endl;
    cout << "Move Count: " << moveCount1 << endl;
    cout << "Comparison Count: " << compCount1 << endl;
    cout << "--------------------------------------------------------" << endl;

    cout << endl;
    cout << endl;

    cout << "INSERTION SORT" << endl;
    int arraySize2 = 12;
    int compCount2 = 0;
    int moveCount2 = 0;
    int arr2[] = {22, 11, 6, 7, 30, 2, 27, 24, 9, 1, 20, 17};
    sorting1.printArray(arr2, arraySize2);
    sorting1.insertionSort(arr2, arraySize2, compCount2, moveCount2);
    sorting1.printArray(arr2, arraySize2);
    cout << "--------------------------------------------------------" << endl;
    cout << "Move Count: " << moveCount2 << endl;
    cout << "Comparison Count: " << compCount2 << endl;
    cout << "--------------------------------------------------------" << endl;

    cout << endl;
    cout << endl;

    cout << "HYBRID SORT" << endl;
    int arraySize3 = 12;
    int compCount3 = 0;
    int moveCount3 = 0;
    int arr3[] = {22, 11, 6, 7, 30, 2, 27, 24, 9, 1, 20, 17};
    sorting1.printArray(arr3, arraySize3);
    sorting1.hybridSort(arr3, arraySize3, compCount3, moveCount3);
    sorting1.printArray(arr3, arraySize3);
    cout << "--------------------------------------------------------" << endl;
    cout << "Move Count: " << moveCount3 << endl;
    cout << "Comparison Count: " << compCount3 << endl;
    cout << "--------------------------------------------------------" << endl;

    cout << endl;
    cout << endl;

    sorting1.performanceAnalysis();
    return 0;
}