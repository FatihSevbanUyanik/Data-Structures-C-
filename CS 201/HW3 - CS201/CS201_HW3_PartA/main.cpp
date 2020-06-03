#include "SimplePerson.h"
#include "SimplePhoneBook.h"
#include <iostream>
using namespace std;


int main() {

    PhoneBook phoneBook1;

    cout << "***************" << endl;
    phoneBook1.displayPeople();
    cout << "***************" << endl << endl;

    phoneBook1.addPerson("Person1");
    phoneBook1.addPerson("person1");
    phoneBook1.addPerson("PeRson1");
    phoneBook1.addPerson("PeRson1");
    phoneBook1.addPerson("PersOn1");
    phoneBook1.addPerson("Person2");
    phoneBook1.addPerson("Person3");
    phoneBook1.addPerson("Person4");
    phoneBook1.addPerson("Person5");
    phoneBook1.addPerson("Person6");

    cout << "***************" << endl;
    phoneBook1.displayPeople();
    cout << "***************" << endl << endl;

    phoneBook1.addPerson("Person3");

    cout << "***************" << endl;
    phoneBook1.displayPeople();
    cout << "***************" << endl << endl;

    phoneBook1.removePerson("Person1");
    phoneBook1.removePerson("Person3");
    phoneBook1.removePerson("Person4");

    cout << "***************" << endl;
    phoneBook1.displayPeople();
    cout << "***************" << endl << endl;

    PhoneBook phoneBook2(phoneBook1);

    cout << "phoneBook1" << endl;
    cout << "***************" << endl;
    phoneBook1.displayPeople();
    cout << "***************" << endl << endl;

    cout << "phoneBook2" << endl;
    phoneBook2.displayPeople();
    cout << "***************" << endl << endl;

    phoneBook2.addPerson("aaaa");
    phoneBook2.addPerson("bbbb");

    phoneBook1 = phoneBook2;
    cout << "code passes" << endl;

    cout << "phoneBook1" << endl;
    cout << "***************" << endl;
    phoneBook1.displayPeople();
    cout << "***************" << endl << endl;

    cout << "phoneBook2" << endl;
    phoneBook2.displayPeople();
    cout << "***************" << endl << endl;

    return 0;
}