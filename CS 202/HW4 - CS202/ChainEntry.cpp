/**
* Title : ChainEntry
* Author :Fatih Sevban Uyanık
* ID: 21602485
* Section : 1
* Assignment : 4
* Description : ChainEntry is a node in the table
*/

#include "ChainEntry.h"

ChainEntry::ChainEntry(int hashKey, int quantity, const string &item) {
    this->hashKey = hashKey;
    this->quantity = quantity;
    this->item = item;
    this->next = NULL;
}

ChainEntry::ChainEntry() {
    this->hashKey = -1;
    this->quantity = 0;
    this->item = "";
    this->next = NULL;
}

int ChainEntry::getHashKey() const {
    return hashKey;
}

void ChainEntry::setHashKey(int hashKey) {
    ChainEntry::hashKey = hashKey;
}

int ChainEntry::getQuantity() const {
    return quantity;
}

void ChainEntry::setQuantity(int quantity) {
    ChainEntry::quantity = quantity;
}

const string &ChainEntry::getItem() const {
    return item;
}

void ChainEntry::setItem(const string &item) {
    ChainEntry::item = item;
}

void ChainEntry::printEntry() {
    cout << "=========================" << endl;
    cout << "Hash Key: " << this->hashKey << endl;
    cout << "Quantity: " << this->quantity << endl;
    cout << "Item    : " << this->item << endl;
    cout << "=========================" << endl;
}