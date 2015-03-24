#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define mp(a,b) make_pair(a,b)
int min_unvis(int *dis,int *vis)
{
	int m=INT_MAX,i,r=-1;
	for(i=0;i<501;i++)
	{
		if(vis[i]==0 && dis[i]<m)
		{
			m=dis[i];
			r=i;
		}
	}
	return r;
}
int main()
{
	int g[501][501],n,i,j,s,d,tp,u,q,dis[501],vis[501]={};
	for(i=0;i<501;i++)
	{
		dis[i]=INT_MAX;
		for(j=0;j<501;++j)
		{
			if(i!=j)
				g[i][j]=INT_MAX;
			else
				g[i][j]=0;
		}
	}
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d %d %d",&s,&d,&tp);
		g[s][d]=tp;
		g[d][s]=tp;
	}
	scanf("%d",&u);
	// priority_queue<pii,vector<pii>,greater<pii> > pq;
	dis[u]=0;
	j=min_unvis(dis,vis);
	while(j!=-1)
	{
		for(int k=0;k<501;k++)
		{
			if(vis[k]==0 && g[j][k]!=INT_MAX && dis[k]>dis[j]+g[j][k])
				dis[k]=dis[j]+g[j][k];
		}
		vis[j]=1;
		j=min_unvis(dis,vis);
	}
	scanf("%d",&q);
	for(i=0;i<q;i++)
	{
		scanf("%d",&d);
		if(dis[d]!=INT_MAX)
			printf("%d\n", dis[d]);
		else
			printf("NO PATH\n");
	}
	return 0;
}