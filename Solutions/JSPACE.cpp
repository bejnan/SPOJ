#include <iostream>

using namespace std;

const int TO_UPPER = 'a' - 'A';

int main_JSPACE() {
	istreambuf_iterator<char> eos;
	string input(istreambuf_iterator<char>(cin), eos);
	string output;
	bool makeBig = false;
	char replacement;
	for (int i = 0; i < input.length(); i++) {
		replacement = input[i];
		if (input[i] == ' ') {
			makeBig = true;
		} else {
			if (makeBig && input[i] > 96 && input[i] < 123)
				replacement -= TO_UPPER;
			output += replacement;
			makeBig = false;
		}

	}
	cout << output;
	return 0;
}
