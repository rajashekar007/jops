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
		int a[n],i,mx=-1,ans,sum=0,temp,cnt,cap;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			sum+=a[i];
			if(mx<a[i])
				mx=a[i];
		}
		if(k>=n)
		{
			ans=mx;
		}
		else
		{
			mx=max(sum/k,mx);
			temp=mx-1;
			while(1)
			{
				temp++;
				cap=temp;
				cnt=1;
				for(i=0;i<n;i++)
				{
					if(a[i]>cap)
					{
						cap=temp-a[i];
						cnt++;
					}
					else
					{
						cap=cap-a[i];
					}
					if(cnt>k)
						break;
				}
				if(i==n)
					break;
			}
			ans=temp;
		}
		printf("%d\n", ans);
	}
	return 0;
}