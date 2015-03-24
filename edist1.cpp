#include <bits/stdc++.h>
using namespace std;
#define MX 2001
int lcs[MX][MX];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		char a[MX],b[MX];
		int i,j,la,lb;
		scanf("%s %s",a,b);
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
		int ls=la+lb-lcs[la][lb],ans=0;
		char lc[ls+1];
		lc[ls]='\0';
		i=la;j=lb;
		while(i>0 && j>0)
		{
			if(a[i-1]==b[j-1])
			{
				i--;
				j--;
			}
			else if(lcs[i-1][j]>lcs[i][j-1])
			{
				i--;
				ans++;
			}
			else if(lcs[i-1][j]<lcs[i][j-1])
			{
				j--;
				ans++;
			}
			else
				i--;
		}
		// for(int ti=0;ti<=la;ti++)
		// {
		// 	for(int tj=0;tj<=lb;tj++)
		// 		printf("%d ", lcs[ti][tj]);
		// 	printf("\n");
		// }
		ans+=i+j;
		printf("%d\n", ans);
	}
	// printf("%d\n", lcs[la][lb]);
	return 0;
}