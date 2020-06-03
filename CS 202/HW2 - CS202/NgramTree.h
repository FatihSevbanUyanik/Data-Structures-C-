/**
* Title : NgramTree.h file
* Author : Fatih Sevban Uyanık
* ID: 21602486
* Section : 1
* Assignment : 2
* Description : Has the prototypes of internal implementation of NgramTree.
*/

#ifndef HW2_NGRAMTREE_H
#define HW2_NGRAMTREE_H

#include <fstream>
#include <iostream>
#include "TreeNode.h"
using namespace std;
#include <sstream>

#define SSTR( x ) static_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()

class NgramTree {
public:
    NgramTree();
    ~ NgramTree();
    void addNgram(std::string ngram );
    int getTotalNgramCount();
    void printNgramFrequencies();
    bool isComplete();
    bool isFull();
    void generateTree(std :: string fileName , int n );

private:
    // private properties
    TreeNode *root;
    int grammSize;

    // private methods
    int compareLexicographicOrder(string str1, string str2);
    void insertNgram(TreeNode *&ptr, std::string &ngram);
    void inOrderTraversal(TreeNode *ptr, string &str);
    void preOrderTraversal(TreeNode *ptr, int &count);
    int getCountAndHeight(TreeNode *&ptr, int &count);
    void destroyTree(TreeNode *&ptr);
    int power(int base, int pow);
};


#endif //HW2_NGRAMTREE_H
