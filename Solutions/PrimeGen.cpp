// 11 paź 2013
// Jakub Banaszewski
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define REP(i,n) for(int i=0;i<(n);i++)
#include<iostream>
const int LIMIT=65537;
using namespace std;
bool numbers[LIMIT+1];
int main_primeGen()
{
	REP(i,LIMIT)
			numbers[i]=true;
	FOR(i,2,LIMIT)
	{
		if (numbers[i])
		{
			cout << i << ","<< "\n";
			for(int j=i+i;j<=LIMIT;j+=i)
				numbers[j] = false;
		}
	}
	return 0;
}
