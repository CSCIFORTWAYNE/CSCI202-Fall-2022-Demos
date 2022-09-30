all: card.o
	g++ -pedantic-errors -g main.cpp card.o -o a.out
card.o: card.h card.cpp
	g++ -pedantic-errors -g -c card.cpp -o card.o
clean:
	rm a.out