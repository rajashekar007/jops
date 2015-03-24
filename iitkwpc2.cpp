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
		map<ll,int> ans;
		map<ll,int>::iterator it;
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
			ans[1]=1;
			if(!isprime(n))
			{
				ans[n]=1;
			}
			for(i=2;i*i<=n;i++)
			{
				if(n%i==0)
				{
					if(!isprime(i))
					{
						ans[i]=1;
					}
					if(!isprime(n/i))
					{
						ans[n/i]=1;
					}
				}
			}
			printf("%d ", ans.size());
			for(it=ans.begin();it!=ans.end();it++)
			{
				printf("%lld ", it->first);
			}
			printf("\n");
		}
	}
}