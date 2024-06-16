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
    cout << "New request from "<<request.ip_in << " to " << request.ip_out << "for " <<request.processing_time <<"ms was added to queue" << endl;
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

void LoadBalancer::allocateServer(int time) {
    int ratio = requestQueue.requests.size() / servers.size();
    if (ratio > 100){
        WebServer newServer(servers[-1].id + 1, time);
        servers.push_back(newServer);
        cout<< "Server " << servers[-1].id << " has been allocated" << endl;
    }   
    else if (ratio < 50 && servers.size() > 1){ 
        
        cout<< "Server " << servers[-1].id << " has been deallocted" << endl;
        servers.pop_back();
    }
    else{
        return;
    }
       
    

}