#include <stdio.h>
int main()
{
	int a[101][101];
	int n,num;
	scanf("%d",&n);
	int i,j;
	num=1;
	for(i=0;i<=n/2;i++)
	{
		for(j=0;j<n;j++)
		{
			a[i][j]=num;
			num+=2;
			if(num>n*n)
				break;
		}
		if(num>n*n)
			break;
	}
	num=2;
	for(i=n-1;i>=n/2;i--)
	{
		for(j=n-1;j>=0;j--)
		{
			a[i][j]=num;
			num+=2;
			if(num>n*n)
				break;
		}
		if(num>n*n)
			break;
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
	return 0;
}