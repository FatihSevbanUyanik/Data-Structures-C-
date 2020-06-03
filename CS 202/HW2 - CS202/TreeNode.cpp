/**
* Title : TreeNode.cpp file
* Author : Fatih Sevban Uyanık
* ID: 21602486
* Section : 1
* Assignment : 2
* Description: Has the implementation of TreeNode
*/

#include "TreeNode.h"

TreeNode::TreeNode(string &key) {
    item = new KeyedItem(key);
    this->leftPtr = NULL;
    this->rightPtr = NULL;
}

TreeNode::~TreeNode() {
    delete item;
}
