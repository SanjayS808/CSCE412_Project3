#include "WebServer.h"

using namespace std;

void WebServer::processRequest(Request request) {
    cout << "Server " << id<< " is processing request from " << request.ip_in << " to " << request.ip_out << " for " << request.processing_time << " seconds" << endl;
    isBusy = true;
    timeLeft = request.processing_time;
}

void WebServer::tick() {
    if (isBusy && timeLeft > 0) {
        timeLeft--;
        if (timeLeft == 0) {
            isBusy = false;
            cout << "Server " << id<< " has processed request" <<  endl;
        }
    }
}