//
// Created by FatihPC on 11/27/2019.
//

#include "Computer.h"

Computer::Computer(int id) {
    remainingTime = 0;
    this->id = id;
}

bool Computer::isAvailable() {
    return remainingTime == 0;
}

void Computer::processRequest(ServerRequest &serverRequest, int currentTime) {
    remainingTime = serverRequest.getProcessTime();
    cout << "Computer " << id << " takes request " << serverRequest.getId() << " at ms " <<
    currentTime << "(wait: " << currentTime - serverRequest.getTimeOfRequest() << " ms)" << endl;
}

void Computer::progress() {
    if (remainingTime > 0) {
        remainingTime--;
    }
}
