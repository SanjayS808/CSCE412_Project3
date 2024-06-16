/**
 * @file main.cpp
 * @brief A program to simulate a load balancer and log simulation details.
 */

#include "LoadBalancer.h"
#include <iostream>
#include <fstream>
#include <cstdlib> // For rand()

using namespace std;

/**
 * @brief Main function that runs the load balancer simulation.
 * @return 0 on successful execution.
 */
int main() {
    int numServers; ///< Number of servers in the system.
    int runTime;    ///< Simulation run time in clock cycles.
    int initialQueueSize; ///< Initial queue size based on number of servers.

    // Prompt user for input
    cout << "Enter the number of servers: ";
    cin >> numServers;

    cout << "Enter the simulation run time (in clock cycles): ";
    cin >> runTime;

    // Open log file for writing
    ofstream outFile("log.txt");
    if (!outFile) {
        cerr << "Error opening log.txt for writing" << endl;
        return 1;
    }

    // Redirect cout to log.txt
    streambuf* coutBuf = cout.rdbuf();
    cout.rdbuf(outFile.rdbuf());

    // Output simulation parameters to log file
    cout << "Server Count: " << numServers << endl;
    cout << "Simulation Run Time: " << runTime << endl;
    initialQueueSize = numServers * 100;
    cout << "Initial Queue Size: " << initialQueueSize << endl << endl;

    // Initialize load balancer
    LoadBalancer loadBalancer(numServers, runTime);
    loadBalancer.initQueue(initialQueueSize);

    // Start simulation
    cout << "Simulation started" << endl;
    for (int time = 0; time < runTime; ++time) {
        loadBalancer.tick();

        // Randomly add new requests
        if (rand() % 50 == 0 && time < 1000) {
            loadBalancer.addRandomRequest();
        }
        
        // Allocate server resources
        loadBalancer.allocateServer(time);
    }

    // Simulation complete
    cout << endl << "Simulation complete. All servers are idle: " << boolalpha << loadBalancer.allServersIdle() << endl;
    cout << "Final Queue Size: " << loadBalancer.requestQueue.requests.size() << " requests" << endl;
    cout << "Number of servers: " << loadBalancer.servers.size() << endl;

    // Restore cout to terminal output
    cout.rdbuf(coutBuf);

    return 0;
}
