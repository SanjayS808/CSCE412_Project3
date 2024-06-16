#ifndef LOADBALANCER_H
#define LOADBALANCER_H

#include "RequestQueue.h"
#include "WebServer.h"
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;
class LoadBalancer{
    private:
        
        //members
        int numServers;
        int time;
        
    public:

        vector<WebServer> servers;
        RequestQueue requestQueue;
        LoadBalancer(int numServers, int time);
        void initQueue(int size);
        void tick();
        bool allServersIdle();
        void addRandomRequest();
        void allocateServer(int time);

};  

#endif 