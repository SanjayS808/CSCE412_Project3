/**
 * @file RequestQueue.cpp
 * @brief Implementation of the RequestQueue class.
 */

#include "RequestQueue.h"

/**
 * @brief Adds a request to the request queue.
 * @param request The request to be added.
 */
void RequestQueue::addRequest(Request request) {
    requests.push(request);
}

/**
 * @brief Checks if the request queue is empty.
 * @return True if the request queue is empty, false otherwise.
 */
bool RequestQueue::isEmpty() {
    return requests.empty();
}

/**
 * @brief Retrieves the next request from the request queue.
 * @return The next request in the queue.
 */
Request RequestQueue::getNextRequest() {
    Request nextRequest = requests.front();
    requests.pop();
    return nextRequest;
}

/**
 * @brief Prints all the requests in the request queue.
 */
void RequestQueue::printRequestQueue() {
    queue<Request> temp = requests;
    while (!temp.empty()) {
        temp.front().printRequest();
        temp.pop();
    }
}
