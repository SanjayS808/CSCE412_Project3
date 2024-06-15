#ifndef REQUEST_H
#define REQUEST_H
#include <iostream>
#include <string>
using namespace std;
class Request {
    
    public:
        string ip_in;
        string ip_out;
        int processing_time;

        //Prints the request
        void printRequest();

        //Constructor for request
        Request(string ipIn, string ipOut, int time);
        Request();
    private:
        //Helpers to generate random vals for request
        string genRandomIp();
        int genRandomTime();



};

#endif // REQUEST_H
