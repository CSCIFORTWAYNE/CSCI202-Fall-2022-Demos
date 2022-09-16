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
    this->numGenres = numGenres;
}


book::~book()
{
    //cout << "Cleaning up " << title << endl;
    delete [] genres;
}


void book::addGenre(genreType g) 
{
    //increment the numGenres
    numGenres++;
    //make new array
    genreType * old = genres;
    genres = new genreType[numGenres];
    //copy from old to new
    for(int i = 0; i < numGenres -1;i++)
    {
        genres[i] = old[i];
    }
    //delete old array
    delete [] old;
    //add new item to new
    genres[numGenres - 1] = g;
    
}

std::ostream& operator<<(std::ostream& out, const book& b)
{
    out << "Title: " << b.title << std::endl;
    out << "Author: " << b.author << std::endl;
    out << "Genre: ";
    for (int i = 0; i < b.numGenres - 1; i++)
    {
        out << genreStr[b.genres[i]] << ", ";
    }
    out << genreStr[b.genres[b.numGenres - 1]] << std::endl;
    out << std::setw(40) << std::setfill('-') << "-" << std::endl;
    return out;
}