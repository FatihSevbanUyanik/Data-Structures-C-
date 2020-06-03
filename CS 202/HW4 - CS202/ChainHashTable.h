/**
* Title : ChainHashTable
* Author :Fatih Sevban Uyanık
* ID: 21602485
* Section : 1
* Assignment : 4
* Description : Hash table that uses chaining.
*/

#ifndef HW4_CHAINHASHTABLE_H
#define HW4_CHAINHASHTABLE_H

#include <iostream>
#include "ChainEntry.h"
using namespace std;


class ChainHashTable {
public:
    ChainHashTable(int size);
    void insertItem(string &item, int quantity);
    void deleteItem(string &item);
    ChainEntry retrieveItem(string &item, double &comparisons);
    void printTable();
    ~ChainHashTable();
    void deleteRandom(int i);
private:
    ChainEntry **entries;
    int size;
    int hash(string &item);
};


#endif //HW4_CHAINHASHTABLE_H
