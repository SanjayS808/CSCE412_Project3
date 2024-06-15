#include "Request.h"

//Constructors
Request::Request(string ipIn, string ipOut, int time)
    : ip_in(ipIn), ip_out(ipOut), processing_time(time) {}

Request::Request() {
    ip_in = genRandomIp();
    ip_out = genRandomIp();
    processing_time = genRandomTime();
}


//
string Request::genRandomIp() {

    // Generate each octet of the IP address
    int octet1 = std::rand() % 256;
    int octet2 = std::rand() % 256;
    int octet3 = std::rand() % 256;
    int octet4 = std::rand() % 256;

    // Construct the IP address string
    std::string ipAddress = std::to_string(octet1) + "." +
                            std::to_string(octet2) + "." +
                            std::to_string(octet3) + "." +
                            std::to_string(octet4);

    return ipAddress;
}

int Request::genRandomTime() {
    return std::rand() % 1000 + 1;
}

void Request::printRequest() {
    std::cout << "Request: " << ip_in << " -> " << ip_out << " ("
              << processing_time << " ms)" << std::endl;
}