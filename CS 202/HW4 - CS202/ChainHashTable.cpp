/**
* Title : ChainHashTable
* Author :Fatih Sevban Uyanık
* ID: 21602485
* Section : 1
* Assignment : 4
* Description : Hash table that uses chaining.
*/

#include "ChainHashTable.h"

ChainHashTable::ChainHashTable(int size) {
    this->size = size;
    entries = new ChainEntry*[size];
    for (int i = 0; i < size; i++) { entries[i] = NULL; }
}

int ChainHashTable::hash(string &item) {
    int hashKey = 0;
    for (int i = 0; i <  item.size(); i++) {
        hashKey += (int) item[i];
    }
    hashKey = hashKey % size;
    return hashKey;
}


void ChainHashTable::insertItem(string &item, int quantity) {
    int hashKey = hash(item);
    ChainEntry *newPtr = new ChainEntry;
    newPtr->setQuantity(quantity);
    newPtr->setHashKey(hashKey);
    newPtr->setItem(item);
    newPtr->next = entries[hashKey];
    entries[hashKey] = newPtr;
}

void ChainHashTable::deleteItem(string &item) {
    int hashKey = hash(item);
    ChainEntry *currentPtr = entries[hashKey];
    ChainEntry *previousPtr = NULL;

    while (currentPtr != NULL) {
        if (currentPtr->getItem() == item) { break; }
        previousPtr = currentPtr;
        currentPtr = currentPtr->next;
    }

    if (currentPtr == NULL) {
        return;
    } else {
        if (previousPtr != NULL) {
            ChainEntry *nextPtr = currentPtr->next;
            previousPtr->next = nextPtr;
            currentPtr->next = NULL;
            delete currentPtr;
        } else {
            ChainEntry *delPtr =  entries[hashKey];
            entries[hashKey] = entries[hashKey]->next;
            delPtr->next = NULL;
            delete delPtr;
        }
    }
}

ChainEntry ChainHashTable::retrieveItem(string &item, double &comparisons) {
    comparisons = 0;
    int hashKey = hash(item);
    ChainEntry *ptr = entries[hashKey];
    while (ptr != NULL) {
        comparisons++;
        if (ptr->getItem() == item) { break; }
        ptr = ptr->next;
    }
    return *ptr;
}

void ChainHashTable::printTable() {
    cout << "===================================================================================================================" << endl;
    for (int i = 0; i < size; i++) {
        ChainEntry *ptr = entries[i];
        if (ptr != NULL) {
            cout << ptr->getHashKey() << ": ";
            while (ptr != NULL) {
                cout << ptr->getItem() << " = " << ptr->getQuantity() << ", ";
                ptr = ptr->next;
            }
            cout << endl;
        }
    }
    cout << "===================================================================================================================" << endl;
}

ChainHashTable::~ChainHashTable() {
    for (int i = 0; i < size; ++i) {
        ChainEntry *ptr = entries[i];
        while (ptr != NULL) {
            ChainEntry *delPtr = ptr;
            ptr = ptr->next;
            delete delPtr;
        }
    }
    delete [] entries;
}

void ChainHashTable::deleteRandom(int count) {
    int counter = 0;
    for (int i = 0; i < size && counter < count; i++) {
        ChainEntry *ptr = entries[i];
        while (ptr != NULL) {
            string item = ptr->getItem();
            ptr = ptr->next;
            deleteItem(item);
            counter++;
        }
    }
}

