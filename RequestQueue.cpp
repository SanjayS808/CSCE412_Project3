#include "RequestQueue.h"

void RequestQueue::addRequest(Request request) {
    requests.push(request);
}

bool RequestQueue::isEmpty() {
    return requests.empty();
}

Request RequestQueue::getNextRequest() {
    Request nextRequest = requests.front();
    requests.pop();
    return nextRequest;
}

void RequestQueue::printRequestQueue() {
    queue<Request> temp = requests;
    while (!temp.empty()) {
        temp.front().printRequest();
        temp.pop();
    }
}