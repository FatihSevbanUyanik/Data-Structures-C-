//
// Created by FatihPC on 12/23/2018.
//

#ifndef CS201_HW3_PARTA_SIMPLEPERSON_H
#define CS201_HW3_PARTA_SIMPLEPERSON_H

#include <string>
using namespace std;

class Person {

public:
    Person( const string name = "" );
    ~Person();
    Person ( const Person &personToCopy );
    void operator=( const Person &right );
    string getName();

private:
    string name;
};

#endif //CS201_HW3_PARTA_SIMPLEPERSON_H