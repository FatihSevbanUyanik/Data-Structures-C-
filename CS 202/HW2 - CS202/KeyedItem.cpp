/**
* Title : KeyedItem.cpp file
* Author : Fatih Sevban Uyanık
* ID: 21602486
* Section : 1
* Assignment : 2
* Description: Contains the inner item of a tree node with a related key.
*/

#include "KeyedItem.h"

KeyedItem::KeyedItem(KeyType &searchKey) {
    this->searchKey = searchKey;
    this->frequency = 1;
}

const KeyType &KeyedItem::getSearchKey() const {
    return searchKey;
}

void KeyedItem::setFrequency(int frequency) {
    KeyedItem::frequency = frequency;
}

int KeyedItem::getFrequency() const {
    return frequency;
}
