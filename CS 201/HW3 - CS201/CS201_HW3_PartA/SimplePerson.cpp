//
// Created by FatihPC on 12/23/2018.
//

#include "SimplePerson.h"

/**
 * Default Constructor for SimplePerson class.
 * @param name is the name of the person.
 */
Person::Person(const string name) {
    this->name = name;
}

/**
 * Copy Constructor for SimplePerson class.
 * @param personToCopy is the person to be copied.
 */
Person::Person(const Person &personToCopy) {
    name = personToCopy.name;
}

/**
 * Operator Overloading for SimplePerson class.
 * @param right is the person to be copied.
 */
void Person::operator=(const Person &right) {
    name = right.name;
}

/**
 * Destructor for the SimplePerson class.
 */
Person::~Person() {
    // Destructor
}

/**
 * gets the name of the person.
 * @return name of the person.
 */
string Person::getName() {
    return name;
}
