#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,i,a;
		long long sum=0;
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a);
			if(a<0)
				a=2*a;
			else
				a=i*a;
			sum+=a;
		}
		printf("%lld\n", sum);
	}
	return 0;
}