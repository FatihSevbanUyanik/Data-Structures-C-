/**
* Title : OpenHashTable
* Author :Fatih Sevban Uyanık
* ID: 21602485
* Section : 1
* Assignment : 4
* Description : OpenHashTable is the table that uses quadratic hashing.
*/

#ifndef HW4_OPENHASHTABLE_H
#define HW4_OPENHASHTABLE_H

#include <iostream>
#include "OpenEntry.h"
using namespace std;


class OpenHashTable {
public:
    OpenHashTable(int size);
    void insertItem(string &item, int quantity, double &collisions);
    bool deleteItem(string &item);
    OpenEntry retrieveItem(string &item, double &comparisons);
    void printTable();
    ~OpenHashTable();

    void deleteRandom(int count);

private:
    const int EMPTY = 0;
    const int OCCUPIED = 1;
    const int DELETED = 2;
    OpenEntry *entries;
    int size;
    int hashInsert(string &item, double &collisions);
    int hashRetrieve(string &item, double &comparisons);
};


#endif //HW4_OPENHASHTABLE_H
