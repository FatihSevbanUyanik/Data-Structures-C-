//
// Created by FatihPC on 9/22/2019.
//

#include "SortedArrayADT.h"


SortedArrayADT::SortedArrayADT() {
    maxSize = 100;
    length = 0;
    array = new int[maxSize];
}

void SortedArrayADT::printError(string error) {
    cout << "----------------------------------------" << endl;
    cout << error << endl;
    cout << "----------------------------------------" << endl;
}

void SortedArrayADT::swap(int index1, int index2) {
    int temp = array[index1];
    array[index1] = array[index2];
    array[index2] = temp;
}

void SortedArrayADT::displayArray() {
    cout << "----------------------------------------" << endl;
    cout << "[ ";
    for (int i = 0; i < length; i++) {
        cout << array[i];
        if (i != length - 1) {
            cout << ", ";
        }
    }
    cout << " ]" << endl;
    cout << "----------------------------------------" << endl;
}

void SortedArrayADT::add(int item) {
    if (length >= maxSize) {
        printError("MAXIMUM SIZE IS REACHED ERROR");
        return;
    }

    bool isInserted = false;
        for (int i = 0; i < length; i++) {
            if (item < array[i]) {
                for (int j = length - 1; j >= i; j--) {
                    array[j+1] = array[j];
                }
                array[i] = item;
                isInserted = true;
                break;
            }
        }

    if (!isInserted) {
        array[length] = item;
    }
    length++;
    displayArray();
}

void SortedArrayADT::remove(int index) {
    if (index >= length) {
        printError("REMOVE INDEX NOT FOUND ERROR");
        return;
    }

    length--;
    for (int i = index; i < length; i++) {
        array[i] = array[i+1];
    }
    displayArray();
}

void SortedArrayADT::linearSearch(int value) {
    cout << "----------------------------------------" << endl;
    cout << "[ ";

    for (int i = 0; i < length; i++) {
        if (array[i] == value) {
            cout << i << " ";
        }
    }

    cout << "]" << endl;
    cout << "----------------------------------------" << endl;
}

void SortedArrayADT::get(int index) {
    if (index >= length) {
        printError("GET INDEX NOT FOUND ERROR");
        return;
    }

    cout << "----------------------------------------" << endl;
    cout << "GET(" << index << "): " << array[index]   << endl;
    cout << "----------------------------------------" << endl;
}

void SortedArrayADT::getAverage() {
    int sum = 0;
    for (int i = 0; i < length; ++i) {
        sum += array[i];
    }
    int average = 0;
    if (length > 0) {
        average = sum / length;
    }

    cout << "----------------------------------------" << endl;
    cout << "AVERAGE: " << average << endl;
    cout << "----------------------------------------" << endl;
}

void SortedArrayADT::binarySearchIterative(int value) {
    int start = 0;
    int end = length-1;
    int index = -1;

    while (start <= end) {
        int middle = (start + end) / 2;
        if (array[middle] == value) {
            index = middle;
            break;
        }
        else if (array[middle] > value) {
            end = middle - 1;
        }
        else if (array[middle] < value) {
            start = middle + 1;
        }
    }

    if (index > 0) {
        cout << "----------------------------------------" << endl;
        cout << "BINARY SEARCH INDEX: " << index << endl;
        cout << "----------------------------------------" << endl;
    } else {
        printError("VALUE NOT EXISTS ERROR" );
    }
}

void SortedArrayADT::binarySearchRecursive(int value) {
    int index = binarySearchRecursive(0, length-1, value);
    if (index > 0) {
        cout << "----------------------------------------" << endl;
        cout << "BINARY SEARCH INDEX: " << index << endl;
        cout << "----------------------------------------" << endl;
    } else {
        printError("VALUE NOT EXISTS ERROR" );
    }
}

int SortedArrayADT::binarySearchRecursive(int start, int end, int value) {
    if (start > end) {
        return -1;
    }

    int middle = (start + end) / 2;
    if (array[middle] == value) {
        return middle;
    }
    else if (array[middle] > value) {
        return binarySearchRecursive(start, middle-1, value);
    }
    else {
        return binarySearchRecursive(middle+1, end, value);
    }
}

SortedArrayADT::~SortedArrayADT() {
    delete [] array;
}