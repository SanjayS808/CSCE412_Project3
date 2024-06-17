#ifndef REQUESTQUEUE_H
#define REQUESTQUEUE_H

#include <iostream>
#include <queue>
#include "Request.h"

using namespace std;

/**
 * @brief A class representing a queue of requests.
 * 
 * The RequestQueue class provides functionality to add requests, check if the queue is empty,
 * get the next request, and print the request queue.
 */
class RequestQueue{
    private:
        
    public:
        queue<Request> requests;
        
        /**
         * @brief Adds a request to the queue.
         * 
         * @param request The request to be added.
         */
        void addRequest(Request request);
        
        /**
         * @brief Checks if the queue is empty.
         * 
         * @return True if the queue is empty, false otherwise.
         */
        bool isEmpty();
        
        /**
         * @brief Gets the next request from the queue.
         * 
         * @return The next request in the queue.
         */
        Request getNextRequest();
        
        /**
         * @brief Prints the request queue.
         * 
         * This function prints the contents of the request queue to the standard output.
         */
        void printRequestQueue();
};

#endif // REQUESTQUEUE_H
