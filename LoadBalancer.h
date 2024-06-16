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
        RequestQueue requestQueue;
        vector<WebServer> servers;
        int numServers;
        int time;
    public:
        LoadBalancer(int numServers, int time);
        void initQueue(int size);
        void tick();
        bool allServersIdle();
        void addRandomRequest();

};  

#endif 