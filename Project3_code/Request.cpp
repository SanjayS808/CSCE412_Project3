/**
 * @file Request.cpp
 * @brief Implementation file for the Request class.
 */
#include "Request.h"

//Constructors
/**
 * @brief Constructor for initializing a Request with specified parameters.
 * 
 * @param ipIn Source IP address.
 * @param ipOut Destination IP address.
 * @param time Processing time in milliseconds.
 */
Request::Request(string ipIn, string ipOut, int time)
    : ip_in(ipIn), ip_out(ipOut), processing_time(time) {}

/**
 * @brief Constructor for initializing a Request with random parameters.
 */
Request::Request() {
    ip_in = genRandomIp();
    ip_out = genRandomIp();
    processing_time = genRandomTime();
}


/**
 * @brief Generates a random IP address.
 */
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
/**
 * @brief Generates a random processing time.
 */

int Request::genRandomTime() {
    return std::rand() % 250 + 1;
}

/**
 * @brief Prints the details of the request.
 *
 * This function prints the source IP address, destination IP address, and processing time
 * of the request.
 */
void Request::printRequest() {
    std::cout << "Request: " << ip_in << " -> " << ip_out << " ("
              << processing_time << " ms)" << std::endl;
}