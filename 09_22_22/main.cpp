#include <iostream>
#include <cstdlib>
#include "queue.h"

int main()
{
    queue<int> q(10);
    for(int i = 0; i < 10; i++)
    {
        int x = rand() % 1000 + 1;
        q.enqueue(x);
        std::cout << "Added to queue: " << x << std::endl;
        
        if(x % 2 == 0)
        {
            std::cout << "Removing from queue: " << q.dequeue() << std::endl;
        }
    }

    return 0;

}