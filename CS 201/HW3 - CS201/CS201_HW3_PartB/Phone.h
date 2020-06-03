//
// Created by FatihPC on 12/23/2018.
//

#ifndef CS201_HW3_PARTB_PHONE_H
#define CS201_HW3_PARTB_PHONE_H

#include <iostream>
using namespace std;

class Phone{

public:
    Phone();
    Phone( const int areaCode, const int number );
    int getAreaCode();
    int getNumber();

private:
    int areaCode;
    int number;
};

#endif //CS201_HW3_PARTB_PHONE_H
