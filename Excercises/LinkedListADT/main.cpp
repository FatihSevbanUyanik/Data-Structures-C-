#include <iostream>
#include "LinkedList.h"
using namespace std;

int main() {

    LinkedList linkedList;
    linkedList.insert(1, 2);
    linkedList.insert(2, 3);
    linkedList.insert(3, 4);
    linkedList.insert(4, 7);
    linkedList.insert(5, 8);
    linkedList.insert(6, 6);
    linkedList.displayList();
    linkedList.reverseRecursive();
    linkedList.displayList();
    return 0;
}