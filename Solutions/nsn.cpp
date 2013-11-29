// 22 lis 2013
// Jakub Banaszewski
#include<iostream>

using namespace std;
long tab[1025];
const int pot[11] = {1,2,4,8,16,32,64,128,256,512,1024};
int nsn_main()
{
	for (int i = 0; i <= 10; i++ )
	{
		++tab[pot[i]];
		for (int k = 1; k < 1025; k++)
		{
				if (tab[k] > 0 && (k+pot[i] < 1025)) tab[k+pot[i]]+=tab[k];
		}
	}
	for (int i = 0; i <= 10; i++)
	{
		cout << i << " " << tab[pot[i]] << "\n";
	}
	return 0;
}
