#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		long long n,rn;
		scanf("%lld",&n);
		rn=(long long)sqrt(n);
		if(rn*rn==n)
			printf("Case %d: Yes\n", i);
		else
			printf("Case %d: No\n", i);
	}
	return 0;
}