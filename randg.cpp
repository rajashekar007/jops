#include <bits/stdc++.h>
using namespace std;
int main()
{
	char c[57];
	while(scanf("%s",c)!=EOF)
	{
		int r[57]={},g[57]={},l,i,mn=57;
		l=strlen(c)-1;
		if(c[0]=='G')
			r[0]=1;
		if(c[l]=='R')
			g[l]=1;
		for(i=1;i<=l;i++)
		{
			if(c[i]=='G')
				r[i]=r[i-1]+1;
			else
				r[i]=r[i-1];
		}
		for(i=l-1;i>=0;i--)
		{
			if(c[i]=='R')
				g[i]=g[i+1]+1;
			else
				g[i]=g[i+1];
		}
		for(i=0;i<=l;i++)
		{
			if(r[i]+g[i]<mn)
				mn=r[i]+g[i];
		}
		printf("%d\n", mn-1);
	}
	return 0;
}