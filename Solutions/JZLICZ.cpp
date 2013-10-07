#include<iostream>

using namespace std;

int main_JZLICZ() {
	istreambuf_iterator<char> eos;
	string input(istreambuf_iterator<char>(cin), eos);

	int chars[128];
	for (int i = 0; i < 128; i++)
		chars[i] = 0;

	for (int i = 0; i < input.length(); i++) {
		chars[int(input[i])]++;
	}

	for (short s = 'a'; s <= 'z'; s++) {
		if (chars[s] > 0)
			cout << char(s) << ' ' << chars[s] << '\n';
	}

	for (short s = 'A'; s <= 'Z'; s++) {
		if (chars[s] > 0)
			cout << char(s) << ' ' << chars[s] << '\n';
	}

}
