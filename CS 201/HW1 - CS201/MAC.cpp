//
// Created by FatihPC on 11/15/2018.
//

#include "MusicAlbum.h"
#include "MAC.h"
#include "Song.h"
#include <iostream>
using namespace std;


/**
 * Default Constructor for MAC.
 */
MAC::MAC() {
    noOfMusicAlbums = 0;
    musicAlbums = NULL;
}

/**
 * Copy Constructor for MAC
 * @param macToCopy is the Mac.
 */
MAC::MAC(const MAC &macToCopy) {

    // bigger than 0.
    if (macToCopy.noOfMusicAlbums > 0) {

        // copying size and allocating memory.
        noOfMusicAlbums = macToCopy.noOfMusicAlbums;
        musicAlbums = new MusicAlbum[ noOfMusicAlbums ];

        // copying data
        for (int i = 0; i < macToCopy.noOfMusicAlbums; i++)
            musicAlbums[i] = macToCopy.musicAlbums[i];
    }

    else { // smaller or equal to 0.
        noOfMusicAlbums = 0;
        musicAlbums = NULL;
    }
}

/**
 * Operator Overloading for MAC.
 * @param right MAC to be overloaded.
 */
void MAC::operator=(const MAC &right) {

    // bigger than 0.
    if (right.noOfMusicAlbums > 0) {

        // deleting previous music albums data.
        if (musicAlbums != NULL)
            delete [] musicAlbums;

        // copying size and allocating memory.
        noOfMusicAlbums = right.noOfMusicAlbums;

        // copying data
        for (int i = 0; i < right.noOfMusicAlbums; i++)
            musicAlbums[i] = right.musicAlbums[i];
    }

    else { // smaller or equal to 0.
        noOfMusicAlbums = 0;
        musicAlbums = NULL;
    }
}

/**
 * Destructor For MAC.
 */
MAC::~MAC() {
    delete [] musicAlbums;
}

/**
 * gets all music albums in the collection.
 * @param allMusicAlbums is the parameter
 * where the music albums data will go.
 * @return number of music albums in MAC.
 */
int MAC::getMusicAlbums(MusicAlbum *&allMusicAlbums) {

    // allocating memory
    allMusicAlbums = new MusicAlbum[ noOfMusicAlbums ];

    // copying files
    for (int i = 0; i < noOfMusicAlbums; i++)
        allMusicAlbums[i] = musicAlbums[i];

    return noOfMusicAlbums;
}

/**
 * resizes the new array and change
 * the corresponding values in array.
 * @param newSize is the new size.
 */
void MAC::resize(int newSize) {

    if (newSize > 0) {

        // already having items
        if (noOfMusicAlbums != 0) {

            // assigning temp pointer to previous data
            MusicAlbum *temp = musicAlbums;
            musicAlbums = new MusicAlbum[newSize];

            // copying previous data to new allocated memory

            // bigger
            if (newSize > noOfMusicAlbums)
                for (int i = 0; i < noOfMusicAlbums; i++)
                    musicAlbums[i] = temp[i];

            else // smaller
                for (int i = 0; i < newSize; i++)
                    musicAlbums[i] = temp[i];

            // copying size and deleting data.
            noOfMusicAlbums = newSize;
            delete [] temp;
        }


        else { // not having albums.
            // initialising
            musicAlbums = new MusicAlbum[newSize];
            noOfMusicAlbums = newSize;
        }
    }

    else { // if newSize 0, assigning null.
        noOfMusicAlbums = 0;
        delete [] musicAlbums;
        musicAlbums = NULL;
    }
}

/**
 * adds a new music album to MAC.
 * @param maArtist is the artist of the music album.
 * @param maTitle is the title of the music album.
 * @param maYear is the year of the music album.
 * @return true if album is added and false otherwise.
 */
bool MAC::addMusicAlbum(const string maArtist, const string maTitle, const int maYear) {

    // checking whether we have the same album in MAC.
    for (int i = 0; i < noOfMusicAlbums; i++)
        if (musicAlbums[i].getMusicAlbumTitle() == maTitle && musicAlbums[i].getMusicAlbumArtist() == maArtist)
            return false;

    // increasing the size of
    // collection for new music album.
    resize(noOfMusicAlbums + 1);


    // adding music album to collection.
    musicAlbums[noOfMusicAlbums - 1] = MusicAlbum(maArtist, maTitle, maYear);
    return true;
}

/**
 * removes a music album from MAC.
 * @param maArtist is the artist of the music album.
 * @param maTitle is the title of the music album.
 * @return true if album is removed and false otherwise.
 */
bool MAC::removeMusicAlbum(const string maArtist, const string maTitle) {

    // checking whether we have the album in MAC.
    for (int i = 0; i < noOfMusicAlbums; i++) {

        if (musicAlbums[i].getMusicAlbumTitle() == maTitle && musicAlbums[i].getMusicAlbumArtist() == maArtist) {

            // assigning temp pointer to current data
            MusicAlbum *result = new MusicAlbum[--noOfMusicAlbums];

            int j;

            // adding values except data to be removed.
            for (j = 0; j < i; j++)
                result[j] = musicAlbums[j];

            for (int k = (i+1); k < (noOfMusicAlbums + 1); k++, j++)
                result[j] = musicAlbums[k];

            // avoiding leakage
            delete [] musicAlbums;
            musicAlbums = result;

            return true;
        }
    }

    return false;
}

/**
 * adds a new song to a specified album in the MAC.
 * @param maArtist is the music album artist.
 * @param maTitle is the music album title.
 * @param sName is the song name.
 * @param sMins is the song minutes.
 * @param sSecs is the song seconds.
 * @return true is song is added, otherwise false.
 */
bool MAC::addSong(const string maArtist, const string maTitle, const string sName, const int sMins, const int sSecs) {

    // checking whether the album exists in MAC.
    for (int i = 0; i < noOfMusicAlbums; i++)
        if (musicAlbums[i].getMusicAlbumTitle() == maTitle && musicAlbums[i].getMusicAlbumArtist() == maArtist)
            return musicAlbums[i].addSong( Song(sName, sMins, sSecs) ); // adding

    // not added, false
    return false;
}

/**
 * removes a song from the collection.
 * @param maArtist is the artist name.
 * @param maTitle is the title name.
 * @return true if removed, otherwise false.
 */
bool MAC::removeSongs(const string maArtist, const string maTitle) {

    // checking whether the album exists in MAC.
    for (int i = 0; i < noOfMusicAlbums; i++)
        if (musicAlbums[i].getMusicAlbumTitle() == maTitle && musicAlbums[i].getMusicAlbumArtist() == maArtist)
            return musicAlbums[i].removeSongs();
}

/**
 * calculates average music album length.
 * @param minutes the minute length of album.
 * @param seconds the second length of album.
 */
void MAC::calculateAvgMusicAlbumLength(int &minutes, int &seconds) {

    int sumOfMusicAlbumLength = 0;
    int tempMins;
    int tempSecs;

    // fetching length data of each album.
    for (int i = 0; i < noOfMusicAlbums; i++) {
        musicAlbums[i].calculateMusicAlbumLength(tempMins, tempSecs);
        sumOfMusicAlbumLength += (tempMins * 60) + tempSecs;
    }

    // calculating avg length.
    int avgInSecs = sumOfMusicAlbumLength / noOfMusicAlbums;
    minutes = avgInSecs / 60;
    seconds = avgInSecs % 60;
}
