#include <bits/stdc++.h>
using namespace std;
#define limit 1000007
typedef long long ll;
int sieve[limit];
void gen_primes()
{
	int i,up_bound=(int)sqrt((double)limit),j;
	for(i=3;i<=up_bound;i+=2)
	{
		if(sieve[i]==0)
		{
			for(j=i*i;j<limit;j+=2*i)
				sieve[j]=1;
		}
	}

}
int main()
{
	gen_primes();
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ll n;
		scanf("%lld",&n);
		if(n%2)
			printf("0\n");
		else
		{
			n=n/2;
			int i;
			vector<ll> ans;
			for(i=1;(ll)i*i<=n;i++)
			{
				if((i%2==0 || sieve[i]==1) && n%i==0)
				{
					ans.push_back(i);
				}
				ll j=n/i;
				if((j%2==0))
					ans.push_back(j);
			}
			// sort(ans.begin(),ans.end());
			printf("%d\n", (int)ans.size());

		}
	}
	return 0;
}