#include<iostream>

using namespace std;

int euclid(int l1, int l2) {
	if (l1 < l2) {
		int swap = l1;
		l1 = l2;
		l2 = swap;
	}
	if (l2 == 0)
		return l1;
	return euclid(l2, l1 - l2);
}

int main_NWD() {
	int n;
	cin >> n;

	int l1, l2;
	for (int i = 0; i < n; i++) {
		cin >> l1 >> l2;
		cout << euclid(l1, l2) << "\n";
	}
	return 0;
}
