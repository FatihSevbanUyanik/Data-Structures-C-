/**
* Title : NgramTree.cpp file
* Author : Fatih Sevban Uyanık
* ID: 21602486
* Section : 1
* Assignment : 2
* Description : Has the internal implementation of NgramTree.
*/

#include "NgramTree.h"

NgramTree::NgramTree() {
    root = NULL;
    grammSize = 0;
}

void NgramTree::addNgram(std::string ngram) {
    if (ngram.length() == grammSize) {
        insertNgram(root, ngram);
    }
}

void NgramTree::insertNgram(TreeNode *&ptr, std::string &ngram) {
    // inserts Ngram to the tree in lexicographic order.
    if (ptr == NULL) {
        ptr = new TreeNode(ngram);
    }
    // node exists, incrementing count.
    else if (compareLexicographicOrder(ptr->item->getSearchKey(), ngram) == 0) {
        int frequency = ptr->item->getFrequency();
        ptr->item->setFrequency(frequency+1);
    }
    // passing to right child pointer.
    else if (compareLexicographicOrder(ptr->item->getSearchKey(), ngram) == -1) {
        insertNgram(ptr->rightPtr, ngram);
    }
    // passing to left child pointer.
    else if (compareLexicographicOrder(ptr->item->getSearchKey(), ngram) == 1) {
        insertNgram(ptr->leftPtr, ngram);
    }
}

int NgramTree::compareLexicographicOrder(string str1, string str2) {
    // compares two strings in lexicographical order.
    int minLength = str1.length() < str2.length() ? str1.length() : str2.length();
    for (int i = 0; i < minLength; ++i) {
        int val1 = int(str1[i]);
        int val2 = int(str2[i]);
        if (val1 > val2) {
            return 1;
        } else if (val1 < val2) {
            return -1;
        }
    }
    return 0;
}

void NgramTree::printNgramFrequencies() {
    string result = "";
    inOrderTraversal(root, result);
    cout << result;
}

void NgramTree::inOrderTraversal(TreeNode *ptr, string &str) {
    // printing n grams lexicographically.
    if (ptr != NULL) {
        inOrderTraversal(ptr->leftPtr, str);
//        std::string str = SSTR( "\"" + ptr->item->getSearchKey() + "\" appears " << ptr->item->getFrequency());
        puts( SSTR( "\"" + ptr->item->getSearchKey() + "\" appears " << ptr->item->getFrequency() << " time(s)").c_str() );
        inOrderTraversal(ptr->rightPtr, str);
    }
}

int NgramTree::getTotalNgramCount() {
    int total = 0;
    preOrderTraversal(root, total);
    return total;
}

void NgramTree::preOrderTraversal(TreeNode *ptr, int &count) {
    if (ptr != NULL) {
        count += 1;
        preOrderTraversal(ptr->leftPtr, count);
        preOrderTraversal(ptr->rightPtr, count);
    }
}

NgramTree::~NgramTree() {
    destroyTree(root);
}

void NgramTree::destroyTree(TreeNode *&ptr) {
    // deleting every pointer in the tree.
    if (ptr != NULL) {
        destroyTree(ptr->leftPtr);
        destroyTree(ptr->rightPtr);
        delete ptr;
        ptr = NULL;
    }
}

bool NgramTree::isComplete() {
    TreeNode *ptr = root;
    if (ptr != NULL) {
        TreeNode **arr = new TreeNode*[99999999];

        int length = 0;
        int index = 0;

        // flag is used for determining the
        // place where one child is missing.
        bool flag = false;
        arr[length++] = ptr;

        // doing a level order traversal.
        while(length - index > 0) {
            ptr = arr[index++];

            // checking left child
            if (ptr->leftPtr != NULL) {
                arr[length++] = ptr->leftPtr;
                if (flag) { return false; }
            }
            else { flag = true; }

            // checking right child.
            if (ptr->rightPtr != NULL) {
                arr[length++] = ptr->rightPtr;
                if (flag) { return false; }
            }
            else { flag = true; }
        }

        for (int i = 0; i < 99999999; i++) {
            delete [] arr[i];
        }

        return true;
    }
    else {
        return false;
    }
}

bool NgramTree::isFull() {
    int count = 0;
    // getting count and height.
    int height = getCountAndHeight(root, count);
    // calculating required count and checking.
    int requiredCount = power(2, height) - 1;
    return requiredCount == count;
}

int NgramTree::getCountAndHeight(TreeNode *&ptr, int &count) {
    if (ptr == NULL) {
        return 0;
    } else {
        // increment count.
        count++;
        // getting maximum height.
        int value1 = getCountAndHeight(ptr->leftPtr, count);
        int value2 = getCountAndHeight(ptr->rightPtr, count);
        return value1 > value2 ? value1 + 1 : value2 + 1;
    }
}

int NgramTree::power(int base, int pow) {
    int result = 1;
    for (int i = 0; i < pow; i++) {
        result *= base;
    }
    return result;
}

void NgramTree::generateTree(std::string fileName, int n) {
    // setting gram size.
    grammSize = n;
    string text;
    string line;
    ifstream inputStream(fileName.c_str());

    // getting text from input text file.
    if (inputStream.is_open()) {
        while ( getline (inputStream, line) ) { text += line + ' '; }
        inputStream.close();
    }

    else { // error while opening file.
        cout << "Unable to open file";
        return;
    }

    // adding each nGram to tree
    string word;
    for (int i = 0; i < text.length(); i++) {
        if (text[i] == ' ') {
            if (word.length() >= n) {
                string str = "";
                for (int k = 0; k <= word.length()-n; k++) {
                    for (int j = k; j < (k+n); j++) { str += tolower(word[j]); }
                    addNgram(str);
                    str = "";
                }
            }
            word = "";
        } else {
            word += text[i];
        }
    }
}