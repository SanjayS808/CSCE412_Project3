#ifndef WEBSERVER_H
#define WEBSERVER_H
#include <iostream>
#include "Request.h"
// Takes requests from the Load Balancer
// Process the requests
// Asks for another

class WebServer{
    public:
        int id;
        bool isBusy;
        void processRequest(Request request);
        void tick();
        int timeLeft;
        WebServer(int id, int time) {
            this->id = id;
            isBusy = false;
            this->timeLeft = time;
        }
    
};


#endif // WEBSERVER_H