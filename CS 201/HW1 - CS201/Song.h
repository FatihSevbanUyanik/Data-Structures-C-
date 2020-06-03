//
// Created by FatihPC on 11/15/2018.
//

#ifndef CS_201_HW1_SONG_H
#define CS_201_HW1_SONG_H

#include <string>
using namespace std;

class Song {
public:
    // default constructor
    Song(const string sName = "", const int sMins = 0, const int sSecs = 0);

    // destructor
    ~Song();

    // copy constructor
    Song(const Song &songToCopy);

    // operator overloading
    void operator=(const Song &right);

    // methods added by the programmer.
    string getName();
    int getMins();
    int getSecs();

private:
    // properties
    string name;
    int mins;
    int secs;
};

#endif //CS_201_HW1_SONG_H
