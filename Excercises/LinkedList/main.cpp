#include <iostream>
using namespace std;

#include "LinkedListADT.h"

/*void printStringReverse(string str) {
    if (str != "") {
        cout << str.back() << " " ;
        str.pop_back();
        printStringReverse(str);
    }
}*/

void printStringReverse(char str[]) {
    if(str[0] != '\0') {
        printStringReverse(str + 1);
        cout << str[0] << endl;
    }
}

int fibonacci(int n) {

    if (n == 1)
        return 0;

    if (n == 2)
        return 1;

    else
        return fibonacci(n-1) + fibonacci(n-2);

}

int fibonacciIterative(int n) {

    int firstTerm = 0;
    int secondTerm = 1;
    int result = 0;

    for (int i = 2; i < n ; i++) {
        result = firstTerm + secondTerm;
        firstTerm = secondTerm;
        secondTerm = result;
    }

    return result;
}

/*int binarySearch(int *arrPtr, int start, int end, int key) {

    if (start > end)
        return -1;

    else {

        int mid = (start + end) / 2;

        if (arrPtr[mid] == key)
            return mid;

        else if (arrPtr[mid] > key)
            return binarySearch(arrPtr, start, --mid, key);

        else
            return binarySearch(arrPtr, mid + 1, end, key);
    }

}

int binarySearch(int *arrPtr, int size, int key) {
    return binarySearch(arrPtr, 0, --size, key);
}
*/

int binarySearch(int *arrPtr, int size, int key) {

    int start = 0;
    int end = size - 1;

    while (start < end) {

        int mid = (start + end) / 2;

        if (arrPtr[mid] == key)
            return mid;

        else if (arrPtr[mid] > key)
            end = mid - 1;

        else
            start = mid + 1;
    }

    return -1;
}

int takePower(int num, int pow) {

    if (pow == 0)
        return 0;

    else if (pow == 1)
        return num;

    else {
        if (pow % 2 == 1)
            return takePower(num * num,  ((pow-1) / 2)) * num;
        else
            return takePower(num * num, pow/2);
    }
 }

 int main() {

    int arr[] = {10, 20, 30, 40, 60, 70, 90, 100};
    int arrSize = 7;

    int num = binarySearch(arr, arrSize, 90);
    cout << takePower(2,9) << endl;

    /*LinkedListADT adt1;

    cout << "****************************" << endl;
    cout << "LENGTH: " << adt1.getLength() << endl;
    cout << "IS EMPTY: " << adt1.isEmpty() << endl;
    cout << "****************************" << endl;


    cout << endl;
    cout << endl;

    adt1.insert(1, 100);
    adt1.insert(2, 200);
    adt1.insert(3, 300);
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

    cout << "****************************" << endl;
    cout << "LENGTH: " << adt1.getLength() << endl;
    cout << "IS EMPTY: " << adt1.isEmpty() << endl;

    cout << "CONTENT" << endl;
    adt1.displayReverseOrder();

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
    cout << "****************************" << endl;*/

    return 0;
}