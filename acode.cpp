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
		long long dp[5007]={},temp;
		int n=strlen(a),i;
		dp[0]=1;
		for(i=1;i<n;i++)
		{
			temp=0;
			if (a[i-1]=='1' || (a[i-1]=='2' && (a[i]-48)<=6))
			{

				if(i==1)
					temp=1;
				else
					temp=dp[i-2];
			}
			if(a[i]=='0')
				dp[i]=dp[i-2>0?i-2:0];
			else
				dp[i]=dp[i-1]+temp;
		}
		printf("%lld\n",dp[n-1] );
	}
	return 0;
}