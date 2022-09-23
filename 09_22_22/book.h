#ifndef BOOK_H
#define BOOK_H
#include <string>
#include <iostream>
#include <iomanip>

using std::string;

enum genreType {NONFICTION, FICTION, SCIFI, FANTASY, CHILD, BIO, AUTOBIO, HORROR, HISTORICAL};

const std::string genreStr[9] = {"Non-Fiction", "Fiction", 
"Science Fiction", "Fantasy", "Children's Picture Book", "Biography", "Autobiography", "Horror", 
"Historical"};
const genreType genreInt[] = {NONFICTION, FICTION, SCIFI, FANTASY, CHILD, BIO, AUTOBIO, HORROR, HISTORICAL};

class book
{
public:
    book(string, string, string, string, string, genreType[], int);
    ~book();
    book(const book&);
    void addGenre(genreType);
    friend std::ostream& operator<<(std::ostream&, const book&);
    bool operator==(const book&);
    bool operator!=(const book&);
    string getTitle() const;

private:   
    std::string author;
    std::string title;
    std::string subject;
    std::string publisher;
    std::string isbn;
    genreType * genres;
    int numGenres;

};




#endif