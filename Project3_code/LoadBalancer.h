#ifndef LOADBALANCER_H
#define LOADBALANCER_H

#include "RequestQueue.h"
#include "WebServer.h"
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

/**
 * @brief LoadBalancer class manages a collection of WebServer instances and a RequestQueue.
 */

class LoadBalancer{
    private:
        
        //members
        
        int numServers;  ///< Number of servers in the system.
        
        int time;   ///< Current time in milliseconds since program start.
        
    public:

        vector<WebServer> servers;
        RequestQueue requestQueue;
        /**
         * @brief Constructor for LoadBalancer class.
         * 
         * @param numServers Number of servers to initialize.
         * @param time Time interval for server tick.
         */
        LoadBalancer(int numServers, int time);

        /**
         * @brief Initializes the request queue with a specified size.
         * 
         * @param size Size of the request queue to initialize.
         */
        void initQueue(int size);
        /**
         * @brief Progresses the state of the load balancer by one time unit.
         *        Assigns requests to servers and updates server state.
         */
        void tick();
        /**
         * @brief Checks if all servers are idle.
         * 
         * @return True if all servers are idle, false otherwise.
         */
        bool allServersIdle();
        /**
         * @brief Adds a random request to the request queue.
         */
        void addRandomRequest();
        /**
         * @brief Allocates a server to a request.
         * 
         * @param time Time interval for server tick.
         */
        
        void allocateServer(int time);

};  

#endif 