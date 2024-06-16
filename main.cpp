#include <iostream>
#include "Request.h"
#include "RequestQueue.h"
#include "WebServer.h"

int main() {
    Request test;
    Request test1;
    Request test2;

    RequestQueue queue;
    queue.addRequest(test);
    queue.addRequest(test1);
    queue.addRequest(test2);

    int time = 10000;
    WebServer server(1, time);

    while (!queue.isEmpty()) {
        Request nextRequest = queue.getNextRequest();
        server.processRequest(nextRequest);
        server.tick();
    }



}