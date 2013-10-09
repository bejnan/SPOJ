// 9 paź 2013
// Jakub Banaszewski

#define FOR(a,b) for(int i=(a);i<=(b);i++)
#define REP(n) for(int i=0;i<(n);i++)
#define LL long long

#include<iostream>
#include<vector>

using namespace std;

vector<int> pomnoz(vector<int> m1, vector<int> m2) {
	vector<int> ans(4);
	ans[0] = (m1[0] * m2[0] + m1[1] * m2[2]) % 10;
	ans[1] = (m1[0] * m2[1] + m1[1] * m2[3]) % 10;
	ans[2] = (m1[2] * m2[0] + m1[3] * m2[2]) % 10;
	ans[3] = (m1[2] * m2[1] + m1[3] * m2[3]) % 10;
	return ans;
}
vector<int> pomnoz(vector<int> m1, int n) {
	if (n == 1)
		return m1;
	if (n % 2 == 0) {
		return pomnoz(pomnoz(m1, m1), n / 2);
	} else {
		return pomnoz(pomnoz(m1, n - 1), m1);
	}
}
int main() {
	int t, n;
	LL l1, l2;
	cin >> t;
	vector<int> m1(4);
	REP(t)
	{
		cin >> n >> l1 >> l2;
		if (n == 0) {
			cout << 0 << "\n";
		}
		else if (n == 1) {
			cout << l1 % 10 << "\n";
		} else if (n == 2) {
			cout << l2 % 10 << "\n";
		} else {
			m1[0] = 1;
			m1[1] = 1;
			m1[2] = 1;
			m1[3] = 0;
			m1 = pomnoz(m1, n - 2);
			cout << (m1[0] * (l2 % 10) + m1[1] * (l1 % 10)) % 10 << "\n";
		}
	}
	return 0;
}
