#include <iostream>
#include "ArrayADT.h"
#include "SortedArrayADT.h"

void displayArray(int *pointer, int length) {
    cout << "----------------------------------------" << endl;
    cout << "[ ";
    for (int i = 0; i < length; i++) {
        cout << pointer[i];
        if (i != length - 1) {
            cout << ", ";
        }
    }
    cout << " ]" << endl;
    cout << "----------------------------------------" << endl;
}

void mergeArraysSorted(int mergeSize1, const int *merge1,
                       int mergeSize2, const int *merge2) {

    int index1 = 0;
    int index2 = 0;
    int resultSize = 0;
    int *result;

    while (index1 < mergeSize1 && index2 < mergeSize2) {
        if (merge1[index1] == merge2[index2]) {
            resultSize++;
            index1++;
            index2++;
        }
        else if (merge1[index1] > merge2[index2]) {
            index2++;
            resultSize++;
        }
        else {
            index1++;
            resultSize++;
        }
    }

    while (index1 < mergeSize1) {
        resultSize++;
        index1++;
    }

    while (index2 < mergeSize2) {
        resultSize++;
        index2++;
    }

    result = new int[resultSize];
    int resultIndex = 0;
    index1 = 0;
    index2 = 0;

    while (index1 < mergeSize1 && index2 < mergeSize2) {
        if (merge1[index1] == merge2[index2]) {
            result[resultIndex++] = merge1[index1];
            index1++;
            index2++;
        }
        else if (merge1[index1] > merge2[index2]) {
            result[resultIndex++] = merge2[index2++];
        }
        else {
            result[resultIndex++] = merge1[index1++];
        }
    }

    while (index1 < mergeSize1) {
        result[resultIndex++] = merge1[index1++];
    }

    while (index2 < mergeSize2) {
        result[resultIndex++] = merge2[index2++];
    }

    displayArray(result, resultSize);
    delete [] result;
}

void intersectArraysSorted(int size1, const int *array1,
                           int size2, const int *array2) {

    int index1 = 0;
    int index2 = 0;
    int resultSize = 0;
    int *result;

    while (index1 < size1 && index2 < size2) {
        if (array1[index1] == array2[index2]) {
            resultSize++;
            index1++;
            index2++;
        }
        else if (array1[index1] > array2[index2]) {
            index2++;
        }
        else {
            index1++;
        }
    }

    result = new int[resultSize];
    int resultIndex = 0;
    index1 = 0;
    index2 = 0;

    while (index1 < size1 && index2 < size2) {
        if (array1[index1] == array2[index2]) {
            result[resultIndex++] = array1[index1];
            index1++;
            index2++;
        }
        else if (array1[index1] > array2[index2]) {
            index2++;
        }
        else {
            index1++;
        }
    }

    displayArray(result, resultSize);
    delete [] result;
}

void takeDifferenceArraysSorted(int size1, const int *array1,
                                int size2, const int *array2) {

    int index1 = 0;
    int index2 = 0;
    int resultSize = 0;
    int *result;

    while (index1 < size1 && index2 < size2) {
        if (array1[index1] == array2[index2]) {
            index1++;
            index2++;
        }
        else if (array1[index1] > array2[index2]) {
            index2++;
        }
        else {
            resultSize++;
            index1++;
        }
    }

    result = new int[resultSize];
    int resultIndex = 0;
    index1 = 0;
    index2 = 0;

    while (index1 < size1 && index2 < size2) {
        if (array1[index1] == array2[index2]) {
            index1++;
            index2++;
        }
        else if (array1[index1] > array2[index2]) {
            index2++;
        }
        else {
            result[resultIndex++] = array1[index1++];
        }
    }

    displayArray(result, resultSize);
    delete [] result;
}

void findMissingElementsInSortedArray(int *array, int size) {
    cout << "----------------------------------------" << endl;
    cout << "[ ";
    for (int i = 0; i < size; i++) {
        int difference = array[i+1] - array[i];
        if (difference > 1) {
            for (int j = 1; j < difference; j++) {
                cout << array[i] + j << " ";
            }
        }
    }
    cout << "]" << endl;
    cout << "----------------------------------------" << endl;
}

void findMissingElementsInUnsortedArray(int *array, int size) {
    int max = array[0];

    for (int i = 1; i < size; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }

    int tempSize = max+1;
    int *temp = new int[tempSize];

    for (int i = 0; i < tempSize; i++) {
        temp[i] = 0;
    }

    for (int i = 0; i < size; i++) {
        temp[array[i]] = 1;
    }

    cout << "----------------------------------------" << endl;
    cout << "[ ";
    for (int i = 1; i < tempSize; i++) {
        if (temp[i] == 0) {
            cout << i << " ";
        }
    }

    cout << "]" << endl;
    cout << "----------------------------------------" << endl;
    delete [] temp;
}

