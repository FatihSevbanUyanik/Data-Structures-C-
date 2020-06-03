#include <iostream>
#include "AVL.h"
#include "Heap.h"
using namespace std;

int main() {
    AVL bst;
    bst.searchTreeInsert(20);
    bst.searchTreeInsert(40);
    bst.searchTreeInsert(30);
    bst.searchTreeInsert(10);
    bst.searchTreeInsert(5);
    bst.searchTreeInsert(50);
    cout << "-----------------" << endl;
    bst.preOrderTraverse();
    cout << "-----------------" << endl;
    bst.inOrderTraverse();
    cout << "-----------------" << endl;
    bst.postOrderTraverse();
    cout << "-----------------" << endl;
//    string retrievedItem;
//    bst.searchTreeRetrieve(5, retrievedItem);
//    cout << "5 --> " << retrievedItem << endl;
//    cout << "-----------------" << endl;
//    bst.searchTreeDelete(5);
//    bst.preOrderTraverse();
//    cout << "-----------------" << endl;
//    bst.inOrderTraverse();
//    cout << "-----------------" << endl;
//    bst.postOrderTraverse();
//    cout << "-----------------" << endl;
//
//    Heap heap(50);
//    heap.heapInsert(100);
//    heap.heapInsert(200);
//    heap.heapInsert(150);
//    heap.heapInsert(220);
//    heap.heapInsert(50);
//    int num;
//    heap.heapDelete(num);
//    heap.heapDelete(num);
//    heap.print();
    return 0;
}