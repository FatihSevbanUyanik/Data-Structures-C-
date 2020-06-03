//
// Created by FatihPC on 11/27/2019.
//

#ifndef HW3_REQUEST_H
#define HW3_REQUEST_H


class ServerRequest {
public:
    ServerRequest();
    ServerRequest(int id, int priority, int timeOfRequest, int processTime);
    int getId() const;
    void setId(int id);
    int getPriority() const;
    void setPriority(int priority);
    int getTimeOfRequest() const;
    void setTimeOfRequest(int timeOfRequest);
    int getProcessTime() const;
    void setProcessTime(int processTime);

private:
    int id;
    int priority;
    int timeOfRequest;
    int processTime;
};


#endif //HW3_REQUEST_H
