/*
 * PTSUMY.cpp
 *
 *  Created on: 8 paź 2013
 *      Author: kuba
 */

#include <iostream>
#include <cstdio>
using namespace std;

string to_string(int i)
{
	char str[2];
	sprintf(str, "%d", i);
	return string(str);
}

void spare(string s, int l, int min)
{
	for (int i = min ; i <= l/2; i++)
	{
		spare(s + to_string(i) + " ",l-i,i);
	}
	s = s + to_string(l);
	cout << s << "\n";
}

int main_PTSUMY()
{
	int n,m;
	cin >> n;
	string out = "";
	for (int i = 0; i < n ; i++)
	{
		cin >> m;
		spare(out, m, 1);
	}
	return 0;
}
