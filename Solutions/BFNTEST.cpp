// 7 paź 2013
// Jakub Banaszewski

#include<iostream>

using namespace std;
enum state {
	normal = 0, maybe_comment, short_comment, long_comment, maybe_uncomment
};

int main_BFNTEST() {
	istreambuf_iterator<char> eos;
	string input(istreambuf_iterator<char>(cin), eos);
	string output;
	state read_state = normal;
	int length = input.length();
	char replacement;
	char last_replacement;
	for (int i = 0; i < length; i++) {
		replacement = input[i];
		switch (read_state) {

		case normal:
			if (replacement == '/') {
				read_state = maybe_comment;
				last_replacement = replacement;
			} else
				output += replacement;
			break;

		case maybe_comment:
			if (replacement == '/')
				read_state = short_comment;
			else if (replacement == '*')
				read_state = long_comment;
			else {
				read_state = normal;
				output = output + last_replacement + replacement;
			}
			break;

		case short_comment:
			if (replacement == '\n') {
				read_state = normal;
				output = output + replacement;
			}
			break;
		case long_comment:
			if (replacement == '*')
				read_state = maybe_uncomment;
			break;
		case maybe_uncomment:
			if (replacement == '/')
				read_state = normal;
			else
				read_state = long_comment;
			break;
		default:
			output += replacement;
			break;
		}
	}
	cout << output;
	return 0;
}
