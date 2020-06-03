#include <iostream>
using namespace std;

#include "DoublyLinkedList.h"

int main() {

    DoublyLinkedList adt1;

    cout << "****************************" << endl;
    cout << "LENGTH: " << adt1.getLength() << endl;
    cout << "IS EMPTY: " << adt1.isEmpty() << endl;
    cout << "****************************" << endl;


    cout << endl;
    cout << endl;

    adt1.insert(1, 100);
    adt1.insert(1, 200);
    adt1.insert(2, 300);
    adt1.insert(2, 400);

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