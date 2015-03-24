#include <bits/stdc++.h>
using namespace std;
#define limit 100007
vector<int> primes;
int sieve[limit];
void gen_primes()
{
	int i,up_bound=(int)sqrt((double)limit),j;
	primes.push_back(2);
	for(i=3;i<=up_bound;i+=2)
	{
		if(sieve[i]==0)
		{
			primes.push_back(i);
			for(j=i*i;j<limit;j+=2*i)
				sieve[j]=1;
		}
	}
	for(;i<limit;i+=2)
	{
		if(sieve[i]==0)
			primes.push_back(i);
	}
}
int main()
{
	gen_primes();
	return 0;
}