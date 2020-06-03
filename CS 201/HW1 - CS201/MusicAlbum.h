//
// Created by FatihPC on 11/15/2018.
//

#ifndef CS_201_HW1_MUSICALBUM_H
#define CS_201_HW1_MUSICALBUM_H

#include <string>
using namespace std;

#include "Song.h"

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

    // operator overloading
    void operator=(const MusicAlbum &right);

    // methods
    string getMusicAlbumArtist();
    string getMusicAlbumTitle();
    int getMusicAlbumYear();
    void calculateMusicAlbumLength(int &minutes, int &seconds);

    // methods added by the programmer.
    bool addSong(Song song);
    void resize(int newSize);
    bool removeSongs();

private:
    // properties
    string artist;
    string title;
    int year;
    Song *songs;
    int noSongs;
};

#endif //CS_201_HW1_MUSICALBUM_H