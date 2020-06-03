/**
* Title : OpenEntry
* Author :Fatih Sevban Uyanık
* ID: 21602485
* Section : 1
* Assignment : 4
* Description : OpenEntry is an item in the table
*/

#include "OpenEntry.h"

OpenEntry::OpenEntry() {
    this->item = "";
    this->hashKey = -1;
    this->quantity = 0;
    this->status = 0;
}

OpenEntry::OpenEntry(int hashKey, int status, int quantity, const string &item) {
    this->hashKey = hashKey;
    this->status = status;
    this->quantity = quantity;
    this->item = item;
}

int OpenEntry::getHashKey() const {
    return hashKey;
}

void OpenEntry::setHashKey(int hashKey) {
    OpenEntry::hashKey = hashKey;
}

int OpenEntry::getStatus() const {
    return status;
}

void OpenEntry::setStatus(int status) {
    OpenEntry::status = status;
}

int OpenEntry::getQuantity() const {
    return quantity;
}

void OpenEntry::setQuantity(int quantity) {
    OpenEntry::quantity = quantity;
}

const string &OpenEntry::getItem() const {
    return item;
}

void OpenEntry::setItem(const string &item) {
    OpenEntry::item = item;
}

void OpenEntry::printEntry() {
    cout << "=========================" << endl;
    cout << "Hash Key: " << this->hashKey << endl;
    cout << "Quantity: " << this->quantity << endl;
    cout << "Item    : " << this->item << endl;
    cout << "Status  : " << this->status << endl;
    cout << "=========================" << endl;
}

