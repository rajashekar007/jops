#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;
int c[]={0,10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};
#define MOD 1000000007
int len(int a)
{
	int i;
	for(i=1;i<10;i++)
	{
		if(a<c[i])
			break;
	}
	return i;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int j,ai,bi,i;
		long long ans=0,sum1,sum2,s,e,a,b;
		scanf("%lld%lld",&a,&b);
		
		ai=len(a);bi=len(b);
		for(i=ai;i<=bi;i++)
		{
			if(i==ai)
			{
				e=(int)pow(10,i)-1;
				s=a;
			}
			else if(i==bi)
			{
				e=b;
				s=(int)pow(10,i-1);
			}
			else
			{
				s=(int)pow(10,i-1);
				e=((int)pow(10,i))-1;
			}
			sum1=((e*(e+1))/2)%MOD;
			sum2=((s*(s+1))/2)%MOD;
			ans=(ans+((sum1-sum2+s)*i)%MOD)%MOD;
		}
		printf("%lld\n", ans);
	}
	return 0;
}