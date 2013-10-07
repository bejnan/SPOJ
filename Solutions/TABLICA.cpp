/*
 * TABLICA.cpp
 *
 *  Created on: 7 paź 2013
 *      Author: kuba
 */

#include<iostream>
#include<stack>
using namespace std;

int main_TABLICA()
{
	stack<int> numbers;
	int number;
	while(cin >> number )
	{
		numbers.push(number);
	}
	while(!numbers.empty())
	{
		cout << numbers.top() << " ";
		numbers.pop();
	}
	return 0;
}
