// 9 paź 2013
// Jakub Banaszewski

#define REP(i,n) for(int i=0;i<(n);i++)
#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
#include<algorithm>

using namespace std;

const int buf_size = 50000;
const int char_size = 1;
class reader {
public:
	char buf2[buf_size];
	int head, tail;
	bool endOfFile;
	reader() :
			head(0), tail(0), endOfFile(false) {
	}

	inline void get_chars() {
		int count = fread(buf2, char_size, buf_size, stdin);
		head = 0;
		tail = count;
		if (count == 0) {
			endOfFile = true;
		}
	}
	inline void read(int &x) {
		char z;
		x = 0;
		do {
			if (head == tail)
				get_chars();
			z = buf2[head++];
		} while (z < '0');
		if (tail - head < 9)
			do {
				x = x * 10 + (z - '0');
				if (head == tail)
					get_chars();
				z = buf2[head++];
			} while (z >= '0');
		else {
			do {
				x = x * 10 + (z - '0');
				z = buf2[head++];
			} while (z >= '0');
		}
	}
	inline void read(string &s) {
		char z;
		s = "";
		if (endOfFile)
			return;
		do {
			if (head == tail)
				get_chars();
			z = buf2[head++];
		} while (z < '0');
		do {
			s += z;
			if (head == tail)
				get_chars();
			z = buf2[head++];
		} while (z >= '0');
	}
	inline void check() {
		char z;
		if (buf2[head] >= '0' || endOfFile)
			return;
		do {
			if (head == tail)
				get_chars();
			z = buf2[head++];
		} while (z < '0' && !endOfFile);
	}
};

bool fnamesCompare(pair<string, int> fn1, pair<string, int> fn2) {
	if (fn1.second == fn2.second)
		return fn1.first < fn2.first;
	return fn1.second > fn2.second;
}
string makeBig(string s) {
	REP(i,s.length())
	{
		if (s[i] >= 'a' && s[i] <= 'z')
			s[i] -= 'a' - 'A';
	}
	return s;
}
int main() {
	string numer, name, fname;
	map<string, int> fnames;
	reader r;
	do {
		r.read(numer);
		r.read(name);
		r.read(fname);
		if (numer == "" || name == "" || fname == "")
			break;
		fname = makeBig(fname);
		if (fnames.find(fname) == fnames.end()) {
			fnames[fname] = 1;
		} else {
			fnames[fname] += 1;
		}
		r.check();
	} while (!r.endOfFile);
	vector<pair<string, int> > sortFnames;
	map<string, int>::iterator it;
	for (it = fnames.begin(); it != fnames.end(); it++) {
		sortFnames.push_back(make_pair((*it).first, (*it).second));
	}
	sort(sortFnames.begin(), sortFnames.end(), fnamesCompare);
	REP(i,sortFnames.size())
	{
		cout << sortFnames[i].first << " " << sortFnames[i].second << "\n";
	}
	return 0;
}
