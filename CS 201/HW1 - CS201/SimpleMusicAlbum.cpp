//
// Created by FatihPC on 11/9/2018.
//

#include <iostream>
using namespace std;

#include "SimpleMusicAlbum.h"

/**
 * Simple Music Album Constructor.
 * @param maArtist is the music album artist.
 * @param maTitle is the music album title.
 * @param maYear is the music album year.
 */
MusicAlbum::MusicAlbum(const string maArtist, const string maTitle, const int maYear) {
    artist = maArtist;
    title = maTitle;
    year = maYear;
}

/**
 * Simple Music Album Copy Constructor.
 * @param maToCopy is the album to be copied.
 */
MusicAlbum::MusicAlbum(const MusicAlbum &maToCopy) {
    artist = maToCopy.artist;
    title = maToCopy.title;
    year = maToCopy.year;
}

/**
 * Simple Music Album Assignment Operator Overloading.
 * @param right is the album to be assigned to this.
 */
void MusicAlbum::operator=(const MusicAlbum &right) {
    artist = right.artist;
    year = right.year;
    title = right.title;
}

/**
 * gets the music albums artist.
 * @return the music albums artist.
 */
string MusicAlbum::getMusicAlbumArtist() {
    return artist;
}

/**
 * gets the music albums title.
 * @return the music albums title.
 */
string MusicAlbum::getMusicAlbumTitle() {
    return title;
}

/**
 * gets the music albums year.
 * @return the music albums year.
 */
int MusicAlbum::getMusicAlbumYear() {
    return year;
}

/**
 * Destructor For Simple Music Album.
 */
MusicAlbum::~MusicAlbum() {}