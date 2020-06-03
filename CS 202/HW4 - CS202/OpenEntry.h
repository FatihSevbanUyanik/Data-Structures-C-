/**
* Title : OpenEntry
* Author :Fatih Sevban Uyanık
* ID: 21602485
* Section : 1
* Assignment : 4
* Description : OpenEntry is an item in the table
*/

#ifndef HW4_OPENENTRY_H
#define HW4_OPENENTRY_H

#include <iostream>
using namespace std;

class OpenEntry {

public:
    OpenEntry();
    OpenEntry(int hashKey, int status, int quantity, const string &item);
    int getHashKey() const;
    void setHashKey(int hashKey);
    int getStatus() const;
    void setStatus(int status);
    int getQuantity() const;
    void setQuantity(int quantity);
    const string &getItem() const;
    void setItem(const string &item);
    void printEntry();

private:
    int hashKey;
    int status;
    int quantity;
    string item;
};


#endif //HW4_OPENENTRY_H
