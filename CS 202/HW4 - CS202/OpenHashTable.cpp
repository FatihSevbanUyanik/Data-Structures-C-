/**
* Title : OpenHashTable
* Author :Fatih Sevban Uyanık
* ID: 21602485
* Section : 1
* Assignment : 4
* Description : OpenHashTable is the table that uses quadratic hashing.
*/
#include "OpenHashTable.h"

OpenHashTable::OpenHashTable(int size) {
    this->size = size;
    entries = new OpenEntry[size];
}

int OpenHashTable::hashInsert(string &item, double &collisions) {
    int hashKey = 0;
    collisions = 0;
    for (int i = 0; i < item.size(); i++) {
        hashKey += (int) item[i];
    }
    int i = 1;
    hashKey = hashKey % size;
    while (entries[hashKey].getStatus() == OCCUPIED) {
        collisions++;
        hashKey = (hashKey + i * i) % size; i++;
    }
    return hashKey;
}

int OpenHashTable::hashRetrieve(string &item, double &comparisons) {
    int hashKey = 0;
    comparisons = 0;
    for (int i = 0; i <  item.size(); i++) {
        hashKey += (int) item[i];
    }

    int i = 1;
    hashKey = hashKey % size;
    while (entries[hashKey].getStatus() != OCCUPIED || entries[hashKey].getItem() != item) {
        comparisons++;
        if (entries[hashKey].getStatus() == EMPTY) { break; }
        hashKey = (hashKey + i * i) % size; i++;
    }
    return hashKey;
}

void OpenHashTable::insertItem(string &item, int quantity, double &collisions) {
    int searchKey = hashInsert(item, collisions);
    entries[searchKey].setHashKey(searchKey);
    entries[searchKey].setStatus(OCCUPIED);
    entries[searchKey].setQuantity(quantity);
    entries[searchKey].setItem(item);
}

OpenEntry OpenHashTable::retrieveItem(string &item, double &comparisons) {
    int searchKey = hashRetrieve(item, comparisons);
    return entries[searchKey];
}

bool OpenHashTable::deleteItem(string &item) {
    double comparisons = 0;
    int searchKey = hashRetrieve(item, comparisons);
    if (entries[searchKey].getStatus() == OCCUPIED) {
        entries[searchKey].setStatus(DELETED);
        entries[searchKey].setQuantity(0);
        entries[searchKey].setItem("");
        entries[searchKey].setHashKey(-1);
        return true;
    }
    return false;
}

void OpenHashTable::printTable() {
    cout << "==============================================================" << endl;
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (entries[i].getStatus() == OCCUPIED) {
            cout << entries[i].getHashKey() << ": " << entries[i].getItem()
            << " = " << entries[i].getQuantity() << "," << endl;
            count++;
        }
    }

    cout << "Total: " << count << endl;
    cout << "==============================================================" << endl;
}

OpenHashTable::~OpenHashTable() {
    delete [] entries;
}

void OpenHashTable::deleteRandom(int count) {
    int counter = 0;
    for (int i = 0; i < size && counter < count; i++) {
        if (entries[i].getStatus() == OCCUPIED) {
            string item = entries[i].getItem();
            bool flag = deleteItem(item);
            if (flag) { counter++; }
        }
    }
}

