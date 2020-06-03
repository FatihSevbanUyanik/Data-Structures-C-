//
// Created by FatihPC on 11/9/2018.
//

#ifndef CS_201_HW1_SIMPLEMAC_H
#define CS_201_HW1_SIMPLEMAC_H

#include "SimpleMusicAlbum.h"
#include <string>
using namespace std;

class MAC {

public:
    // constructor
    MAC();

    // destructor
    ~MAC();

    // copy constructor
    MAC(const MAC &macToCopy);

    // overloaded assignment operator.
    void operator=(const MAC &right);

    // methods
    bool addMusicAlbum(const string maArtist,
                       const string maTitle,
                       const int maYear);

    bool removeMusicAlbum(const string maArtist,
                          const string maTitle);

    int getMusicAlbums(MusicAlbum *&allMusicAlbums);

    // methods added by the programmer.
    void resize(int newSize);

private:
    // properties
    MusicAlbum *musicAlbums;
    int noOfMusicAlbums;
};

#endif //CS_201_HW1_SIMPLEMAC_H
