/**
 * @file Webserver.cpp
 * @brief Implementation file for the WebServer class.
 */

#include "WebServer.h"

using namespace std;

/**
 * @brief Processes the given request.
 * 
 * This function processes the given request by printing the server ID, source IP, destination IP, processing time, and the current ratio.
 * It also sets the server's busy status and the remaining time for processing the request.
 * 
 * @param request The request to be processed.
 */
void WebServer::processRequest(Request request) {
    cout << "Server " << id<< " is processing request from " << request.ip_in << " to " << request.ip_out << " for " << request.processing_time << " seconds." << endl ;
    isBusy = true;
    timeLeft = request.processing_time;
}

/**
 * @brief Performs a tick of the server.
 * 
 * This function is called periodically to simulate the passage of time for the server.
 * If the server is busy and there is still time left for processing the request, it decrements the remaining time.
 * If the remaining time becomes zero, it sets the server's busy status to false and prints a message indicating that the request has been processed.
 */
void WebServer::tick() {
    if (isBusy && timeLeft > 0) {
        timeLeft--;
        if (timeLeft == 0) {
            isBusy = false;
            cout << "Server " << id<< " has processed request." <<  endl;
        }
    }
}
