#include <stdio.h>
long long max(long long x, long long y)
{
	return x>y?x:y;
}
long long goldcoins(int *ar,int cur,int s)
{
	if(cur<s-1)
	{
		return max(ar[cur]+goldcoins(ar,cur+2,s),goldcoins(ar,cur+1,s));
	}
	else if(cur==s-1)
	{
		return ar[cur];
	}
	else
	{
		return 0;
	}
}
int main()
{
	int t,j;
	scanf("%d",&t);
	for(j=1;j<=t;j++)
	{
		int n;
		scanf("%d",&n);
		int i,a[10007]={};
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		printf("Case %d: %lld\n",j,goldcoins(a,0,n));
	}
	return 0;
}