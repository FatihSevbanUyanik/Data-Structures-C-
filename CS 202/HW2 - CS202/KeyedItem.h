/**
* Title : KeyedItem.h file
* Author : Fatih Sevban Uyanık
* ID: 21602486
* Section : 1
* Assignment : 2
* Description: Contains the inner item of a tree node with a related key.
*/

#ifndef HW2_KEYEDITEM_H
#define HW2_KEYEDITEM_H

#include <iostream>
using namespace std;
typedef string KeyType;

class KeyedItem {
public:
    KeyedItem(KeyType &searchKey);
    const KeyType &getSearchKey() const;
    void setFrequency(int frequency);

    int getFrequency() const;

private:
    // properties
    KeyType searchKey;
    int frequency;
};


#endif //HW2_KEYEDITEM_H
