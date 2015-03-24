#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		int a[1009]={},lis[1009]={},i,j,mx=-1;
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		lis[n-1]=1;
		for(i=n-1;i>=0;i--)
		{
			for(j=n-1;j>i;j--)
			{
				if((a[i]>a[j]||i==m) && lis[i]<lis[j]+1)
					lis[i]=lis[j]+1;
			}
			lis[i]=max(1,lis[i]);
			if(mx<lis[i])
				mx=lis[i];
		}
		printf("%d\n",mx);
	}
	return 0;
}