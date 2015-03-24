#include <bits/stdc++.h>
using namespace std;
int main()
{
	int h;
	scanf("%d",&h);
	int a[100000]={},l=(int)pow(2,h),i,t,k;
	for(i=1;i<l;i++)
	{
		k=0;
		scanf("%d",&t);
		if(t%2)
		{
			if(a[t+1]==0)
				k=1;
		}
		else
		{
			if(a[t-1]==0)
				k=1;
		}
		a[t]=1;
		printf("%d ", k);
	}
	printf("\n");
	scanf("%d",&t);
	return 0;
}