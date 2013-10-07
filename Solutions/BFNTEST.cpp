// 7 paź 2013
// Jakub Banaszewski

#include<iostream>

using namespace std;
enum state{
	normal = 0, short_comment, long_comment, text
};

int main() {
	istreambuf_iterator<char> eos;
	string input(istreambuf_iterator<char>(cin), eos);
	string output;
	state read_state;
	int length = input.length();
	char replacement;
	for (int i = 0; i < length; i++)
	{
		replacement = input[i];
		if (read_state == normal && input[i] == '"')
		{
			read_state = text;
			output += replacement;
		}
		else if (read_state == text && input[i] == '"')
		{
			read_state = normal;
			output += replacement;
		}
		else if (input[i] == '/' && read_state==normal)
		{
			if (i < length - 1 )
			{
				if (input[i+1] == '/')
				{
					read_state = short_comment;
					i++;
				}
				else if (input[i+1] == '*')
				{
					read_state = long_comment;
					i++;
				}
				else
				{
					output += replacement;
				}
			}
			else
			{
				output += replacement;
			}
		}
		else if (read_state == short_comment && input[i]== '\n')
		{
			read_state = normal;
			output += replacement;
		}
		else if (read_state == long_comment && input[i] == '*')
		{
			if (i < length - 1 )
			{
				if (input[i+1] == '/')
				{
					read_state = normal;
					i++;
				}
			}
		}
		else if (read_state == normal || read_state == text)
		{
			output += replacement;
		}
	}
	cout << output;
	return 0;
}
