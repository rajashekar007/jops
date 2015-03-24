#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
#define MOD 1000000007
ull pmod(int b,ull n)
{
	if(n==1)
		return b;
	else if(n==0)
		return 1;
	else
	{
		ull p=pmod(b,n/2);
		ull x=(p*p)%MOD;
		if (n%2)
			return (x*b)%MOD;
		else
			return x;
	}
}
int main()
{
	ull n;
	while(scanf("%lld",&n)!=EOF)
	{
		ull t=pmod(2,n);
		if(n%2)
			printf("%lld\n", ((t+1)*333333336)%MOD);
		else
			printf("%lld\n", ((t+2)*333333336)%MOD);
	}
}