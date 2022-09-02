all: book.o
	g++ -pedantic-errors main.cpp book.o -g

book.o: book.cpp book.h
	g++ -pedantic-errors book.cpp -o book.o -c -g

clean:
	rm a.out