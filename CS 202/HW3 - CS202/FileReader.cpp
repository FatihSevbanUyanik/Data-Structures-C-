//
// Created by FatihPC on 11/27/2019.
//

#include "FileReader.h"

FileReader::FileReader() {}

/**
 * reads the requests in the text file.
 * @param requestCount the number of requests will be stored.
 * @param requests are the requests records to be stored.
 */
void FileReader::readTextFile(int &requestCount, ServerRequest *&requests) {
    string text;
    string line;
    string fileName = "input.txt";
    ifstream inputStream(fileName.c_str());

    // getting text from input text file.
    if (inputStream.is_open()) {
        while ( getline (inputStream, line) ) { text += line + ' '; }
        inputStream.close();
    }
    else { // error while opening file.
        cout << "Unable to open file";
        return;
    }

    string requestCountStr;
    int counter = 0;

    while (text[counter] != ' ') {
        requestCountStr += text[counter];
        counter++;
    }

    // variables for constructing requests.
    stringstream ss(requestCountStr);
    ss >> requestCount;
    requests = new ServerRequest[requestCount];
    int requestCounter = 0;
    counter++;

    // getting each request.
    while (counter < text.size()) {
        int tmp = 0;
        string number;
        ServerRequest serverRequest;

        while (tmp != 4) {
            if (text[counter] == ' ' && number.length() > 0) {
                int numb;
                stringstream ss(number);
                ss >> numb;

                if (tmp == 0) {
                    serverRequest.setId(numb);
                } else if (tmp == 1) {
                    serverRequest.setPriority(numb);
                } else if (tmp == 2) {
                    serverRequest.setTimeOfRequest(numb);
                } else if (tmp == 3) {
                    serverRequest.setProcessTime(numb);
                }
                tmp++;
                number = "";
            }
            else if (text[counter] != ' ') {
                number += text[counter];
            }
            counter++;
        }
        requests[requestCounter++] = serverRequest;
        counter++;
    }
}

void FileReader::printRequests(int requestCount, ServerRequest *requests) {
    for (int i = 0; i < requestCount; i++) {
        cout << "id: "                  << requests[i].getId()
             << "\tpriority: "          << requests[i].getPriority()
             << "\tTime Of Request: "   << requests[i].getTimeOfRequest()
             << "\tProcess Time: "      << requests[i].getProcessTime()
             << endl;
    }
}
