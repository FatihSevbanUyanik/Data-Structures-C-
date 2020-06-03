#include "Person.h"
#include "Phone.h"
#include "PhoneBook.h"
#include <iostream>
using namespace std;

int main() {

    PhoneBook phoneBook;
    phoneBook.addPerson("Person1");
    phoneBook.addPerson("Person2");
    phoneBook.addPerson("Person3");
    phoneBook.addPerson("Person4");
    phoneBook.addPerson("Person4");
    phoneBook.addPerson("Person4");
    phoneBook.addPerson("Person4");
    phoneBook.addPerson("Person4");
    phoneBook.addPerson("Person5");
    phoneBook.addPerson("Person6");
    phoneBook.addPerson("Person7");
    phoneBook.addPerson("PersoN7");
    phoneBook.addPerson("PersOn7");
    phoneBook.addPerson("person7");
    phoneBook.addPerson("PerSon7");

    cout << endl;
    cout << "*************************" << endl;
    phoneBook.displayPeople();
    cout << "*************************" << endl;
    cout << endl;

    phoneBook.removePerson("Person5");
    phoneBook.removePerson("Person6");
    phoneBook.removePerson("Person7");
    phoneBook.removePerson("Person7");
    phoneBook.removePerson("Person7");
    phoneBook.removePerson("Person10");

    cout << endl;
    cout << "*************************" << endl;
    phoneBook.displayPeople();
    cout << "*************************" << endl;
    cout << endl;

    phoneBook.addPhone("Person4", 7777, 1111);
    phoneBook.addPhone("Person4", 7777, 2222);
    phoneBook.addPhone("Person4", 7777, 3333);

    phoneBook.addPhone("Person1", 1111, 5656);
    phoneBook.addPhone("Person1", 1111, 2222);
    phoneBook.addPhone("Person1", 3333, 2222);
    phoneBook.addPhone("Person1", 7777, 9999);

    cout << endl;
    cout << "*************************" << endl;
    phoneBook.displayPeople();
    cout << "*************************" << endl;
    cout << endl;

    cout << endl;
    cout << "*************************" << endl;
    phoneBook.displayPerson("Person4");
    cout << "*************************" << endl;
    cout << endl;

    cout << endl;
    cout << "*************************" << endl;
    phoneBook.displayPerson("Person3");
    cout << "*************************" << endl;
    cout << endl;

    cout << endl;
    cout << "*************************" << endl;
    phoneBook.displayPerson("Person2");
    cout << "*************************" << endl;
    cout << endl;

    cout << endl;
    cout << "*************************" << endl;
    phoneBook.displayPerson("Person1");
    cout << "*************************" << endl;
    cout << endl;

    cout << endl;
    cout << "*************************" << endl;
    phoneBook.displayAreaCode(7777);
    cout << "*************************" << endl;
    cout << endl;

    cout << endl;
    cout << "*************************" << endl;
    phoneBook.displayAreaCode(3333);
    cout << "*************************" << endl;
    cout << endl;

    cout << endl;
    cout << "*************************" << endl;
    phoneBook.displayAreaCode(1111);
    cout << "*************************" << endl;
    cout << endl;

    cout << endl;
    cout << "*************************" << endl;
    phoneBook.displayAreaCode(8585);
    cout << "*************************" << endl;
    cout << endl;

    cout << endl;
    cout << "*************************" << endl;
    phoneBook.displayPeople();
    cout << "*************************" << endl;
    cout << endl;

    phoneBook.removePerson("Person4");
    phoneBook.removePerson("Person3");
    phoneBook.removePerson("Person2");
    phoneBook.removePerson("Person2");
    phoneBook.removePerson("Person1");
    phoneBook.removePerson("Person1");

    cout << endl;
    cout << "*************************" << endl;
    phoneBook.displayPeople();
    cout << "*************************" << endl;
    cout << endl;

    cout << endl;
    cout << "*************************" << endl;
    cout << "*************************" << endl;
    cout << "*************************" << endl;
    cout << "*************************" << endl;
    cout << endl;

    PhoneBook phoneBook2;
    phoneBook2.addPerson("Person1");
    phoneBook2.addPerson("Person2");
    phoneBook2.addPerson("Person3");
    phoneBook2.addPerson("Person4");
    phoneBook2.addPerson("Person4");
    phoneBook2.addPerson("Person4");
    phoneBook2.addPerson("Person4");
    phoneBook2.addPerson("Person4");
    phoneBook2.addPerson("Person5");
    phoneBook2.addPerson("Person6");
    phoneBook2.addPerson("Person7");

    phoneBook2.addPhone("Person1", 2222, 121212);
    phoneBook2.addPhone("Person1", 2222, 363363);
    phoneBook2.addPhone("Person1", 2222, 145454);
    phoneBook2.addPhone("Person1", 2222, 145454);
    phoneBook2.addPhone("Person1", 2222, 145454);

    PhoneBook phoneBook3;
    phoneBook3.addPerson("Person1");
    phoneBook3.addPerson("Person2");

    cout << endl;
    cout << "*************************" << endl;
    phoneBook2.displayPeople();
    cout << "*************************" << endl;
    cout << endl;

    cout << endl;
    cout << "*************************" << endl;
    phoneBook3.displayPeople();
    cout << "*************************" << endl;
    cout << endl;

    cout << endl;
    cout << "*************************" << endl;
    cout << "*************************" << endl;
    cout << "*************************" << endl;
    cout << "*************************" << endl;
    cout << endl;

    phoneBook3 = phoneBook2;

    cout << endl;
    cout << "*************************" << endl;
    phoneBook2.displayPeople();
    cout << "*************************" << endl;
    cout << endl;

    cout << endl;
    cout << "*************************" << endl;
    phoneBook3.displayPeople();
    cout << "*************************" << endl;
    cout << endl;

    cout << endl;
    cout << "*************************" << endl;
    cout << "*************************" << endl;
    cout << "*************************" << endl;
    cout << "*************************" << endl;
    cout << endl;

    PhoneBook phoneBook4(phoneBook2);

    cout << endl;
    cout << "*************************" << endl;
    phoneBook4.displayPeople();
    cout << "*************************" << endl;
    cout << endl;

    return 0;
}