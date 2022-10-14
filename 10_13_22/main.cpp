#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include <string>
#include "searchSort.h"
#include "customer.h"



const int ARRAY = 10;

void printResult(int index, int searchTerm, int comp);
int getInt(std::string, bool (*func)(int, int , int), int, int);
int fibNum(int, int, int, int[]);
void moveDisks(int, char source, char destination, char spare);
void insertCustomer(unorderedLinkedList<customer>&, ifstream&);
int compareCustomerByName(customer&, customer&);
int compareCustomerById(customer&, customer&);

bool intGreaterThan0(int, int, int);
bool intInRange(int n, int lower, int upper);

int main()
{
    int firstNum, secondNum;
    int n;
    int * sequence;

    firstNum = getInt("Enter the first Fibonacci number:", intInRange, 0, 10);
    secondNum = getInt("Enter the second Fibonacci number:", intInRange, firstNum+1, firstNum+10);
    n = getInt("Enter the number of Fibonacci numbers to generate:", intGreaterThan0, 0, 0);

    sequence = new int[n];
    sequence[0] = firstNum;
    sequence[1] = secondNum;
    for(int i = 2; i < n; i++)
    {
        sequence[i] = 0;
    }
    fibNum(firstNum, secondNum, n, sequence);

    for(int i = 0; i < n; i++)
    {
        std::cout << sequence[i] << " ";
    }
    std::cout << std::endl;

    moveDisks(8, 'A', 'C', 'B');
    std::cout << std::endl << std::endl;

    std::ifstream in("input.txt");
    unorderedLinkedList<customer> customers;
    while(!in.eof())
    {
        insertCustomer(customers, in);
    }
    
    std::cout << customers.print() << std::endl;
    quickSort(customers, 0, customers.length() - 1, compareCustomerByName);
    std::cout << customers.print() << std::endl;
    quickSort(customers, 0, customers.length() - 1, compareCustomerById);
    std::cout << customers.print() << std::endl;

    return 0;
}

int fibNum(int first, int second, int n, int seq[])
{
    if(n == 1)
    {
        return first;
    }
    else if (n == 2)
    {
        return second;
    }
    else
    {
        if(seq[n-1] == 0)
        {
            seq[n-1] = fibNum(first, second, n-1, seq) + fibNum(first, second, n-2, seq);
        }
        return seq[n-1];
    }
}

void moveDisks(int count, char source, char destination, char spare)
{
    if(count > 0)
    {
        moveDisks(count - 1, source, spare, destination);
        std::cout << "Move disk " << count << " from " 
        << source << " to " << destination << "." << std::endl;
        moveDisks(count-1, spare, destination, source);
    }
}

void printResult(int index, int searchTerm, int comp)
{
    if(index == -1)
    {
        std::cout << searchTerm << " is not in the list." << std::endl;
    }
    else
    {
        std::cout << searchTerm << " is found at " << index << std::endl;
    }

    std::cout << comp << " comparsions performed." << std::endl;
}

int getInt(std::string prompt, bool (*func)(int, int , int), int lower, int upper)
{
    int x;
    std::cout << prompt << " ";
    std::cin >> x;
    if(std::cin && func(x, lower, upper))
    {
        return x;
    } else if(!cin)
    {
        std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		std::cout << "You entered something that is not a number." << std::endl;
    }
    x = getInt(prompt, func, lower, upper);
    
    return x;
}

bool intGreaterThan0(int x, int, int)
{
    if(x < 0)
        std::cout << "The number must be greater than 0" << std::endl;
    return x > 0;
}
bool intInRange(int n, int lower, int upper)
{
    if(n  < lower || n > upper)
        std::cout << "The number should be between " << lower << " and " << upper << std::endl;
    return n >= lower && n <= upper; 
}

void insertCustomer(unorderedLinkedList<customer>& list, ifstream& in)
{
	int id;
	std::string name, address, phone, temp;
	customer * x;
	//cout << "Enter the customer id: ";
	in >> id;
	getline(in >> ws, name);
	getline(in >> ws, temp);
	address = temp;
	getline(in >> ws, temp);
	address = address + "\n" + temp;
	getline(in >> ws, phone);
	x = new customer(id, name, address, phone);
	list.insert(*x);
	delete x;
}

int compareCustomerByName(customer& c1, customer& c2)
{
    if(c1.getName() == c2.getName())
    {
        return 0;
    }
    else if(c1.getName() > c2.getName())
    {
        return 1;
    }
    else if(c1.getName() < c2.getName())
    {
        return -1;
    }

    return 0;
    
}

int compareCustomerById(customer& c1, customer& c2)
{
    if(c1.getId() == c2.getId())
    {
        return 0;
    }
    else if(c1.getId() > c2.getId())
    {
        return 1;
    }
    else if(c1.getId() < c2.getId())
    {
        return -1;
    }

    return 0;
}