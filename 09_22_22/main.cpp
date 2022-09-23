#include <iostream>
#include <cstdlib>
#include <ctime>
#include "queue.h"
#include "book.h"

int main()
{
    srand(time(0));
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

    queue<book> b;
    genreType g[1];
    g[0] = CHILD;
    book b1("Maurice Sendak", "Where the Wild things are", 
    "Monsters", "Harper & Row", "0-06-025492-0", g, 1);
    genreType g1[2];
    g1[0] = FANTASY;
    g1[1] = SCIFI;
    book b2("Madeleine L'Engle", "A Wrinkle in Time", 
    "Timey Wimey Stuff", "Ariel Books", "9780582151840", g1, 1);

    for(int i = 0; i < 100; i++)
    {
        int x = rand() % 1000 + 1;
        if(x % 2 == 0)
        {
            std::cout << "Adding book 1" << std::endl;
            b.enqueue(b1);
        }
        else if(x % 3 == 0)
        {
            std::cout << "Adding book 2" << std::endl;
            b.enqueue(b2);
        }
        else 
        {
            std::cout << "Removing book from queue: " << std::endl;
            std::cout << b.dequeue() << std::endl;
        }
    }

    return 0;

}