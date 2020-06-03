//
// Created by FatihPC on 12/23/2018.
//

#include "Person.h"
#include <iostream>
using namespace std;

/**
 * Default Constructor for Person class.
 * @param name is the name of the person.
 */


Person::Person(const string name) {
    this->name = name;
    head = NULL;
    noOfPhoneNumbers = 0;
}

/**
 * Copy Constructor for Person class.
 * @param personToCopy is the person to be copied.
 */
Person::Person(const Person &personToCopy) {
    name = personToCopy.name;
    noOfPhoneNumbers = personToCopy.noOfPhoneNumbers;

    // no phones available
    if (personToCopy.head == NULL)
        head = NULL;

    else { // replicating phones.

        // replicating head
        head = new PhoneNode;
        head->p = personToCopy.head->p;
        PhoneNode *replicatorPtr = head;

        // replicating remaining nodes.
        for (PhoneNode *iterativePtr = personToCopy.head->next;
                iterativePtr != NULL ; iterativePtr = iterativePtr->next) {

            replicatorPtr->next = new PhoneNode;
            replicatorPtr = replicatorPtr->next;
            replicatorPtr->p = iterativePtr->p;
        }
        replicatorPtr->next = NULL;
    }
}

/**
 * Operator Overloading for Person class.
 * @param right is the person to be copied.
 */
void Person::operator=(const Person &right) {

    // removing all phone nodes.
    while (noOfPhoneNumbers != 0) {
        PhoneNode *cur = head;
        head = head->next;
        cur->next = NULL;
        delete cur;
        noOfPhoneNumbers--;
    }

    head = NULL;
    name = right.name;
    noOfPhoneNumbers = right.noOfPhoneNumbers;

    if (right.head != NULL) {

        // replicating head
        head = new PhoneNode;
        head->p = right.head->p;
        PhoneNode *replicatorPtr = head;

        // replicating remaining nodes.
        for (PhoneNode *iterativePtr = right.head->next;
             iterativePtr != NULL ; iterativePtr = iterativePtr->next) {

            replicatorPtr->next = new PhoneNode;
            replicatorPtr = replicatorPtr->next;
            replicatorPtr->p = iterativePtr->p;
        }

        replicatorPtr->next = NULL;
    }
}

/**
 * gets the name of the person.
 * @return name of the person.
 */
string Person::getName() {
    return name;
}

/**
 * checks whether the person has phone numbers or not.
 * @return whether the person has phone numbers or not.
 */
bool Person::hasPhoneNumbers() const {
    return head != NULL;
}

/**
 * finds the phone's corresponding node.
 * @param areaCode is the area code of the number.
 * @param number is the phone number.
 * @return true if found, otherwise false.
 */
PhoneNode* Person::findPhone(const int areaCode, const int number) {
    for (PhoneNode *iterativePtr = head; iterativePtr != NULL; iterativePtr = iterativePtr->next)
        if (iterativePtr->p.getAreaCode() == areaCode && iterativePtr->p.getNumber() == number)
            return iterativePtr;

    return NULL;
}

/**
 * Adds a new phone to the list.
 * @param areaCode is the area code.
 * @param number is the phone number.
 * @return true if added, false otherwise.
 */
bool Person::addPhone(const int areaCode, const int number) {
    PhoneNode *newPhone = findPhone(areaCode, number);

    // phone doesn't exist.
    if (newPhone == NULL) {
        // constructing new phone.
        newPhone = new PhoneNode;
        newPhone->p = Phone(areaCode, number);

        // adding new phone
        newPhone->next = head;
        head = newPhone;

        noOfPhoneNumbers++;
        return true;
    }

    cout << "Phone already exists" << endl;
    return false;
}

/**
 * removes a phone node from the list.
 * @param areaCode is the area code.
 * @param number is the phone number.
 * @return true if removed, otherwise false.
 */
bool Person::removePhone(const int areaCode, const int number) {
    PhoneNode *prev = NULL;

    // iterating through the list to find the related phoneNode.
    for (PhoneNode *cur = head; cur != NULL; cur = cur->next) {

        // removing a node.
        if (cur->p.getAreaCode() == areaCode && cur->p.getNumber() == number) {

            // removing first node.
            if (cur == head)
                head = head->next;

            else // removing other nodes.
                prev->next = cur->next;

            cur->next = NULL;
            delete cur;

            noOfPhoneNumbers--;
            return true;
        }
        prev = cur;
    }

    cout << "Phone doesn't exist!!!" << endl;
    return false;
}

/**
 * Displays all of the phone numbers.
 */
void Person::displayPhoneNumbers() {

    // list is empty
    if (head == NULL)
        cout << "--EMPTY--" << endl;

    else // list is full, printing out.
        for (PhoneNode *iterativePtr = head; iterativePtr != NULL; iterativePtr = iterativePtr->next)
            cout << "Phone Number: " << iterativePtr->p.getAreaCode() << ", " << iterativePtr->p.getNumber() << endl;
}

/**
 * displays phone Numbers of a particular area code.
 * @param areaCode is the number of area code.
 */
bool Person::hasPhoneNumbersOfAreaCode(int areaCode) const {
    for (PhoneNode *iterativePtr = head; iterativePtr != NULL; iterativePtr = iterativePtr->next)
        if (iterativePtr->p.getAreaCode() == areaCode)
            return true;

    return false;
}

/**
 * displays phone Numbers of a particular area code.
 * @param areaCode is the number of area code.
 */
void Person::displayPhoneNumbersOfAreaCode(int areaCode) const {
    for (PhoneNode *iterativePtr = head; iterativePtr != NULL; iterativePtr = iterativePtr->next)
        if (iterativePtr->p.getAreaCode() == areaCode)
            cout << "Phone Number: " << iterativePtr->p.getAreaCode() << ", " << iterativePtr->p.getNumber() << endl;
}

/**
 * gets the phone count of the person.
 * @return the phone count of the person.
 */
int Person::getPhoneCount() const {
    return noOfPhoneNumbers;
}

/**
 * Destructor for SimplePhoneBook class.
 */
Person::~Person() {
    // removing all phone nodes.
    while (head != NULL) {
        PhoneNode *cur = head;
        head = head->next;
        cur->next = NULL;
        delete cur;
    }
}