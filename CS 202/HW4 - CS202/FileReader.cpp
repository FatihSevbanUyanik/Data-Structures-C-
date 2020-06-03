/**
* Title : FileReader
* Author :Fatih Sevban Uyanık
* ID: 21602485
* Section : 1
* Assignment : 4
* Description : Reads items.txt file
*/

#include "FileReader.h"

FileReader::FileReader() {}

void FileReader::readTextFile(int &totalCount, string *&fruits, int *&fruitCounts) {
    string text;
    string line;
    string fileName = "items.txt";
    ifstream inputStream(fileName.c_str());
    totalCount = 0;

    // getting text from input text file.
    if (inputStream.is_open()) {
        while ( getline (inputStream, line) ) {
            totalCount++;
        }
        inputStream.close();
    }
    else { // error while opening file.
        cout << "Unable to open file";
        return;
    }

    ifstream inputStream2(fileName.c_str());
    fruits = new string[totalCount];
    fruitCounts = new int[totalCount];

    // getting text from input text file.
    if (inputStream2.is_open()) {
        int index = 0;
        while (getline(inputStream2, line) ) {
            string fruitCountStr;
            int fruitCount;
            int counter = 0;

            while (line[counter] != ' ' && line[counter] != '\t' ) {
                fruitCountStr += line[counter++];
            }

            counter++;
            stringstream ss(fruitCountStr);
            ss >> fruitCount;

            string fruitStr;
            while (counter < line.length()) {
                fruitStr += line[counter++];
            }

            fruitCounts[index] = fruitCount;
            fruits[index] = fruitStr;
            index++;
        }
        inputStream2.close();
    }
    else { // error while opening file.
        cout << "Unable to open file";
        return;
    }
}

void FileReader::printRequests(int totalCount, string *&fruits, int *&fruitCounts) {
    for (int i = 0; i < totalCount; i++) {
        cout << fruitCounts[i] << " ---> " << fruits[i] << endl;
    }
    cout << "-------------------------------------" << endl;
    cout << "Total Count: " << totalCount << endl;
    cout << "-------------------------------------" << endl;
}
