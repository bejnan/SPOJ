#include<iostream>
#include<sstream>
#include<stack>

using namespace std;

int stringToInt(string s) {
	int num = 0;
	stringstream ss(s);
	ss >> num;
	return num;
}
int main_STOS() {
	stack<int> stos;
	string input;
	int num = 0;
	while (cin >> input) {
		if (input[0] == '-') {
			if (stos.empty()) {
				cout << ":(\n";
			}
			else
			{
				cout << stos.top() << "\n";
				stos.pop();
			}
		} else if (input[0] != '+'){
			num = stringToInt(input);
			if (stos.size() > 9)
				cout << ":(\n";
			else {
				stos.push(num);
				cout << ":)\n";
			}
		}
	}
	return 0;

}
