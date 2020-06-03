#include <iostream>
#include "ServerRequest.h"
#include "PriorityQueue.h"
#include "Computer.h"
#include "FileReader.h"
using namespace std;

void updateRequestQueue(PriorityQueue &eventRequests, ServerRequest *&requests, int totalRequestCount, int currentTime) {
    for (int i = 0; i < totalRequestCount; i++) {
        if (requests[i].getTimeOfRequest() == currentTime) {
            eventRequests.pqInsert(requests[i]);
        }
    }
}

int main() {
    int requestCount = 4;
    int processedRequestCount = 0;
    ServerRequest *requests;
    FileReader fileReader;
    //fileReader.readTextFile(requestCount, requests);

    ServerRequest serverRequest1(1, 8, 3, 5);
    ServerRequest serverRequest2(2, 4, 30, 3);
    ServerRequest serverRequest3(3, 2, 44, 24);
    ServerRequest serverRequest4(4, 3, 57, 20);
    requests = new ServerRequest[4];
    requests[0] = serverRequest1;
    requests[1] = serverRequest2;
    requests[2] = serverRequest3;
    requests[3] = serverRequest4;

    // EventRequests Queue
    PriorityQueue eventRequests(requestCount);

    // getting computer count
    int computerCount = 3;

    Computer **computers = new Computer*[computerCount];
    for (int i = 0; i < computerCount; i ++) { computers[i] = new Computer(i); }

    int timer = 1;

    // simulating requests
    while (processedRequestCount < requestCount) {
        updateRequestQueue(eventRequests, requests, requestCount, timer);
        for (int i = 0; i < computerCount; i++) {
            if (computers[i]->isAvailable() && !eventRequests.pqIsEmpty()) {
                ServerRequest request;
                eventRequests.pqDelete(request);
                computers[i]->processRequest(request, timer);
                processedRequestCount++;
            }
            computers[i]->progress();
        }
        timer++;
    }

    return 0;
}

