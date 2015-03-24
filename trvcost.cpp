#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define mp(a,b) make_pair(a,b)
struct comp
{
	bool operator()(const pii a,const pii b)
	{
		return a.first<b.first;
	}
};
int main()
{
	int g[501][501],n,i,j,s,d,tp,u,q,dis[501];
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
		scanf("%d %d %d",&s,&d,tp);
		g[s][d]=tp;
		g[d][s]=tp;
	}
	scanf("%d",&u);
	priority_queue<pii,vector<pii>,comp > pq;
	// priority_queue<pii,vector<pii>,greater<pii> > pq;
	for(i=0;i<501;i++)
	{
		pq.push(mp(g[u][i],i));
	}
	dis[u]=0;
	int vis[501]={};
	pii tpi;
	while(!pq.empty())
	{
		tpi=pq.top();
		i=tpi.second;
		if(!vis[i])
		{
			for(j=0;j<501;j++)
			{
				if(g[i][j]!=INT_MAX)
				{
					if(dis[j]>dis[i]+g[i][j])
						dis[j]=dis[i]+g[i][j];
				}
			}
			vis[i]=1;
			pq.pop();
		}
	}
	return 0;
}