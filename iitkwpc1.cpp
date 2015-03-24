#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int isprime(ll a)
{
	ll i;
	if(a==1)
		return 0;
	for(i=2;i*i<=a;i++)
	{
		if(a%i==0)
			return 0;
	}
	return 1;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ll n,i;
		list<ll> ans;
		list<ll>::iterator it;
		scanf("%lld",&n);
		if(n==0)
			printf("0 0\n");
		else if(n%2)
		{
			printf("0\n");
		}
		else
		{
			int sz=1;
			n=n/2;
			ans.push_back(1);
			it=ans.begin();
			if(!isprime(n))
			{
				ans.push_back(n);
				sz++;
			}
			it++;
			for(i=2;i*i<=n;i++)
			{
				if(n%i==0)
				{
					if(!isprime(i))
					{
						ans.insert(it,i);
						sz++;//printf("%lld\n", i);
					}
					if(!isprime(n/i))
					{
						ans.insert(it,n/i);
						it--;
						sz++;
					}
				}
			}
			printf("%d ", sz);
			for(it=ans.begin();it!=ans.end();it++)
			{
				printf("%lld ", *it);
			}
			printf("\n");
		}
	}
}