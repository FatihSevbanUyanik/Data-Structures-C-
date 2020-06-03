//
// Created by FatihPC on 12/23/2018.
//

#include "Phone.h"

/**
 * Default Constructor for Phone class.
 */
Phone::Phone() {
    areaCode = 0;
    number = 0;
}

/**
 * Constructor for Phone class.
 * @param areaCode is the areaCode.
 * @param number is the number.
 */
Phone::Phone(const int areaCode, const int number) {
    this->areaCode = areaCode;
    this->number = number;
}

/**
 * gets the number of the phone.
 * @return the number of the phone.
 */
int Phone::getNumber() {
    return number;
}

/**
 * gets the areaCode of the phone.
 * @return areaCode of the phone.
 */
int Phone::getAreaCode() {
    return areaCode;
}