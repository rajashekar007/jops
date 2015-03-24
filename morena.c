#include <stdio.h>
typedef long long ll;
int main()
{
	int n,i;
	scanf("%d",&n);
	ll a[n+9];
	if(n>2)
	{
		int up=0,ans=1;
		scanf("%lld",&a[0]);
		scanf("%lld",&a[1]);
		ll dif=a[1]-a[0];
		if(dif>0)
		{
			ans=2;
			up=1;
		}
		else if(dif<0)
		{
			ans=2;
			up=-1;
		}
		for(i=2;i<n;i++)
		{
			scanf("%lld",&a[i]);
			dif=a[i]-a[i-1];
			if((dif>0 && up==-1) || (dif>0 && up==0))
			{
				up=1;
				ans++;
			}
			else if((dif<0 && up==1) || (dif<0 && up==0))
			{
				up=-1;
				ans++;
			}

		}
		printf("%d\n", ans);
	}
	else if(n==2)
	{
		scanf("%lld",&a[0]);
		scanf("%lld",&a[1]);
		if(a[0]!=a[1])
			printf("2\n");
		else
			printf("1\n");
	}
	else
	{
		scanf("%lld",&a[0]);
		printf("1\n");
	}
}