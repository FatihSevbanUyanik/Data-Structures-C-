//
// Created by FatihPC on 11/27/2019.
//

#ifndef HW3_FILEREADER_H
#define HW3_FILEREADER_H


#include "ServerRequest.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

class FileReader {
public:
    FileReader();
    void readTextFile(int &requestCount, ServerRequest *&requests);
    void printRequests(int requestCount, ServerRequest *requests);
};


#endif //HW3_FILEREADER_H
