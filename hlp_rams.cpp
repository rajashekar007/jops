#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll pr(ll n)
{
	ll ans=1;
	while (n)
	{
		ans*=((n&1)+1);
		n>>=1;
	}
	return ans;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ll n,k;
		scanf("%lld",&n);
		k=pr(n);
		printf("%lld %lld\n", n+1-k,k);
	}
	return 0;
}