
#include <iostream>

#include "Queue.h"

int main()
{
    Queue* myQueue = new Queue(2);

    myQueue->Enqueue(1);

    std::cout << "Dequeued Value: " << myQueue->Dequeue();
    std::cout << "\n\nDequeued Value: " << myQueue->Dequeue();
    std::cout << "\n\nDequeued Value: " << myQueue->Dequeue();
    return 0;
}

