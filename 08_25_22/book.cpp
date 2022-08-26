#include "book.h"

book::book(string author, string title, string subject, 
    string publisher, string isbn, genreType genres[], int numGenres)
{
    this->author = author;
    this->title = title;
    this->subject = subject;
    this->publisher = publisher;
    this->isbn = isbn;
    this->genres = new genreType[numGenres];
    for(int i = 0; i < numGenres; i++)
    {
        this->genres[i] = genres[i];
    }
}


book::~book()
{
    //cout << "Cleaning up " << title << endl;
    delete [] genres;
}