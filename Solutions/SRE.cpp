// 7 paź 2013
// Jakub Banaszewski

#include<iostream>
#include<cmath>

using namespace std;

int main_SRE() {
	int numbers[1001];
	int sum;
	double min;
	int n, m, l, medNum;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> m;
		sum = 0;
		min = 200;
		medNum = 0;
		for (int j = 0; j < m; j++) {
			cin >> l;
			numbers[j] = l;
			sum += l;
		}
		for (int j = 0; j < m; j++) {
			if (abs(numbers[j] - double(sum)/m) < min) {
				min = abs(numbers[j] - double(sum)/m);
				medNum = numbers[j];
			}
		}
		if (m > 0)
			cout << medNum << "\n";
	}
	return 0;
}
