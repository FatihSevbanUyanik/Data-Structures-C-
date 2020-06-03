//
// Created by FatihPC on 11/27/2019.
//

#include "ServerRequest.h"

ServerRequest::ServerRequest() {}

int ServerRequest::getId() const {
    return id;
}

void ServerRequest::setId(int id) {
    ServerRequest::id = id;
}

int ServerRequest::getPriority() const {
    return priority;
}

void ServerRequest::setPriority(int priority) {
    ServerRequest::priority = priority;
}

int ServerRequest::getTimeOfRequest() const {
    return timeOfRequest;
}

void ServerRequest::setTimeOfRequest(int timeOfRequest) {
    ServerRequest::timeOfRequest = timeOfRequest;
}

int ServerRequest::getProcessTime() const {
    return processTime;
}

void ServerRequest::setProcessTime(int processTime) {
    ServerRequest::processTime = processTime;
}

ServerRequest::ServerRequest(int id, int priority, int timeOfRequest, int processTime) {
    this->setId(id);
    this->setPriority(priority);
    this->setTimeOfRequest(timeOfRequest);
    this->setProcessTime(processTime);
}

