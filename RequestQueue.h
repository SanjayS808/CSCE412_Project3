#ifndef REQUESTQUEUE_H
#define REQUESTQUEUE_H
#include <iostream>
#include <queue>
#include "Request.h"

using namespace std;

class RequestQueue{
    private:
        
    public:
        queue<Request> requests;
        void addRequest(Request request);
        bool isEmpty();
        Request getNextRequest();
        void printRequestQueue();
        
};

#endif // REQUESTQUEUE_H