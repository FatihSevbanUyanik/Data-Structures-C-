/**
* Title : Main Program
* Author : Fatih Sevban Uyanık
* ID: 21602486
* Section : 1
* Assignment : 2
* Description : Tests the NgramTree
*/

#include <iostream>
#include "NgramTree.h"

using namespace std;

int main () {
    NgramTree tree ;
    int n = 4;
    tree.generateTree("input.txt", n);
    cout << "\nTotal " << n << "-gram count : " << tree.getTotalNgramCount() << endl ;
    tree . printNgramFrequencies ();
    cout << n << "-gram tree is complete : " << ( tree.isComplete() ? "Yes": "No") << endl ;
    cout << n << "-gram tree is full : " << ( tree . isFull () ? "Yes " : "No") << endl ;
    // Before insertion of new n- grams

    tree.addNgram("samp");
    tree.addNgram("samp");
    tree.addNgram("zinc");
    tree.addNgram("aatt");
    cout << "\nTotal " << n << "-gram count : " << tree.getTotalNgramCount() << endl ;
    tree . printNgramFrequencies ();
    cout << n << "-gram tree is complete : " << ( tree . isComplete () ? "Yes" : "No") << endl ;
    cout << n << "-gram tree is full : " << ( tree . isFull () ? "Yes " : "No") << endl ;
    return 0;
}