//7 paź 2013
// Jakub Banaszewski

#include<iostream>

using namespace std;

int main_JHTMLLET()
{
	istreambuf_iterator<char> eos;
	string input(istreambuf_iterator<char>(cin), eos);
	string output;

	bool makeBig = false;
	char replacement;

	for (int i = 0; i < input.length(); i++)
	{
		replacement = input[i];
		if (input[i] == '<')
			makeBig= true;
		if (input[i] == '>')
			makeBig = false;
		if (makeBig && replacement >= 'a' && replacement <= 'z')
		{
			replacement = replacement - 'a' + 'A';
		}
		output += replacement;
	}

	cout <<output;
	return 0;
}
