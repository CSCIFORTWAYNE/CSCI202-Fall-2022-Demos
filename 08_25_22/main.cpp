#include <iostream>
#include "book.h"

using namespace std;


int main()
{
    genreType g[1] = {CHILD};
    book mybook("Maurice Sendak", "Where the Wild things are", "Monsters", "Harper & Row", 
    "0-06-025492-0", g, 1);
   /* mybook.author = ;
    mybook.title = ;
    mybook.publisher = ;
    mybook.isbn = ;
    mybook.genres = new genreType[1];
    mybook.genres[0] = CHILD;*/
    
    return 0;
}