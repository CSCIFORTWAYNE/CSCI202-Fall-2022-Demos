all: book.o
	g++ -pedantic-errors main.cpp book.o

book.o: book.cpp book.h
	g++ -pedantic-errors book.cpp -o book.o -c

clean:
	rm a.out