#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,k;
		scanf("%d%d",&n,&k);
		if(k==1)
			printf("0\n");
		else if(k==n)
		{
			printf("%d\n",n-1);
		}
		else if(k>n)
			printf("%d\n", n);
		else
		{
			long long a=k;
			int ans=0,p=1,cnt;
			while (a<=n)
			{
				cnt=n/a;
				if( p%2==0)
					ans=ans-cnt;
				else
					ans=ans+cnt;
				a=a*k;
				p+=1;
			}
			printf("%d\n", n-ans);
		}

	}
	return 0;
}
