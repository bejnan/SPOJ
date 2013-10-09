// 8 paź 2013
// Jakub Banaszewski
#include<iostream>
#include<vector>
using namespace std;

vector<int> computePrefixFunction(string s) {
	vector<int> pref(s.length() + 1);
	pref[0] = 0;
	int k = 0;
	for (int q = 1; q < s.length(); q++) {
		while (k > 0 && s[k] != s[q]) {
			k = pref[k-1];
		}
		if (s[k] == s[q])
			k++;
		pref[q] = k;
	}
	return pref;
}

int kmp(string text, string subtext) {
	int resoult = 0;
	vector<int> prefixFunction = computePrefixFunction(subtext);
	int q = 0;
	for (int i = 0; i < text.length(); i++) {
		while (q > 0 && subtext[q] != text[i])
			q = prefixFunction[q-1];
		if (subtext[q] == text[i])
			q++;
		if (q == subtext.length()) {
			cout << i - q + 1 << "\n";
			resoult++;
			q = prefixFunction[q-1];
		}
	}
	return resoult;
}

int main_KMP() {
	int n, sublen;
	cin >> n;
	string text;
	string subtext;
	for (int i = 0; i < n; i++) {
		cin >> sublen;
		cin >> subtext;
		cin >> text;
		kmp(text, subtext);
	}
	return 0;
}
