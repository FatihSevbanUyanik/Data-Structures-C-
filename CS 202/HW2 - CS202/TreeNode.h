/**
* Title : TreeNode.h file
* Author : Fatih Sevban Uyanık
* ID: 21602486
* Section : 1
* Assignment : 2
* Description: Has the prototype of TreeNode
*/

#ifndef HW2_TREENODE_H
#define HW2_TREENODE_H

#include <iostream>
#include "KeyedItem.h"

using namespace std;

class TreeNode {
private:
    TreeNode(string &key);
    ~TreeNode();

    // properties
    KeyedItem *item;
    TreeNode *leftPtr;
    TreeNode *rightPtr;
    friend class NgramTree;
};


#endif //HW2_TREENODE_H
