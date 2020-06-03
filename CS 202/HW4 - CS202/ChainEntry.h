/**
* Title : ChainEntry
* Author :Fatih Sevban Uyanık
* ID: 21602485
* Section : 1
* Assignment : 4
* Description : ChainEntry is a node in the table
*/

#ifndef HW4_CHAINENTRY_H
#define HW4_CHAINENTRY_H

#include <iostream>
using namespace std;


class ChainEntry {
public:
    ChainEntry();
    ChainEntry(int hashKey, int quantity, const string &item);
    int getHashKey() const;
    void setHashKey(int hashKey);
    int getQuantity() const;
    void setQuantity(int quantity);
    const string &getItem() const;
    void setItem(const string &item);
    ChainEntry *next;
    void printEntry();
private:

    int hashKey;
    int quantity;
    string item;
};


#endif //HW4_CHAINENTRY_H
