// 8 paź 2013
// Jakub Banaszewski
#include<iostream>

using namespace std;

int char_to_value(char c) {
	if (c == 'I')
		return 1;
	if (c == 'V')
		return 5;
	if (c == 'X')
		return 10;
	if (c == 'L')
		return 50;
	if (c == 'C')
		return 100;
	if (c == 'D')
		return 500;
	if (c == 'M')
		return 1000;
	return 0;
}
int char_to_num(char last, char act, int sum) {
	if (act == ' ' || act == '\n')
		return sum + char_to_value(last);
	if (char_to_value(last) < char_to_value(act))
		return sum - char_to_value(last);
	else
		return sum + char_to_value(last);
}

char inc_num(int power) {
	if (power == 0)
		return 'I';
	if (power == 1)
		return 'X';
	if (power == 2)
		return 'C';
	return ' ';
}


string digitToRom(int digit, int power)
{
	if (digit == 0)
		return "";
	string ans= "";
	if (power == 0)
	{
		if (digit < 4)
			while (digit > 0)
			{
				ans +="I";
				--digit;
			}
		else if (digit < 9)
			ans += "V" + digitToRom(digit - 5,0);
	}
	if (power == 1)
	{
		if (digit < 4)
					while (digit > 0)
					{
						ans +="X";
						--digit;
					}
				else if (digit < 9)
					ans += "L" + digitToRom(digit - 5,1);
	}
	if (power == 2)
	{
		if (digit < 4)
					while (digit > 0)
					{
						ans +="C";
						--digit;
					}
				else if (digit < 9)
					ans += "D" + digitToRom(digit - 5,2);
	}
	if (power == 3)
	{
		while (digit > 0)
				{
					ans +="M";
					--digit;
				}

	}
	return ans;
}
string numToRom(int sum) {
	if (sum == 0)
		return "";
	string ans = "";
	int p = sum;
	int l = 0;
	int pow= 1;
	while (p > 9) {
		l++;
		p /= 10;
		pow *= 10;
	}
	char c=' ';
	if ((l < 3) && (p == 9 || p == 4)) {
		c = inc_num(l);
		return ans = ans + c + numToRom(sum + char_to_value(c));
	}
	else
	{
		return digitToRom(p,l) + numToRom(sum-p*pow);
	}

}

int main_JSUMRZYM() {
	string input;
	int sum = 0;
	int count = 1;
	while (cin >> input) {
		for (int i = 1; i < input.length(); i++) {
			sum = char_to_num(input[i - 1], input[i], sum);
		}
		sum = char_to_num(input[input.length() - 1], ' ', sum);
		if (count == 2) {
			cout << numToRom(sum) << "\n";
			sum = 0;
			count = 0;
		}
		++count;
	}
	return 0;
}
