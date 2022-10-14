all: customer.o
	g++ -pedantic-errors -g main.cpp customer.o -o a.out
customer.o: customer.h customer.cpp
	g++ -pedantic-errors -g -c customer.cpp -o customer.o
clean:
	rm a.out