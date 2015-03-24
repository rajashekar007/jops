#include <bits/stdc++.h>
using namespace std;
int k[2002][2002];
int main()
{
	int s,n,val[2002]={},wt[2002]={},i,w;
	scanf("%d%d",&s,&n);
	for(i=1;i<=n;i++)
		scanf("%d%d",&wt[i],&val[i]);
	for(i=1;i<=n;i++)
	{
		for(w=1;w<=s;w++)
		{
			if(w>=wt[i])
				k[i][w]=max(val[i]+k[i-1][w-wt[i]],k[i-1][w]);
			else
				k[i][w]=k[i-1][w];
		}
	}
	printf("%d\n", k[n][s]);
	return 0;
}