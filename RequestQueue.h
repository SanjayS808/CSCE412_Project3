#ifndef REQUESTQUEUE_H
#define REQUESTQUEUE_H
#include <iostream>
#include <queue>
#include "Request.h"

using namespace std;

class RequestQueue{
    private:
        queue<Request> requests;
    public:
        void addRequest(Request request);
        bool isEmpty();
        Request getNextRequest();
        void printRequestQueue();
        
};

#endif // REQUESTQUEUE_H