// main.cpp
#include "LoadBalancer.h"
#include <iostream>

int main() {
    int numServers;
    int runTime;
    int initialQueueSize;

    std::cout << "Enter the number of servers: ";
    std::cin >> numServers;

    std::cout << "Enter the simulation run time (in clock cycles): ";
    std::cin >> runTime;

    initialQueueSize = numServers * 50;

    LoadBalancer loadBalancer(numServers, runTime);
    loadBalancer.initQueue(initialQueueSize);

    for (int time = 0; time < runTime; ++time) {
        loadBalancer.tick();
        if (rand() % 50 == 0 ) { // Randomly add new requests

           loadBalancer.addRandomRequest();
        }
        loadBalancer.allocateServer(time);

    }

    cout << loadBalancer.requestQueue.requests.size() << " requests remaining in queue" << endl;
    std::cout << "Simulation complete. All servers are idle: " << std::boolalpha << loadBalancer.allServersIdle() << std::endl;

    return 0;
}
