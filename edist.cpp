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
		int ls=lcs[la][lb];
		if(lb>la)
			ls=lb-ls;
		else
			ls=la-ls;
		printf("%d\n", ls);
	}
	// printf("%d\n", lcs[la][lb]);
	return 0;
}