//
// Created by FatihPC on 11/15/2018.
//

#include "MusicAlbum.h"
#include "MAC.h"
#include "Song.h"
#include <iostream>
using namespace std;

/**
 * Music Album Constructor.
 * @param maArtist is the music album artist.
 * @param maTitle is the music album title.
 * @param maYear is the music album year.
 */
MusicAlbum::MusicAlbum(const string maArtist, const string maTitle, const int maYear) {
    artist = maArtist;
    title = maTitle;
    year = maYear;
    noSongs = 0;
    songs = NULL;
}

/**
 * Music Album Copy Constructor.
 * @param maToCopy is the album to be copied.
 */
MusicAlbum::MusicAlbum(const MusicAlbum &maToCopy) {

    // copying data
    artist = maToCopy.artist;
    title = maToCopy.title;
    year = maToCopy.year;

    // noSongs bigger than 0
    if (maToCopy.noSongs > 0) {
        noSongs = maToCopy.noSongs;
        songs = new Song[ noSongs ];

        for (int i = 0; i < noSongs; i++)
            songs[i] = maToCopy.songs[i];
    }

    else { // noSongs smaller than 0.
        noSongs = 0;
        songs = NULL;
    }
}

/**
 * Music Album Operator Overloading.
 * @param maToCopy is the album to be copied.
 */
void MusicAlbum::operator=(const MusicAlbum &right) {

    // deleting previous data
    if (songs != NULL)
        delete [] songs;

    // copying data
    artist = right.artist;
    title = right.title;
    year = right.year;

    // noSongs bigger than 0
    if (right.noSongs > 0) {
        noSongs = right.noSongs;
        songs = new Song[ right.noSongs ];

        for (int i = 0; i < noSongs; i++)
            songs[i] = right.songs[i];

    } else { // noSongs smaller than 0.
        noSongs = 0;
        songs = NULL;
    }
}

/**
 * resizes the new array and change
 * the corresponding values in array.
 * @param newSize is the new size.
 */
void MusicAlbum::resize(int newSize) {

    if (newSize > 0) {

        // already having items
        if (noSongs != 0) {

            // assigning temp pointer to previous data
            Song *temp = songs;
            songs = new Song[newSize];

            // copying previous data to new allocated memory

            // bigger
            if (newSize > noSongs)
                for (int i = 0; i < noSongs; i++)
                    songs[i] = temp[i];

            else // smaller
                for (int i = 0; i < newSize; i++)
                    songs[i] = temp[i];

            // copying size and deleting data.
            noSongs = newSize;
            delete [] temp;
        }

        // not having albums.
        else {
            // initialising
            songs = new Song[newSize];
            noSongs = newSize;
        }
    }

    // if newSize 0, assigning null.
    else {
        noSongs = 0;
        delete [] songs;
        songs = NULL;
    }
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
 * adds a new song to the music album.
 * @param song is the song to be added.
 * @return true is added, false otherwise.
 */
bool MusicAlbum::addSong(Song song) {

    // noSongs bigger than 0.
    if (noSongs != 0) {

        // checking whether song exist.
        for (int i = 0; i < noSongs; i++) {

            // exist.
            if ( songs[i].getName() == song.getName() && songs[i].getSecs() == song.getSecs() && songs[i].getMins() == song.getMins())
                return false;

            else { // doesn't exist.
                resize(noSongs + 1);
                songs[noSongs - 1] = song;
                return true;
            }
        }
    }

    else { // no songs available.
        resize(noSongs + 1);
        songs[noSongs - 1] = song;
        return true;
    }
}

/**
 * calculates music album length.
 * @param minutes is the minute length.
 * @param seconds is the second length.
 */
void MusicAlbum::calculateMusicAlbumLength(int &minutes, int &seconds) {

    int sumOfAllSongsLengthInSeconds = 0;

    for (int i = 0; i < noSongs; i++)
        sumOfAllSongsLengthInSeconds += (songs[i].getMins() * 60) + songs[i].getSecs();

    minutes = sumOfAllSongsLengthInSeconds / 60;
    seconds = sumOfAllSongsLengthInSeconds % 60;
}

/**
 * removes all the song from the album.
 * @return true if removed, false otherwise.
 */
bool MusicAlbum::removeSongs() {

    // no songs present to remove.
    if (songs == NULL && noSongs == 0)
        return false;

    else { // removing
        delete [] songs;
        songs = NULL;
        noSongs = 0;
        return true;
    }
}

/**
 * Destructor For Music Album.
 */
MusicAlbum::~MusicAlbum() {
    delete [] songs;
}
