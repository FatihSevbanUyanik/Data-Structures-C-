#include <iostream>
#include <algorithm>
#include "LinkedList.h"

using namespace std;

bool isPalindrome(char *str, int strLength) {

    if (strLength <= 1)
        return true;

    else {
        if (str[0] == str[strLength - 1])
            return isPalindrome(++str, strLength - 2);

        else return false;
    }
}

void writeBackwards(char *str) {
    if (str[0] != '\0') {
        writeBackwards(str + 1);
        cout << str[0] << " ";
    }
}

int recursiveFib(int n) {
    if (n == 1)
        return 0;

    else if (n == 2)
        return 1;

    else return recursiveFib(n - 1) + recursiveFib(n - 2);
}

int iterativeFib(int n) {

    if (n == 1)
        return 0;

    else if(n == 2)
        return 1;

    int firstTerm = 0;
    int secondTerm = 1;
    int curTerm = 0;

    for (int i = 0; i < (n-2) ; i++) {
        curTerm = firstTerm + secondTerm;
        firstTerm = secondTerm;
        secondTerm = curTerm;
    }

    return curTerm;
}

int recursiveBinarySearch(int *array, int start, int end, int key) {
    if (start > end)
        return -1;

    int mid = (start + end) / 2;

    if (array[mid] == key)
        return mid;

    if (array[mid] > key)
        return recursiveBinarySearch(array, start, mid - 1, key);

    else if (array[mid] < key)
        return recursiveBinarySearch(array, mid + 1, end, key);
}

int iterativeBinarySearch(const int *array, int start, int end, int key) {

    while (start <= end) {
        int mid = (start + end) / 2;

        if (array[mid] == key)
            return mid;

        else if (array[mid] > key)
            end = mid - 1;

        else if (array[mid] < key)
            start = mid + 1;
    }

    return -1;
}

int recursivePower(int base, int power) {

    if (power == 0)
        return  1;

    else if (power == 1)
        return base;

    else if (power > 1) {

        if (power % 2 == 1)
            return recursivePower(base * base, power / 2) * base;

        else return recursivePower(base * base, power / 2);
    }
}


int main() {

    LinkedList adt1;

    cout << "****************************" << endl;
    cout << "LENGTH: " << adt1.getLength() << endl;
    cout << "IS EMPTY: " << adt1.isEmpty() << endl;
    cout << "****************************" << endl;

    cout << endl;
    cout << endl;

    adt1.insert(1, 100);
    adt1.insert(2, 200);
    adt1.insert(1, 300);
    adt1.insert(4, 400);

    cout << "****************************" << endl;
    cout << "LENGTH: " << adt1.getLength() << endl;
    cout << "IS EMPTY: " << adt1.isEmpty() << endl;

    cout << "CONTENT" << endl;

    for (int i = 1; i <= adt1.getLength() ; i++) {
        int temp;
        adt1.retrieve(i, temp);
        cout << temp <<endl;
    }
    cout << "****************************" << endl;

    cout << endl;
    cout << endl;

    adt1.remove(3);
    adt1.remove(1);

    cout << "****************************" << endl;
    cout << "LENGTH: " << adt1.getLength() << endl;
    cout << "IS EMPTY: " << adt1.isEmpty() << endl;

    cout << "CONTENT" << endl;

    for (int i = 1; i <= adt1.getLength() ; i++) {
        int temp;
        adt1.retrieve(i, temp);
        cout << temp <<endl;
    }
    cout << "****************************" << endl;

    adt1.remove(2);
    adt1.remove(1);

    cout << endl;
    cout << endl;

    cout << "****************************" << endl;
    cout << "LENGTH: " << adt1.getLength() << endl;
    cout << "IS EMPTY: " << adt1.isEmpty() << endl;

    cout << "CONTENT" << endl;

    for (int i = 1; i <= adt1.getLength() ; i++) {
        int temp;
        adt1.retrieve(i, temp);
        cout << temp <<endl;
    }
    cout << "****************************" << endl;
    return 0;
}