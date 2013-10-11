// 11 paź 2013
// Jakub Banaszewski
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define REP(i,n) for(int i=0;i<(n);i++)

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
const int buf_size = 50000;
const int char_size = 1;

using namespace std;

class writer {
public:
	char buf[buf_size];
	int head;
	writer() :
			head(0) {
	}
	inline void flow() {
		fwrite(buf, char_size, head, stdout);
		head = 0;
	}
	inline void put_int(int l) {
		int i = 0;
		if (buf_size - head < 12)
			this->flow();

		if (l > 999999999) {
			i = head + 9;
			do {
				buf[i--] = l % 10 + '0';
			} while ((l /= 10) > 0);
			head += 11;
			buf[head - 1] = ' ';
		} else if (l > 99999999) {
			i = head + 8;
			do {
				buf[i--] = l % 10 + '0';
			} while ((l /= 10) > 0);
			head += 10;
			buf[head - 1] = ' ';
		} else if (l > 9999999) {
			i = head + 7;
			do {
				buf[i--] = l % 10 + '0';
			} while ((l /= 10) > 0);
			head += 9;
			buf[head - 1] = ' ';
		} else if (l > 999999) {
			i = head + 6;
			do {
				buf[i--] = l % 10 + '0';
			} while ((l /= 10) > 0);
			head += 8;
			buf[head - 1] = ' ';
		} else if (l > 99999) {
			i = head + 5;
			do {
				buf[i--] = l % 10 + '0';
			} while ((l /= 10) > 0);
			head += 7;
			buf[head - 1] = ' ';
		} else if (l > 9999) {
			i = head + 4;
			do {
				buf[i--] = l % 10 + '0';
			} while ((l /= 10) > 0);
			head += 6;
			buf[head - 1] = ' ';
		} else if (l > 999) {
			i = head + 3;
			do {
				buf[i--] = l % 10 + '0';
			} while ((l /= 10) > 0);
			head += 5;
			buf[head - 1] = ' ';
		} else if (l > 99) {
			i = head + 2;
			do {
				buf[i--] = l % 10 + '0';
			} while ((l /= 10) > 0);
			head += 4;
			buf[head - 1] = ' ';
		} else if (l > 9) {
			i = head + 1;
			do {
				buf[i--] = l % 10 + '0';
			} while ((l /= 10) > 0);
			head += 3;
			buf[head - 1] = ' ';
		} else {
			buf[head++] = l + '0';
			buf[head++] = ' ';
		}
	}
	inline void endline() {
		buf[head++] = '\n';
	}
};
class reader {
public:
	char buf2[buf_size];
	int head, tail;

	reader() :
			head(0), tail(0) {
	}

	inline void get_chars() {
		int count = fread(buf2, char_size, buf_size, stdin);
		head = 0;
		tail = count;
	}
	inline void read_int(int &x) {
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
};

const int PRIMES_COUNT = 6543;
const int MAX_PRIME = 65537;
int primes[PRIMES_COUNT];

void get_primes() {
	int primes_count = 0;
	bool numbers[MAX_PRIME + 1];
	REP(i,MAX_PRIME)
		numbers[i] = true;
	FOR(i,2,MAX_PRIME)
	{
		if (numbers[i]) {
			primes[primes_count++] = i;
			for (int j = i + i; j <= MAX_PRIME; j += i)
				numbers[j] = false;
		}
	}
}

short eratostenes[1000001];
int main() {
	int t, l1, l2, l3;
	double l2_sqrt;
	reader r;
	writer w;
	r.read_int(t);
	get_primes();
	REP(m,t)
	{
		memset(eratostenes, 0, sizeof(eratostenes));
		r.read_int(l1);
		r.read_int(l2);

		l3 = (l2 == 2147483647) ? l2 - 1 : l2;
		l2_sqrt = sqrt(l3);

		for (int i = 0; primes[i] < l2_sqrt; i++) {
			FOR(j,l1,l3)
			{
				if (j % primes[i] == 0) {
					if (j != primes[i]) {
						eratostenes[j - l1] = 1;
					}
					for (int k = primes[i]; k <= l2 - l1; k += primes[i]) {
						eratostenes[j + k - l1] = 1;
					}
					break;
				}
			}
		}
		FOR(j,l1,l3)
		{
			if (eratostenes[j - l1] == 0) {
				w.put_int(j);
				w.endline();
			}
		}
		if (l3 < l2) {
			w.put_int(l2);
			w.endline();
		}
	}
	w.flow();
	return 0;
}
