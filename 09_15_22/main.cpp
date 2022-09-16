#include <iostream>
#include "stackType.h"
#include "book.h"



int main()
{
    stackType<book> books(1);
    genreType g[1];
    g[0] = CHILD;
    book b("Maurice Sendak", "Where the Wild things are", 
    "Monsters", "Harper & Row", "0-06-025492-0", g, 1);
    books.push(b);
    std::cout << books.top() << std::endl;
    genreType g1[2];
    g[0] = FANTASY;
    g[1] = SCIFI;
    book b1("Madeleine L'Engle", "A Wrinkle in Time", 
    "Timey Wimey Stuff", "Ariel Books", "9780582151840", g, 1);
    try
    {
    books.push(b1);
    std::cout << books.top() << std::endl;
    book x = books.pop();
    x.addGenre(FICTION);

    std::cout  << x << std::endl;
    std::cout << books.top() << std::endl;
    } 
    catch(std::overflow_error e)
    {
        std::cout << e.what() << std::endl;
    }


    return 0;
    
}

