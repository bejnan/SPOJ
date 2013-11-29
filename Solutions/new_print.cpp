// 13 paź 2013
// Jakub Banaszewski
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define RREP(i,n) for(register int i=0;i<(n);i++)
#define REP(i,n) for(int i=0;i<(n);i++)

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>

typedef unsigned int uint;
using namespace std;

const int LIMIT = 31251;
unsigned int eratostenes_bits[LIMIT];
const int PRIMES_COUNT = 6543;
const int MAX_PRIME = 65537;
int primes[PRIMES_COUNT];

const uint small_primes[11] = { 0xAAAAAAAA, //2
		0x92492492, //3
		0x84210842, //5
		0x80808080, //7
		0x80100200, //11
		0x80040020, //13
		0x80004000, //17
		0x80001000, //19
		0x80000100, //23
		0x80000004, //29
		0x80000001  //31
		};

inline int NumberOfSetBits(register unsigned int i) {
	i = i - ((i >> 1) & 0x55555555);
	i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
	return (((i + (i >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24;
}

inline int nearest_prime_pos(int n) {
	int p = 0, k = PRIMES_COUNT-1;
	while (p != k) {
		if (primes[(p + k) / 2] == n)
			return (p + k) / 2;
		if (primes[(p + k) / 2] > n) {
			k = (p + k) / 2;
		} else
			p = (p + k) / 2 + 1;
	}
	return p;
}

inline int runEratostenes(int lp, int lk) {
	int counter = 0;
	if (lp <= MAX_PRIME) {
		int pos = nearest_prime_pos(lp);
		if (primes[pos] < lp)
			pos++;
		if (lk <= MAX_PRIME) {
			int pos_k = nearest_prime_pos(lk);
			if (primes[pos_k] > lk)
				pos_k--;
			return pos_k - pos + 1;
		}
		lp = MAX_PRIME + 1;
		counter += PRIMES_COUNT - pos;
	}
	const int iterationLimit = ((lk - lp) >> 5) + 1;
	uint bit_mask;
	int iter_count;
	for (iter_count = 0; iter_count < iterationLimit; iter_count++) {
		for (short s = 0; s < 11; s++) {
			bit_mask = small_primes[s]
					>> ((primes[s] - (lp + 32 * iter_count) % primes[s]) % primes[s]);
			eratostenes_bits[iter_count] |= bit_mask;
		}
	}
	const int sqrt_lk = sqrt(lk);
	int next_bit = 0;
	//TODO gdzieś tutaj czai się robaczek...
	for (int i = 11; primes[i] <= sqrt_lk; i++) {
		next_bit = primes[i] - (lp % primes[i] == 0) ? primes[i] : lp % primes[i];
		iter_count = next_bit / 32;
		while(iter_count < iterationLimit)
		{
			next_bit %= 32;
			eratostenes_bits[iter_count] |= 1 << (31 - next_bit);
			iter_count++;
			next_bit = primes[i] - (((lp + 32*iter_count) % primes[i])== 0) ?
					primes[i] : (lp + 32*iter_count) % primes[i];
			iter_count += next_bit / 32;
		}
	}
	bit_mask = ~0;
	bit_mask = bit_mask >> ((lk - lp) % 32 + 1);
	eratostenes_bits[iterationLimit - 1] |= bit_mask;
	for (iter_count = 0; iter_count < iterationLimit; iter_count++) {
		counter += 32 - NumberOfSetBits(eratostenes_bits[iter_count]);
		//cout << iter_count << " " << 32 - NumberOfSetBits(eratostenes_bits[iter_count]) << "\n";
	}
	return counter;
}

void clearSieve() {
	memset(eratostenes_bits, 0, sizeof(eratostenes_bits));
}

void get_primes() {
	int primes_count = 0;
	bool numbers[MAX_PRIME + 1];
	REP(i,MAX_PRIME+1)
		numbers[i] = true;
	FOR(i,2,MAX_PRIME)
	{
		if (numbers[i]) {
			primes[primes_count++] = i;
			for (int j = i + i; j < MAX_PRIME; j += i)
				numbers[j] = false;
		}
	}
}
int main() {
	int t, lp, lk;
	get_primes();
	cin >> t;
	REP(i,t)
	{
		cin >> lp >> lk;
		cout << runEratostenes(lp, lk) << "\n";
		clearSieve();
	}
	return 0;
}
