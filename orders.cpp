#include <iostream>
#include <stdio.h>
using namespace std;

main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int a[n+1],k[200007]={},i,j;
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		k[n-1]=0;
		for(i=n-2;i>=0;i--)
		{
			for(j=i+1;j<n;j++)
			{
				if(a[i]<a[j])
				{
					k[i]++;
				}
			}
		}
		for(i=0;i<n;i++)
			printf("%d ", i+1-a[i]+k[i]);
		printf("\n");
	}
}