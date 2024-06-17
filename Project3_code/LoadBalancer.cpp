/**
 * @file LoadBalancer.cpp
 * @brief Implementation file for the LoadBalancer class.
 */
#include "LoadBalancer.h"
#include <iostream>



/**
 * @brief Constructor for LoadBalancer class.
 * 
 * @param numServers Number of initial servers to create.
 * @param time Time interval for server tick.
 */

LoadBalancer::LoadBalancer(int numServers,int time) : numServers(numServers), time(time) {
    for (int i = 0; i < numServers; i++) {
        WebServer server(i,time );
        servers.push_back(server);
    }
}
/**
 * @brief Initializes the request queue with a specified size.
 * 
 * @param size Size of the request queue to initialize.
 */

void LoadBalancer::initQueue(int size) {
    for (int i = 0; i < size; i++) {
        Request request;
        requestQueue.addRequest(request);
    }
}
/**
 * @brief Adds a random request to the request queue.
 */

void LoadBalancer::addRandomRequest() {
    Request request;
    cout << "New request from "<<request.ip_in << " to " << request.ip_out << "for " <<request.processing_time <<" s was added to queue." << endl;
    requestQueue.addRequest(request);
}


/**
 * @brief Progresses the state of the load balancer by one time unit.
 *        Assigns requests to servers and updates server state.
 */

void LoadBalancer::tick(){
    for (auto& server : servers) {
        if (!server.isBusy && !requestQueue.isEmpty()) {
            server.processRequest(requestQueue.getNextRequest());
            
        }
        server.tick();
    }
}

/**
 * @brief Checks if all servers are idle.
 * 
 * @return True if all servers are idle, false otherwise.
 */
bool LoadBalancer::allServersIdle() {
    if(servers.size() == 0){
        return false;
    }
    for (auto& server : servers) {
        if (server.isBusy) {
            return false;
        }
    }
    return true;
}

/**
 * @brief Allocates or deallocates servers based on queue length and server idle status.
 * 
 * @param time Time interval for server tick.
 */
void LoadBalancer::allocateServer(int time) {
    int ratio = requestQueue.requests.size() / servers.size();
    if (ratio > 50){
        WebServer newServer(servers[servers.size()-1].id + 1, time);
        servers.push_back(newServer);
        cout<< "Server " << servers[servers.size()-1].id << " has been allocated. "  <<endl;
    }   
    else if (allServersIdle() &&  servers.size() > 1){ 
        
        cout<< "Server " << servers[servers.size()-1].id << " has been deallocated. " << endl;
        servers.pop_back();
    }
    else{
        return;
    }

}