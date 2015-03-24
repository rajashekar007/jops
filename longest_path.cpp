#include <stdio.h>
#include <vector>
using namespace std;
void dfs(vector<int> *g,int u,int *v,int *visited,int *max_dist,int current_distance)
{
	if(!visited[u])
	{
		visited[u]=1;
		int i;
		for(i=0;i<g[u].size();i++)
		{
			if(!visited[g[u][i]])
			{//printf("v=%d max_dist=%d g[u][i]=%d u=%d\n", *v,*max_dist,g[u][i],u);
				if((*max_dist)<(current_distance+1))
				{
					*max_dist=current_distance+1;
					*v=g[u][i];//printf("v=%d max_dist=%d g[u][i]=%d u=%d\n", *v,*max_dist,g[u][i],u);
				}
				dfs(g,g[u][i],v,visited,max_dist,current_distance+1);
			}
		}
	}
}
int main()
{
	vector<int> g[10007];
	int visited[10007]={};
	int n,i;
	scanf("%d",&n);
	for(i=0;i<n-1;i++)
	{
		int u,v;
		scanf("%d %d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int v1,v2,max_dist=0;
	dfs(g,1,&v1,visited,&max_dist,0);
	for(i=0;i<=n;i++)
	{
		visited[i]=0;
	}
	//printf("%d %d\n", v1,max_dist);
	max_dist=0;
	dfs(g,v1,&v2,visited,&max_dist,0);
	printf("%d\n", max_dist);
	return 0;
}