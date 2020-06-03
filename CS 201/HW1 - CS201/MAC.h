//
// Created by FatihPC on 11/15/2018.
//

#ifndef CS_201_HW1_MAC_H
#define CS_201_HW1_MAC_H

#include <string>
using namespace std;

#include "MusicAlbum.h"

class MAC{

public:

    // constructor
    MAC();

    // destructor
    ~MAC();

    // copy constructor
    MAC(const MAC &macToCopy);

    // operator overloading
    void operator=(const MAC &right);

    // methods
    bool addMusicAlbum(const string maArtist,
                       const string maTitle,
                       const int maYear);

    bool removeMusicAlbum(const string maArtist, const string maTitle);

    int getMusicAlbums(MusicAlbum *&allMusicAlbums);

    bool addSong(const string maArtist, const string maTitle,
                 const string sName, const int sMins, const int sSecs);

    bool removeSongs(const string maArtist, const string maTitle);

    void calculateAvgMusicAlbumLength(int &minutes, int &seconds);

    // methods added by the programmer.
    void resize(int newSize);

private:
    // properties
    MusicAlbum *musicAlbums;
    int noOfMusicAlbums;
};

#endif //CS_201_HW1_MAC_H