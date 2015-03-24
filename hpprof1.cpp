#include <bits/stdc++.h>
using namespace std;
char a[25];
int ans,n;
int main()
{
	scanf("%s",a);
	n=strlen(a);
	// permute(0);
	int dp[25]={};
	if(n<=1)
		printf("%d\n",n);
	else
	{
		dp[0]=1;
		if((a[0]-48)!=0 && (a[0]-48)*10+(a[1]-48)<=20)
			dp[1]=2;
		else
			dp[1]=1;
		for(int i=2;i<n;i++)
		{
			dp[i]=dp[i-1];
			if((a[i-1]-48)!=0 && (a[i-1]-48)*10+(a[i]-48)<=20)
				dp[i]+=dp[i-2];
		}

	}
	printf("%d\n", dp[n-1]);
	return 0;
}