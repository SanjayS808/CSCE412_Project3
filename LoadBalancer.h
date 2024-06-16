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
        
        vector<WebServer> servers;
        int numServers;
        int time;
    public:
        RequestQueue requestQueue;
        LoadBalancer(int numServers, int time);
        void initQueue(int size);
        void tick();
        bool allServersIdle();
        void addRandomRequest();
        void allocateServer(int time);

};  

#endif 