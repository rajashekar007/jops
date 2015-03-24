#include <bits/stdc++.h>
using namespace std;
#define MX 109
int main()
{
	char a[MX],b[MX];
	while(scanf("%s %s",a,b)!=EOF)
	{
		int lcs[MX][MX],i,j,la,lb;
		la=strlen(a);
		lb=strlen(b);
		for(i=0;i<MX;i++)
		{
			lcs[0][i]=0;
			lcs[i][0]=0;
		}
		for(i=1;i<=la;i++)
		{
			for(j=1;j<=lb;j++)
			{
				if(a[i-1]==b[j-1])
					lcs[i][j]=lcs[i-1][j-1]+1;
				else
					lcs[i][j]=max(lcs[i-1][j],lcs[i][j-1]);
			}
		}
		int ls=la+lb-lcs[la][lb];
		char lc[ls+1];
		lc[ls]='\0';
		i=la;j=lb;
		while(i>0 && j>0)
		{
			if(a[i-1]==b[j-1])
			{
				lc[ls-1]=a[i-1];
				i--;
				j--;
				ls--;
			}
			else if(lcs[i-1][j]>lcs[i][j-1])
			{
				lc[ls-1]=a[i-1];
				ls--;
				i--;
			}
			else
			{
				lc[ls-1]=b[j-1];
				ls--;
				j--;
			}
		}
		while(i>0)
		{
			lc[ls-1]=a[i-1];
			ls--;
			i--;
		}
		while(j>0)
		{
			lc[ls-1]=b[j-1];
			ls--;
			j--;
		}
		printf("%s\n", lc);
	}
	// printf("%d\n", lcs[la][lb]);
	return 0;
}