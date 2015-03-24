#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t,ti;
	scanf("%d",&t);
	for(ti=1;ti<=t;ti++)
	{
		int n,i,tp;
		scanf("%d",&n);
		if(n>0)
		{
			long long dp[n],a[n];
			for(i=0;i<n;i++)
			{
				scanf("%d",&tp);
				a[i]=tp;
			}
			dp[0]=a[0];
			if(n>1)
				dp[1]=max(dp[0],a[1]);
			for(i=2;i<n;i++)
				dp[i]=max(dp[i-1],dp[i-2]+a[i]);
			printf("Case %d: %lld\n",ti, dp[n-1]);
		}
		else
			printf("Case %d: %d\n",ti, 0);
	}
	return 0;
}