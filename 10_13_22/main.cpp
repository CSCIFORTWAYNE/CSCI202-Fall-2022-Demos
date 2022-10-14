#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include <string>
#include "searchSort.h"
#include "customer.h"

//void insertCustomer(orderedLinkedList<customer>&);

const int ARRAY = 10;

void printResult(int index, int searchTerm, int comp);
int getInt(std::string);
int fibNum(int, int, int, int[]);
void moveDisks(int, char source, char destination, char spare);

int main()
{
    int firstNum, secondNum;
    int n;
    int * sequence;

    firstNum = getInt("Enter the first Fibonacci number:");
    secondNum = getInt("Enter the second Fibonacci number:");
    n = getInt("Enter the number of Fibonacci numbers to generate:");

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

int getInt(std::string prompt)
{
    int x;
    std::cout << prompt << " ";
    cin >> x;
    if(!cin)
    {
        cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "You entered something that is not a number." << endl;
        x = getInt(prompt);
    }
    return x;
}

/*void insertCustomer(orderedLinkedList<customer>& list)
{
	int id;
	string name, address, phone, temp;
	customer * x;
	cout << "Enter the customer id: ";
	cin >> id;
	while(!cin) 
	{
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "The customer id should be a whole number." << endl;
		cout << "Enter the customer id: ";
		cin >> id;
	}
	cout << endl;
	cout << "Enter the customer name (first and last): ";
	getline(cin >> ws, name);
	cout << endl;
	cout << "Enter " << name << "'s street address: ";
	getline(cin >> ws, temp);
	address = temp;
	cout << endl;
	cout << "Enter the city, state and zip code for the address: ";
	getline(cin >> ws, temp);
	address = address + "\n" + temp;
	cout << endl;
	cout << "Enter " << name << "'s phone number: ";
	getline(cin >> ws, phone);
	cout << endl;
	x = new customer(id, name, address, phone);
	list.insert(*x);
	delete x;
}*/