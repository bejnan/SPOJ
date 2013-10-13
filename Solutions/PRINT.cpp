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
	const static int tens[];
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

		for (int j = 0; j < 10; j++) {
			if ((l / tens[j]) > 0) {
				i = head + 9 - j;
				do {
					buf[i--] = l % 10 + '0';
				} while ((l /= 10) > 0);
				head += 11 - j;
				buf[head - 1] = ' ';
				break;
			}
		}
		if (i == 0) {
			buf[head++] = l + '0';
			buf[head++] = ' ';
		}
	}

	inline void endline() {
		buf[head++] = '\n';
	}
};

const int writer::tens[] = { 1000000000, 100000000, 10000000, 1000000, 100000,
		10000, 1000, 100, 10, 1 };
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
	inline void read_int(unsigned int &x) {
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

short eratostenes[1000002];
int main() {


	unsigned int t, l1, l2;

	double l2_sqrt;
	reader r;
	writer w;
	r.read_int(t);
	get_primes();
	REP(m,t)
	{
		r.read_int(l1);
		r.read_int(l2);

		memset(eratostenes, 0, sizeof(eratostenes));

		l2_sqrt = sqrt(l2);

		for (int i = 0; primes[i] < l2_sqrt; i++) {
			FOR(j,l1,l2)
			{
				if (j % primes[i] == 0) {
					if (j != primes[i]) {
						eratostenes[j - l1] = 1;
					}
					for (unsigned int k = primes[i]; k <= l2 - j; k += primes[i]) {
						eratostenes[j + k - l1] = 1;
					}
					break;
				}
			}
		}
		FOR(j,l1,l2)
		{
			if (eratostenes[j - l1] == 0) {
				w.put_int(j);
				w.endline();
			}
		}
	}
	w.flow();
	return 0;
}
