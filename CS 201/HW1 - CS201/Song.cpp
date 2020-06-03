//
// Created by FatihPC on 11/15/2018.
//

#include "MusicAlbum.h"
#include "MAC.h"
#include "Song.h"

/**
 * Constructor for Song class.
 * @param sName is song name.
 * @param sMins is song mins.
 * @param sSecs is song secs.
 */
Song::Song(const string sName, const int sMins, const int sSecs) {
    name = sName;
    mins = sMins;
    secs = sSecs;
}

/**
 * Copy Constructor for Song class.
 * @param songToCopy the obj to be copied.
 */
Song::Song(const Song &songToCopy) {
    name = songToCopy.name;
    mins = songToCopy.mins;
    secs = songToCopy.secs;
}

/**
 * gets the name of the song.
 * @return the name of the song.
 */
string Song::getName() {
    return name;
}

/**
 * get minutes of the song.
 * @return the minutes.
 */
int Song::getMins() {
    return mins;
}

/**
 * get minutes of the song.
 * @return the minutes.
 */
int Song::getSecs() {
    return secs;
}

/**
 * Operator Overloading for Song class.
 * @param right the obj to be overloaded.
 */
void Song::operator=(const Song &right) {
    name = right.name;
    mins = right.mins;
    secs = right.secs;
}

/**
 * Destructor for Song class.
 */
Song::~Song() {}