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
    
};


#endif // WEBSERVER_H