void findDuplicateElementsInArray(int *array, int size) {
    cout << "----------------------------------------" << endl;
    cout << "[ ";

    int duplicate = -1;
    int count = 0;
    for (int i = 1; i < size; i++) {
        if (array[i-1] == array[i] && array[i] != duplicate) {
            duplicate = array[i];
            count = 2;
        }

        else if (array[i-1] == array[i] && array[i] == duplicate) {
            count++;
        }

        else if (count > 0) {
            cout << duplicate << ":" << count << " ";
            count = 0;
        }
    }

    cout << "]" << endl;
    cout << "----------------------------------------" << endl;
}

void findPairsWithSumK(int *array, int size, int k, int index) {
    int temp = array[index++];

    for (int i = index; i < size; i++) {
        if (array[i] + temp == 10) {
            cout << temp << "+" << array[i] << " ";
        }
    }

    if (index < size) {
        findPairsWithSumK(array, size, k, index);
    }
}


void findPairsWithSumK(int *array, int size, int k) {
    cout << "----------------------------------------" << endl;
    cout << "[ ";
    findPairsWithSumK(array, size, k, 0);
    cout << "]" << endl;
    cout << "----------------------------------------" << endl;
}

void findPairsWithSumKHashing(int *array, int size, int k) {
    int max = array[0];

    for (int i = 1; i < size; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }

    int tempSize = max+1;
    int *temp = new int[tempSize];

    for (int j = 0; j < size; ++j) {
        temp[array[j]]++;
    }

    cout << "----------------------------------------" << endl;
    cout << "[ ";

    if (tempSize > k) {
        tempSize = k;
    }

    for (int i = 0; i < tempSize; i++) {
        if ((i != k-i) && temp[i] > 0 && temp[k-i] > 0) {
            cout << i << "+" << k-i << endl;
            temp[k-i] = 0;
        }
        else if ((i == k-i) && temp[i] > 1) {
            cout << i << "+" << k-i << endl;
        }
    }

    cout << "]" << endl;
    cout << "----------------------------------------" << endl;
    delete [] temp;
}

int main() {

    ArrayADT arrayADT;
    arrayADT.add(100);
    arrayADT.add(200);
    arrayADT.add(300);
    arrayADT.isSorted();
    arrayADT.add(400);
    arrayADT.add(500);
    arrayADT.add(600);
    arrayADT.add(600);
    arrayADT.add(700);
    arrayADT.linearSearch(600);
    arrayADT.insert(3, 800);
    arrayADT.remove(3);
    arrayADT.reverseArray();
    arrayADT.getAverage();
    arrayADT.get(2);
    arrayADT.set(3, 20);
    arrayADT.isSorted();

    cout << endl;
    cout << endl;

    SortedArrayADT sortedArrayADT;
    sortedArrayADT.add(100);
    sortedArrayADT.add(300);
    sortedArrayADT.add(400);
    sortedArrayADT.add(500);
    sortedArrayADT.add(200);
    sortedArrayADT.add(600);
    sortedArrayADT.linearSearch(300);
    sortedArrayADT.binarySearchIterative(600);
    sortedArrayADT.binarySearchRecursive(500);
    sortedArrayADT.remove(0);
    sortedArrayADT.getAverage();
    sortedArrayADT.get(2);

    cout << endl;
    cout << endl;

    int size1 = 6;
    int array1[] = {2, 5, 8, 12, 13, 14};
    int size2 = 5;
    int array2[] = {3, 4, 12, 13, 15};
    mergeArraysSorted(size1, array1, size2, array2);
    intersectArraysSorted(size1, array1, size2, array2);
    takeDifferenceArraysSorted(size1, array1, size2, array2);

    cout << endl;
    cout << endl;

    int array3[] = {6, 7, 8, 9, 11, 12, 15, 16, 17, 18, 19};
    int size3 = 11;
    findMissingElementsInSortedArray(array3, size3);

    cout << endl;
    cout << endl;

    int array4[] = {3, 7, 4, 9, 12, 6, 1, 11, 2, 10};
    int size4 = 10;
    findMissingElementsInUnsortedArray(array4, size4);

    int array5[] = {3, 6, 8, 8, 10, 12, 15, 15, 15, 20};
    int size5 = 10;
    findDuplicateElementsInArray(array5, size5);


    int array6[] = {6, 3, 8, 10, 16, 7, 5, 5, 2, 9, 14};
    int size6 = 11;
    findPairsWithSumK(array6, size6, 10);


    return 0;
}