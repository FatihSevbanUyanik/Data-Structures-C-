//
// Created by FatihPC on 12/23/2018.
//

#ifndef CS201_HW3_PARTB_PERSON_H
#define CS201_HW3_PARTB_PERSON_H

#include "Phone.h"
#include <string>
using namespace std;

struct PhoneNode {
    Phone p;
    PhoneNode* next;
};

class Person{

public:
    Person( const string name = "" );
    ~Person();
    Person( const Person& personToCopy );
    void operator=( const Person &right );
    string getName();
    bool addPhone( const int areaCode, const int number );
    bool removePhone( const int areaCode, const int number );
    void displayPhoneNumbers();

    // methods added by the programmer.
    bool hasPhoneNumbers() const;
    void displayPhoneNumbersOfAreaCode(int areaCode) const;
    bool hasPhoneNumbersOfAreaCode(int areaCode) const;
    int getPhoneCount() const;

private:
    PhoneNode *head;
    string name;
    PhoneNode* findPhone( const int areaCode, const int number );

    // properties added by the programmer
    int noOfPhoneNumbers;
};

#endif //CS201_HW3_PARTB_PERSON_H
