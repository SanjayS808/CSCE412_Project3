#ifndef REQUEST_H
#define REQUEST_H

#include <iostream>
#include <string>

using namespace std;

/**
 * @brief The Request class represents a network request.
 */
class Request {
public:
    /**
     * @brief The source IP address of the request.
     */
    string ip_in;

    /**
     * @brief The destination IP address of the request.
     */
    string ip_out;

    /**
     * @brief The processing time required for the request.
     */
    int processing_time;

    /**
     * @brief Prints the details of the request.
     */
    void printRequest();

    /**
     * @brief Constructs a Request object with the given parameters.
     * @param ipIn The source IP address of the request.
     * @param ipOut The destination IP address of the request.
     * @param time The processing time required for the request.
     */
    Request(string ipIn, string ipOut, int time);

    /**
     * @brief Default constructor for Request class.
     */
    Request();

private:
    /**
     * @brief Generates a random IP address.
     * @return A randomly generated IP address.
     */
    string genRandomIp();

    /**
     * @brief Generates a random processing time.
     * @return A randomly generated processing time.
     */
    int genRandomTime();
};

#endif // REQUEST_H
