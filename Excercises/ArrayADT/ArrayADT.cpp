//
// Created by FatihPC on 9/22/2019.
//

#include "ArrayADT.h"

ArrayADT::ArrayADT() {
    maxSize = 100;
    length = 0;
    array = new int[maxSize];
}

void ArrayADT::printError(string error) {
    cout << "----------------------------------------" << endl;
    cout << error << endl;
    cout << "----------------------------------------" << endl;
}

void ArrayADT::swap(int index1, int index2) {
    int temp = array[index1];
    array[index1] = array[index2];
    array[index2] = temp;
}

void ArrayADT::displayArray() {
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

void ArrayADT::add(int item) {
    if (length >= maxSize) {
        printError("MAXIMUM SIZE IS REACHED");
        return;
    }
    array[length++] = item;
    displayArray();
}

void ArrayADT::insert(int index, int item) {
    if (index >= length) {
        printError("INSERT INDEX NOT FOUND ERROR");
        return;
    }

    for (int i = length; i >= index ; i--) {
        array[i+1] = array[i];
    }

    array[index] =item;
    length++;
    displayArray();
}

void ArrayADT::remove(int index) {
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

void ArrayADT::linearSearch(int value) {
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

void ArrayADT::get(int index) {
    if (index >= length) {
        printError("GET INDEX NOT FOUND ERROR");
        return;
    }

    cout << "----------------------------------------" << endl;
    cout << "GET(" << index << "): " << array[index]   << endl;
    cout << "----------------------------------------" << endl;
}

void ArrayADT::set(int index, int value) {
    if (index >= length) {
        printError("SET INDEX NOT FOUND ERROR");
        return;
    }

    array[index] = value;
    displayArray();
}

void ArrayADT::getAverage() {
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

void ArrayADT::reverseArray() {
    if (length > 0) {
        int start = 0;
        int end = length - 1;

        while (start <= end) {
            swap(start, end);
            start++;
            end--;
        }

        displayArray();
    }
}

void ArrayADT::isSorted() {
    if (length > 1) {
        for (int i = 0; i < length-1; i++) {
            if (array[i] > array[i+1]) {
                cout << "----------------------------------------" << endl;
                cout << "ARRAY NOT SORTED" << endl;
                cout << "----------------------------------------" << endl;
                return;
            }
        }
    }

    cout << "----------------------------------------" << endl;
    cout << "ARRAY SORTED" << endl;
    cout << "----------------------------------------" << endl;
}

ArrayADT::~ArrayADT() {
    delete [] array;
}