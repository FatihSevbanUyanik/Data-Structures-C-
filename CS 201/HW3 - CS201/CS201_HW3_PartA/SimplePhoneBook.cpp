//
// Created by FatihPC on 12/23/2018.
//

#include "SimplePhoneBook.h"
#include <iostream>
#include <locale>
using namespace std;

/**
 * Default Constructor for SimplePhoneBook class.
 */
PhoneBook::PhoneBook() {
    numberOfPeople = 0;
    head = NULL;
}

/**
 * Copy Constructor for SimplePhoneBook class.
 * @param phoneBookToCopy is the book to be copied.
 */
PhoneBook::PhoneBook(const PhoneBook &phoneBookToCopy) {
    numberOfPeople = phoneBookToCopy.numberOfPeople;

    // phoneBookToCopy being empty.
    if (numberOfPeople == 0)
        head = NULL;

    else { // phoneBookToCopy not being empty.

        // replicating head
        head = new PersonNode;
        head->t = phoneBookToCopy.head->t;
        PersonNode *replicatorPtr = head;

        // replicating remaining nodes.
        for (PersonNode *iterativePtr = phoneBookToCopy.head->next;
                iterativePtr != NULL; iterativePtr = iterativePtr->next) {

            replicatorPtr->next = new PersonNode;
            replicatorPtr = replicatorPtr->next;
            replicatorPtr->t = iterativePtr->t;
        }

        replicatorPtr->next = NULL;
    }
}

/**
 * Operator Overloading for SimplePhoneBook class.
 * @param right  is the book to be copied.
 */
void PhoneBook::operator=(const PhoneBook &right) {
    // removing the excess nodes.
    if (numberOfPeople > right.numberOfPeople) {
        while (numberOfPeople != right.numberOfPeople) {
            PersonNode *cur = head;
            head = head->next;
            cur->next = NULL;
            delete cur;
            numberOfPeople--;
        }
    }

    // replicating nodes
    if (right.numberOfPeople > 0) {

        // replicating head.
        if (head == NULL) {
            head = new PersonNode;
            head->next = NULL;
        }

        head->t = right.head->t;
        PersonNode *replicatorPtr = head;

        // replicating remaining nodes.
        for (PersonNode *iterativePtr = right.head->next;
                iterativePtr != NULL; iterativePtr = iterativePtr->next) {

            // creating new node if not exists.
            if (replicatorPtr->next == NULL) {
                replicatorPtr->next = new PersonNode;
                replicatorPtr->next->next = NULL;
            }

            replicatorPtr = replicatorPtr->next;
            replicatorPtr->t = iterativePtr->t;
        }

        replicatorPtr->next = NULL;
        numberOfPeople = right.numberOfPeople;
    }
}

/**
 * finds a person with the specified name.
 * @param name is the person's name.
 * @return true if found, false otherwise.
 */
PhoneBook::PersonNode * PhoneBook::findPerson(string name) {

    for (PersonNode *iterativePtr = head; iterativePtr != NULL; iterativePtr = iterativePtr->next) {

        // checking for case insensitiveness.
        if (iterativePtr->t.getName().size() == name.size()){
            bool temp = true;

            for (int i = 0; i < name.size(); i++)
                if (tolower(iterativePtr->t.getName().at(i)) != tolower(name.at(i))) {
                    temp = false;
                    break;
                }

            if (temp)
                return iterativePtr;
        }
    }

    return NULL;
}

/**
 * adds a person to the phone book.
 * @param name is the name of the person.
 * @return true if added, false otherwise.
 */
bool PhoneBook::addPerson(const string name) {
   PersonNode *newPerson = findPerson(name);

   // person doesn't exist.
   if (newPerson == NULL) {
       // constructing new person
       newPerson = new PersonNode;
       newPerson->t = Person(name);

       // adding new person.
       newPerson->next = head;
       head = newPerson;
       numberOfPeople++;
       return true;
   }

   return false;
}

/**
 * removes a person from the phone book.
 * @param name is the name of the person.
 * @return true if added, false otherwise.
 */
bool PhoneBook::removePerson(const string name) {
    PersonNode *prev = NULL;

    for (PersonNode *cur = head; cur != NULL; cur = cur->next) {
        // removing a node.
        if (cur->t.getName() == name) {
            // removing first node.
            if (cur == head)
                head = head->next;

            else // removing other nodes.
                prev->next = cur->next;

            cur->next = NULL;
            delete cur;
            numberOfPeople--;
            return true;
        }
        prev = cur;
    }
    return false;
}

/**
 * displays all of the
 * people in the phone book.
 */
void PhoneBook::displayPeople() {
    // list being empty.
    if (head == NULL)
        cout << "--EMPTY--" << endl;

    else // displaying
        for (PersonNode *iterativePtr = head; iterativePtr != NULL; iterativePtr = iterativePtr->next)
            cout << "Person: " << iterativePtr->t.getName() << endl;
}

/**
 * Destructor for SimplePhoneBook class.
 */
PhoneBook::~PhoneBook() {
    while (head != NULL) {
        PersonNode *cur = head;
        head = head->next;
        cur->next = NULL;
        delete cur;
    }
}