//
// Created by FatihPC on 12/23/2018.
//

#ifndef CS201_HW3_PARTA_SIMPLEPHONEBOOK_H
#define CS201_HW3_PARTA_SIMPLEPHONEBOOK_H

#include "SimplePerson.h"
#include <string>
#include <locale>
using namespace std;

class PhoneBook{

public:
    PhoneBook();
    ~PhoneBook();
    PhoneBook (const PhoneBook& phoneBookToCopy);
    void operator=(const PhoneBook& right);
    bool addPerson(const string name);
    bool removePerson(const string name);
    void displayPeople();

private:
    struct PersonNode {
        Person t;
        PersonNode* next;
    };

    PersonNode *head;
    int numberOfPeople;
    PersonNode* findPerson(string name);
};

#endif //CS201_HW3_PARTA_SIMPLEPHONEBOOK_H