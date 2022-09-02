#include <iostream>
#include "book.h"
#include <vector>

using namespace std;


int main()
{
    book ** books;
    int numBooks;
    cout << "How many books do you want to enter? ";
    cin >> numBooks;
    cout << endl;

    books = new book*[numBooks];

    //input validation goes here 

    //int numBooks;
    for(int i = 0; i < numBooks; i++)
    {
        string author, title, subject, publisher, ISBN, genreSt;
        genreType * g = new genreType[1];
        int numGenres = 1;

        cout << "Enter the book author: ";
        getline(cin >> ws, author);
        cout << endl;

        cout << "Enter the book title: ";
        getline(cin >> ws, title);
        cout << endl;

        cout << "Enter a genre: ";
        getline(cin >> ws, genreSt);
        cout << endl;
        for(int j = 0; j < 9; j++)
        {
            if(genreSt == genreStr[j])
            {
                g[numGenres - 1] = genreInt[j];
                break;
            }
        }
        while(true)
        {
            char yesNo = ' ';
            cout << "Do you want to enter another genre: ";
            cin >> yesNo;
            cout << endl;
            if(tolower(yesNo) == 'n')
            {
                break;
            }
            numGenres++;
            genreType * old = g;
            g = new genreType[numGenres];
            for(int j = 0; j < numGenres - 1; j++)
            {
                g[j] = old[j];
            }
            cout << "Enter a genre: ";
            getline(cin >> ws, genreSt);
            cout << endl;
            for(int j = 0; j < 9; j++)
            {
                if(genreSt == genreStr[j])
                {
                    g[numGenres - 1] = genreInt[j];
                    break;
                }
            }
        }

        cout << "Enter the book subject: ";
        getline(cin >> ws, subject);
        cout << endl;
       
        cout << "Enter the book publisher: ";
        getline(cin >> ws, publisher);
        cout << endl;

        cout << "Enter the isbn: ";
        getline(cin >> ws, ISBN);
        cout << endl;


       books[i] = new book(author, title, subject, publisher, 
        ISBN, g, numGenres); //create the book using new
        //books[i]->addGenre(FICTION);
        cout << *books[i] << endl;
        
        //books.push_back(mybook);
    }

   // genreType g[1] = {CHILD};
   // book mybook("Maurice Sendak", "Where the Wild things are", "Monsters", "Harper & Row", 
 //   "0-06-025492-0", g, 1);
   /* mybook.author = ;
    mybook.title = ;
    mybook.publisher = ;
    mybook.isbn = ;
    mybook.genres = new genreType[1];
    mybook.genres[0] = CHILD;*/
    
    return 0;
}