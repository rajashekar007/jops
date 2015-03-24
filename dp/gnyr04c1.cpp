#include <bits/stdc++.h>
using namespace std;
#define N 11
#define M 2001
int n,m,cnt;
long long dp[N][M];
int main()
{
	int t,ti,i,j;
	scanf("%d",&t);
	for(i=1;i<N;i++)
		dp[i][1]=0;	
	for(i=1;i<M;i++)
		dp[1][i]=i;
	for(i=2;i<N;i++)
	{
		for(j=2<<(i-2);j<M;j++)
		{
			dp[i][j]=dp[i-1][j/2]+dp[i][j-1];
		}
	}
	for(ti=1;ti<=t;ti++)
	{
		scanf("%d%d",&n,&m);
		printf("Data set %d: %d %d %lld\n",ti,n,m,dp[n][m]);
	}
	return 0;
}