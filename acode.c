#include <stdio.h>
#include <string.h>
int main()
{
	while(1)
	{
		char c[100007]={};
		long long int dp[100007]={};
		scanf("%s",c);
		int len=strlen(c);//printf("len =%d\n", len);
		if(!(c[0]-'0'))
			break;
		int i;
		dp[0]=1;
		for(i=1;i<len;i++)
		{
			if(c[i]-'0')
			{
				dp[i]=dp[i-1];
			}
			int temp=(c[i-1]-'0')*10;
			temp+=(c[i]-'0');//printf("%d\n", temp);
			if(temp<=26 && temp>9)
			{
				dp[i]+=dp[i-2>=0?i-2:0];
			}
		}
		printf("%lld\n", dp[len-1]);
	}
	return 0;
}