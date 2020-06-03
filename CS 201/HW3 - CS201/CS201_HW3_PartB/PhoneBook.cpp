//
// Created by FatihPC on 12/23/2018.
//

#include "PhoneBook.h"

/**
 * Default Constructor for PhoneBook.
 */
PhoneBook::PhoneBook() {
    numberOfPeople = 0;
    head = NULL;
}

/**
 * Copy Constructor for PhoneBook class.
 * @param systemToCopy is the book to be copied.
 */
PhoneBook::PhoneBook(const PhoneBook &systemToCopy) {
    numberOfPeople = systemToCopy.numberOfPeople;

    // systemToCopy being empty.
    if (numberOfPeople == 0)
        head = NULL;

    else { // systemToCopy not being empty.

        // replicating head
        head = new Node;
        head->t = systemToCopy.head->t;
        Node *replicatorPtr = head;

        // replicating remaining nodes.
        for (Node *iterativePtr = systemToCopy.head->next;
                iterativePtr != NULL; iterativePtr = iterativePtr->next) {

            replicatorPtr->next = new Node;
            replicatorPtr = replicatorPtr->next;
            replicatorPtr->t = iterativePtr->t;
        }
        replicatorPtr->next = NULL;
    }
}

/**
 * Operator Overloading for PhoneBook class.
 * @param right is the book to be copied.
 */
void PhoneBook::operator=(const PhoneBook &right) {

    // removing the excess nodes.
    if (numberOfPeople > right.numberOfPeople) {
        while (numberOfPeople != right.numberOfPeople) {
            Node *cur = head;
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
            head = new Node;
            head->next = NULL;
        }

        head->t = right.head->t;
        Node *replicatorPtr = head;

        // replicating remaining nodes.
        for (Node *iterativePtr = right.head->next;
             iterativePtr != NULL; iterativePtr = iterativePtr->next) {

            // creating new node if not exists.
            if (replicatorPtr->next == NULL) {
                replicatorPtr->next = new Node;
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
PhoneBook::Node * PhoneBook::findPerson(string name) {

    for (Node *iterativePtr = head; iterativePtr != NULL; iterativePtr = iterativePtr->next) {

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
bool PhoneBook::addPerson(string name) {
    Node *newPerson = findPerson(name);

    // person doesn't exist.
    if (newPerson == NULL) {
        // constructing new person
        newPerson = new Node;
        newPerson->t = Person(name);

        // adding new person.
        newPerson->next = head;
        head = newPerson;
        numberOfPeople++;
        return true;
    }

    cout << "Person already exists." << endl;
    return false;
}

/**
 * removes a person from the phone book.
 * @param name is the name of the person.
 * @return true if added, false otherwise.
 */
bool PhoneBook::removePerson(const string name) {
    Node *prev = NULL;

    for (Node *cur = head; cur != NULL; cur = cur->next) {

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

    cout << "Person doesn't exist." << endl;
    return false;
}

/**
 * displays a person in more detail with phone numbers.
 * @param name is the name of the persons.
 */
void PhoneBook::displayPerson(string name) {
    Node *correspondingPerson = findPerson(name);

    // person doesn't exist
    if (correspondingPerson == NULL)
        cout << "--EMPTY--" << endl;

    else { // person exists
        cout << correspondingPerson->t.getName() << endl;
        if (correspondingPerson->t.hasPhoneNumbers())
            correspondingPerson->t.displayPhoneNumbers();
    }
}

/**
 * displays the users and their phone numbers for a specific area code.
 * @param areaCode is the specific area code.
 */
void PhoneBook::displayAreaCode(int areaCode) {
    cout << areaCode << endl;
    bool isAnyUserDisplayed = 0;

    for (Node *iterativePtr = head; iterativePtr != NULL; iterativePtr = iterativePtr->next) {
        if ( iterativePtr->t.hasPhoneNumbersOfAreaCode(areaCode) ) {
            isAnyUserDisplayed = 1;
            cout << iterativePtr->t.getName() << endl;
            iterativePtr->t.displayPhoneNumbersOfAreaCode(areaCode);
            cout << endl;
        }
    }

    if (!isAnyUserDisplayed)
        cout << "--EMPTY--" << endl;
}

/**
 * displays all people in the list and how many phones they have.
 */
void PhoneBook::displayPeople() {
    for (Node *iterativePtr = head; iterativePtr != NULL; iterativePtr = iterativePtr->next)
        cout << iterativePtr->t.getName() << ", " << iterativePtr->t.getPhoneCount() << endl;
}

/**
 * adds phone to a specific person.
 * @param personName is the name of the person.
 * @param areaCode is the area code of the num.
 * @param number is the phone number.
 * @return true if added, false otherwise.
 */
bool PhoneBook::addPhone(string personName, int areaCode, int number) {
    Node *correspondingPerson = findPerson(personName);

    if (correspondingPerson == NULL) {
        cout << "Person doesn't exist!!!" << endl;
        return false;
    }

    else
        return correspondingPerson->t.addPhone(areaCode, number);
}

/**
 * removes the phone from a specific person.
 * @param personName is the name of the corresponding person.
 * @param areaCode is the area code of the specific person.
 * @param number is the number of the phone.
 * @return true if added, otherwise false.
 */
bool PhoneBook::removePhone(string personName, int areaCode, int number) {
    Node *correspondingPerson = findPerson(personName);

    if (correspondingPerson == NULL) {
        cout << "Person doesn't exist!!!" << endl;
        return false;
    }

    else
        return correspondingPerson->t.removePhone(areaCode, number);
}

/**
 * Destructor for PhoneBook class.
 */
PhoneBook::~PhoneBook() {
    while (head != NULL) {
        Node *cur = head;
        head = head->next;
        cur->next = NULL;
        delete cur;
    }
}
