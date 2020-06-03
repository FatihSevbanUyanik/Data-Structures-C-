//
// Created by FatihPC on 11/27/2019.
//

#ifndef HW3_COMPUTER_H
#define HW3_COMPUTER_H


#include "PriorityQueue.h"

class Computer {
public:
    Computer(int id);
    void processRequest(ServerRequest &serverRequest, int currentTime);
    void progress();
    bool isAvailable();
private:
    int remainingTime;
    int id;
};


#endif //HW3_COMPUTER_H
