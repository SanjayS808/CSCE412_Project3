#include "LoadBalancer.h"
#include <iostream>

LoadBalancer::LoadBalancer(int numServers,int time) : numServers(numServers), time(time) {
    for (int i = 0; i < numServers; i++) {
        WebServer server(i,time );
        servers.push_back(server);
    }
}


void LoadBalancer::initQueue(int size) {
    for (int i = 0; i < size; i++) {
        Request request;
        requestQueue.addRequest(request);
    }
}


void LoadBalancer::addRandomRequest() {
    Request request;
    requestQueue.addRequest(request);
}

void LoadBalancer::tick(){
    for (auto& server : servers) {
        if (!server.isBusy && !requestQueue.isEmpty()) {
            server.processRequest(requestQueue.getNextRequest());
        }
        server.tick();
    }
}

bool LoadBalancer::allServersIdle() {
    for (auto& server : servers) {
        if (server.isBusy) {
            return false;
        }
    }
    return true;
}