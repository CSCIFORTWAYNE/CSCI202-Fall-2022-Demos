/* Program name: jbtictactoe.cpp
*  Author: John Doe
*  Date last updated: 5/1/2017
* Purpose: Play the game of Tic-Tac-Toe
*/

#include "linkedStack.h"
#include <iostream>
#include <string>
#include <stdexcept>
#include <cmath>


using namespace std;

void getNumber(linkedStackType<int>&, int&);
void convertNumber(linkedStackType<int>&, int&);

/*This is comment with no spaces around the begin/end comment*/

int main()
{
	linkedStackType<int> binaryNum;//comment is here but did you find it?
	int num;
	getNumber(binaryNum, num);
	cout << num << " converted to decimal is ";
	convertNumber(binaryNum, num);
	cout << num << endl;
	
	return 0;
}

void getNumber(linkedStackType<int>& stack, int& numCpy)
{
	int num = 0;
	numCpy = 0;
	linkedStackType<int> stack2;
	cout << "Enter a binary number to convert: ";
	cin >> num;
	
		
	while(!cin)
	{
		if(!cin)
		{
			cin.clear();
			cin.ignore(1000, '\n');
		}
		cout << "That is not a valid binary number.  Binary numbers are made up of only 1s and 0s." << endl;
		cin >> num;
	}
	cout << endl;
	numCpy = num;
	try {
	do 
	{
		if(num%10 != 1 && num%10 != 0)
			throw logic_error("The number entered contains digits that are not 1s and 0s.");
		stack2.push(num%10);
		//cout << num%10 << endl;
		num/=10;
		
	}while(num> 0);
	} catch(logic_error e) {
		cout << e.what() << endl;
		getNumber(stack, numCpy);
	}
	while(!stack2.isEmptyStack())
	{
		stack.push(stack2.top());
		stack2.pop();
	}
	
	
}
/***This comment is found before a function and has extra ***/

void convertNumber(linkedStackType<int>& stack, int& num)
{
	num = 0;
	for(int i = 0; !stack.isEmptyStack(); i++)
	{
		num += pow(2,i) * stack.top();
		//cout << pow(2,i) * stack.top() << endl;
		stack.pop();
	}
}