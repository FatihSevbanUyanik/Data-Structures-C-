//
// Created by FatihPC on 11/9/2018.
//

#ifndef CS_201_HW1_SIMPLEMUSICALBUM_H
#define CS_201_HW1_SIMPLEMUSICALBUM_H

#include <string>
using namespace std;

class MusicAlbum {

public:

    // constructor
    MusicAlbum(const string maArtist = "",
               const string maTitle = "",
               const int maYear = 0);

    // destructor
    ~MusicAlbum();

    // copy constructor
    MusicAlbum(const MusicAlbum &maToCopy);

    // overloaded assignment operator.
    void operator=(const MusicAlbum &right);

    // methods
    string getMusicAlbumArtist();
    string getMusicAlbumTitle();
    int getMusicAlbumYear();

private:
    // properties
    string artist;
    string title;
    int year;
};

#endif //CS_201_HW1_SIMPLEMUSICALBUM_H