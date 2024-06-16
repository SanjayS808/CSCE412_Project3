// main.cpp
#include "LoadBalancer.h"
#include <iostream>
#include <fstream>

int main() {
    int numServers;
    int runTime;
    int initialQueueSize;

    

    std::cout << "Enter the number of servers: ";
    std::cin >> numServers;

    std::cout << "Enter the simulation run time (in clock cycles): ";
    std::cin >> runTime;

    std::ofstream outFile("log.txt");
    std::streambuf* coutBuf = std::cout.rdbuf();
    std::cout.rdbuf(outFile.rdbuf());
    cout << "Server Count: " << numServers << endl;
    cout << "Simulation Run Time: " << runTime << endl;
    initialQueueSize = numServers * 100;
    cout << "Initial Queue Size: " << initialQueueSize << endl << endl;
    LoadBalancer loadBalancer(numServers, runTime);
    loadBalancer.initQueue(initialQueueSize);
    cout << "Simulation started" << endl;
    for (int time = 0; time < runTime; ++time) {
        loadBalancer.tick();
        if (rand() % 50 == 0 && time < 1000) { // Randomly add new requests

           loadBalancer.addRandomRequest();
        }
        
       loadBalancer.allocateServer(time);
       

    }
    
    
    std::cout << endl << "Simulation complete. All servers are idle: " << std::boolalpha << loadBalancer.allServersIdle() << std::endl;
    cout << "Final Queue Size: "<< loadBalancer.requestQueue.requests.size() << " requests" << endl;
    cout << "Number of servers: " << loadBalancer.servers.size() << endl;
    std::cout.rdbuf(coutBuf);
    return 0;
}
