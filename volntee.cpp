#include <bits/stdc++.h>
using namespace std;
bool fun(int x,int y)
{
	return abs(x)<abs(y);
}
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	int a[n],i,j,mn,mx=INT_MIN;
	long long sum=0,r=0;
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]<0)
		{
			r++;
			sum-=a[i];
		}	
		else
			sum+=a[i];
		if(a[i]>mx)
			mx=a[i];
	}
	if(k==n)
	{
		if(r%2)
			sum=-sum;
		printf("%lld\n", sum);
	}
	else if(k==1)
	{
		printf("%d\n", mx);
	}
	else
	{
		sum=0;r=0;
		int minn=INT_MAX,minp=INT_MAX;
		sort(a,a+n,fun);
		for(i=0;i<k;i++)
		{
			j=n-1-i;
			if(a[j]<0)
			{
				r++;
				sum-=a[j];
				if(minn>-a[j])
					minn=-a[j];
			}
			else
			{
				sum+=a[j];
				if(minp>a[j])
					minp=a[j];
			}	
		}
		if(r%2)
		{
			int maxp=INT_MIN,maxn=INT_MIN;
			for(i=n-1-k;i>=0;i--)
			{
				if(a[i]>0 && a[i]>maxp)
					maxp=a[i];
				else if(-a[i]>maxn)
					maxn=-a[i];
			}
			if(minp+maxp>minn+maxn)
				sum=sum-minn+maxp;
			else
				sum=sum-minp+maxn;
		}
		printf("%lld\n", sum);
	}
	return 0;
}