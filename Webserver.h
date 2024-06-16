#ifndef WEBSERVER_H
#define WEBSERVER_H

#include <iostream>
#include "Request.h"

/**
 * @brief The WebServer class represents a web server that takes requests from a load balancer,
 *        processes the requests, and asks for another request.
 */
class WebServer{
    public:
        int id; /**< The ID of the web server. */
        bool isBusy; /**< Indicates whether the web server is currently busy processing a request. */
        int timeLeft; /**< The time left for the web server to finish processing the current request. */

        /**
         * @brief Constructs a new WebServer object with the given ID and processing time.
         * 
         * @param id The ID of the web server.
         * @param time The time required for the web server to process a request.
         */
        WebServer(int id, int time) {
            this->id = id;
            isBusy = false;
            this->timeLeft = time;
        }

        /**
         * @brief Processes the given request by the web server.
         * 
         * @param request The request to be processed.
         */
        void processRequest(Request request);

        /**
         * @brief Performs a tick of the web server, decrementing the time left for the current request.
         */
        void tick();
};

#endif // WEBSERVER_H