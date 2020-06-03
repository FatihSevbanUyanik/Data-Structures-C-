//
// Created by FatihPC on 12/13/2019.
//

#ifndef BST_BST_H
#define BST_BST_H

#include <iostream>
using namespace std;

struct TreeNode {
    TreeNode *leftPtr;
    TreeNode *rightPtr;
    string value;
    int key;
};

class BST {
public:
    BST();
    ~BST();
    bool isEmpty() const;
    void searchTreeRetrieve(int searchKey, string &value);
    void searchTreeInsert(int searchKey, string newItem);
    void searchTreeDelete(int searchKey);
    void preOrderTraverse();
    void inOrderTraverse();
    void postOrderTraverse();

private:
    TreeNode *root;
    void retrieveItem(TreeNode *treePtr, int &searchKey, string& item);
    void insertItem(TreeNode *&treePtr, int &searchKey, string& item);
    void deleteItem(TreeNode * &treePtr, int &searchKey);
    void deleteNodeItem(TreeNode *&nodePtr);
    string processLeftmost(TreeNode * &nodePtr);
    void preOrderTraverse(TreeNode *treePtr);
    void inOrderTraverse(TreeNode *treePtr);
    void postOrderTraverse(TreeNode *treePtr);
    void destroyTree(TreeNode *&treePtr);
};


#endif //BST_BST_H
