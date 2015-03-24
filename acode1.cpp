#include <stdio.h>
#include <string.h>
int main()
{
	while(1)
	{
		char a[5007]={};
		scanf("%s",a);
		if(a[0]=='0')
			break;
		long long dp[5007]={};
		int n=strlen(a),i;
		dp[n]=1;
		for(i=n-1;i>=0;i--)
		{
			if (i<n-1 && (a[i]=='1' || (a[i]=='2' && a[i+1]<='6')))
				dp[i]=dp[i+1]+dp[i+2];
			else
				dp[i]=dp[i+1];
		}
		printf("%lld\n",dp[0] );
	}
	return 0;
}