/**
* Title : FileReader
* Author :Fatih Sevban Uyanık
* ID: 21602485
* Section : 1
* Assignment : 4
* Description : Reads items.txt file
*/

#ifndef HW3_FILEREADER_H
#define HW3_FILEREADER_H

#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

class FileReader {
public:
    FileReader();
    void readTextFile(int &totalCount, string *&fruits, int *&fruitCounts);
    void printRequests(int totalCount, string *&fruits, int *&fruitCounts);
};


#endif //HW3_FILEREADER_H
