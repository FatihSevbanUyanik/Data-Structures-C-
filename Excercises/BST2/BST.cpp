//
// Created by FatihPC on 12/13/2019.
//

#include "BST.h"

BST::BST() {
    root = nullptr;
}

bool BST::isEmpty() const {
    return root == nullptr;
}

void BST::searchTreeInsert(int searchKey, string newItem) {
    insertItem(root, searchKey, newItem);
}

void BST::insertItem(TreeNode *&treePtr, int &searchKey, string &item) {
    if (treePtr == nullptr) {
        treePtr = new TreeNode;
        treePtr->rightPtr = nullptr;
        treePtr->leftPtr = nullptr;
        treePtr->value = item;
        treePtr->key = searchKey;
    } else if (treePtr->key < searchKey) {
        insertItem(treePtr->rightPtr, searchKey, item);
    } else if (treePtr->key >= searchKey) {
        insertItem(treePtr->leftPtr, searchKey, item);
    }
}

void BST::searchTreeDelete(int searchKey) {
    deleteItem(root, searchKey);
}

void BST::deleteItem(TreeNode *&treePtr, int &searchKey) {
    if (treePtr == nullptr) {
        return;
    } else if (treePtr->key == searchKey) {
        deleteNodeItem(treePtr);
    } else if (treePtr->key < searchKey) {
        deleteItem(treePtr->rightPtr, searchKey);
    } else if (treePtr->key > searchKey) {
        deleteItem(treePtr->leftPtr, searchKey);
    }
}

void BST::deleteNodeItem(TreeNode *&nodePtr) {
    if (nodePtr->leftPtr == nullptr && nodePtr->rightPtr == nullptr) {
        delete nodePtr;
        nodePtr = nullptr;
    }
    else if (nodePtr->rightPtr == nullptr) {
        TreeNode *delPtr = nodePtr;
        nodePtr = nodePtr->leftPtr;
        delPtr->leftPtr = nullptr;
        delete delPtr;
    }
    else if (nodePtr->leftPtr == nullptr) {
        TreeNode *delPtr = nodePtr;
        nodePtr = nodePtr->rightPtr;
        delPtr->rightPtr = nullptr;
        delete delPtr;
    }
    else {
        nodePtr->value = processLeftmost(nodePtr->rightPtr);
    }
}

string BST::processLeftmost(TreeNode *&nodePtr) {
    if (nodePtr->leftPtr == nullptr) {
        string itemToBeReplaced = nodePtr->value;
        deleteNodeItem(nodePtr);
        return itemToBeReplaced;
    } else {
        return processLeftmost(nodePtr->leftPtr);
    }
}

void BST::searchTreeRetrieve(int searchKey, string &value) {
    retrieveItem(root, searchKey, value);
}

void BST::retrieveItem(TreeNode *treePtr, int &searchKey, string &item) {
    if (treePtr == nullptr) {
        return;
    } else if (treePtr->key == searchKey) {
        item = treePtr->value;
    } else if (treePtr->key < searchKey) {
        retrieveItem(treePtr->rightPtr, searchKey, item);
    } else if (treePtr->key > searchKey) {
        retrieveItem(treePtr->leftPtr, searchKey, item);
    }
}

void BST::preOrderTraverse() {
    preOrderTraverse(root);
}

void BST::preOrderTraverse(TreeNode *treePtr) {
    if (treePtr == nullptr) return;
    cout << treePtr->key << " --> " << treePtr->value << endl;
    preOrderTraverse(treePtr->leftPtr);
    preOrderTraverse(treePtr->rightPtr);
}

void BST::inOrderTraverse() {
    inOrderTraverse(root);
}

void BST::inOrderTraverse(TreeNode *treePtr) {
    if (treePtr == nullptr) return;
    inOrderTraverse(treePtr->leftPtr);
    cout << treePtr->key << " --> " << treePtr->value << endl;
    inOrderTraverse(treePtr->rightPtr);
}

void BST::postOrderTraverse() {
    postOrderTraverse(root);
}

void BST::postOrderTraverse(TreeNode *treePtr) {
    if (treePtr == nullptr) return;
    postOrderTraverse(treePtr->leftPtr);
    postOrderTraverse(treePtr->rightPtr);
    cout << treePtr->key << " --> " << treePtr->value << endl;
}

BST::~BST() {
    destroyTree(root);
}

void BST::destroyTree(TreeNode *&treePtr) {
    if (treePtr != nullptr) {
        destroyTree(treePtr->leftPtr);
        destroyTree(treePtr->rightPtr);
        delete treePtr;
        treePtr = nullptr;
    }
}
