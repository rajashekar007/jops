#include <iostream>
#include <stdio.h>
using namespace std;
// int a[1000][1000];
int max(int x,int y)
{
	return x>y?x:y;
}
int main()
{
	int t,k;
	scanf("%d",&t);
	for(k=1;k<=t;k++)
	{
		int m,n,i,j,a[1007][1007]={};
		char x[1007]={},y[1007]={};
		scanf("%d %s %d %s",&m,x,&n,y);
		for(i=0;i<=m;i++)
		{
			for(j=0;j<=n;j++)
			{
				if(i==0 || j==0)
					a[i][j]=0;
				else if(x[i-1]==y[j-1])
					a[i][j]=a[i-1][j-1]+1;
				else
					a[i][j]=max(a[i-1][j],a[i][j-1]);
			}
		}
		char lcs[1007]={};

		int ind=a[m][n];
		int b[ind],c[ind];
		lcs[ind]='\0';
		i=m;j=n;
		while(i>0 && j>0)
		{
			if(x[i-1]==y[j-1])
			{
				lcs[ind-1]=x[i-1];b[ind-1]=i;c[ind-1]=j;
				i--;
				j--;
				ind--;
			}
			else if(a[i-1][j]>a[i][j-1])
			{
				i--;
			}
			else
			{
				j--;
			}
		}
		if(a[m][n]>0)
		{
			printf("case %d Y\n",k);
			printf("%d\n", a[m][n]);
			for(i=0;i<a[m][n];i++)
			{
				printf("%c %d %d\n", lcs[i],b[i],c[i]);
			}
		}
		else
			printf("case %d N\n",k);

	}
	return 0;
}