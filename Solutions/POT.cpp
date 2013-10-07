#include <iostream>

using namespace std;

int pot(int l1, int l2) {
	if (l1 % 10 == 1 || l2 == 0)
		return 1;
	if (l1 % 10 == 0)
		return 0;
	if (l1 % 10 == 2) {
		switch (l2 % 4) {
		case 0:
			return 6;
		case 1:
			return 2;
		case 2:
			return 4;
		case 3:
			return 8;
		}
	}
	if (l1 % 10 == 3) {
		switch (l2 % 4) {
		case 0:
			return 1;
		case 1:
			return 3;
		case 2:
			return 9;
		case 3:
			return 7;
		}
	}
	if (l1 % 10 == 4) {
		if (l2 % 2 == 0)
			return 6;
		else
			return 4;
	}
	if (l1 % 10 == 5)
		return 5;
	if (l1 % 10 == 6) {
		return 6;
	}
	if (l1 % 10 == 7) {
		switch (l2 % 4) {
		case 0:
			return 1;
		case 1:
			return 7;
		case 2:
			return 9;
		case 3:
			return 3;
		}
	}
	if (l1 % 10 == 8) {
		switch (l2 % 4) {
		case 0:
			return 6;
		case 1:
			return 8;
		case 2:
			return 4;
		case 3:
			return 2;
		}
	}
	if (l1 % 10 == 9) {
		if (l2 % 2  == 0)
			return 1;
		else return 9;
	}
	return 1;
}

int main() {
	int n, l1, l2;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> l1 >> l2;
		cout << pot(l1, l2) << "\n";
	}
	return 0;
}
