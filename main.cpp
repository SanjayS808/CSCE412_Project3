#include <iostream>
#include "Request.h"
#include "RequestQueue.h"

int main() {
    Request test;
    Request test1;
    Request test2;

    RequestQueue queue;
    queue.addRequest(test);
    queue.addRequest(test1);
    queue.addRequest(test2);

    queue.printRequestQueue();

    cout << queue.isEmpty() << endl;
    queue.getNextRequest();
    queue.getNextRequest().printRequest();
    queue.getNextRequest();
    cout << queue.isEmpty() << endl;


}