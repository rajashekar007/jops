#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,i,j,k;
		scanf("%d",&n);
		char c[509][509]={};
		for(i=0;i<n;i++)
			scanf("%s",c[i]);
		int dp[509][509]={};
		if(c[0][0]=='*')
			dp[0][0]=1;
		for(i=1;i<n;i++)
		{
			if(c[0][i]=='*')
				dp[0][i]=dp[0][i-1]+1;
			else if(c[0][i]=='#')
			{
				dp[0][i]=-1;
				for(i=i+1;i<n;i++)
					dp[0][i]=-1;
				break;
			}
			else
				dp[0][i]=dp[0][i-1];
		}
		for(j=1;j<n;j++)
		{
			if(c[j][0]=='*')
				dp[j][0]=dp[j-1][0]+1;
			else if(c[j][0]=='#')
			{
				dp[j][0]=-1;
				for(j=j+1;j<n;j++)
					dp[j][0]=-1;
				break;
			}
			else
				dp[j][0]=dp[j-1][0];
		}
		for(i=1;i<n;i++)
		{
			for(j=1;j<n;j++)
			{
				if(dp[i-1][j]==-1 && dp[i][j-1]==-1)
					dp[i][j]=-1;
				else if(c[i][j]=='*' && (c[i-1][j]!='#' || c[i][j-1]!='#'))
					dp[i][j]=max(dp[i-1][j],dp[i][j-1])+1;
				else if(c[i][j]=='#')
				{
					dp[i][j]=-1;
				}
				else
					dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
		printf("%d\n", dp[n-1][n-1]);
	}
	return 0;
}
