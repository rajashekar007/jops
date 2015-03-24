#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;
int within_bounds(int i,int j)
{
	if(i<8 && i>=0 && j<9 && j>0)
		return 1;
	else
		return 0;
}
void make_edges(int g[65][65],int u)
{
	int i=(u-1)/8,j=((u-1)%8)+1;
	if( within_bounds(i-2,j-1))
	{
		g[u][(i-2)*8+(j-1)]=1;	
	}	
	if( within_bounds(i-2,j+1))
	{
		g[u][(i-2)*8+(j+1)]=1;	
	}	
	if( within_bounds(i+2,j-1))
	{
		g[u][(i+2)*8+(j-1)]=1;	
	}	
	if( within_bounds(i+2,j+1))
	{
		g[u][(i+2)*8+(j+1)]=1;	
	}	
	if( within_bounds(i-1,j-2))
	{
		g[u][(i-1)*8+(j-2)]=1;	
	}	
	if( within_bounds(i-1,j+2))
	{
		g[u][(i-1)*8+(j+2)]=1;	
	}	
	if( within_bounds(i+1,j-2))
	{
		g[u][(i+1)*8+(j-2)]=1;	
	}	
	if( within_bounds(i+1,j+2))
	{
		g[u][(i+1)*8+(j+2)]=1;	
	}	
}
void construct_graph(int g[65][65])
{
	int i=1,n=64;
	for(i=1;i<=n;i++)
	{
		make_edges(g,i);
	}
}

int bfs(int g[65][65],int s,int d)
{
	queue<int> q;
	q.push(s);
	int r=s,ans=0,visited[65]={};
	visited[s]=1;
	q.push(-1);
	while(!q.empty())
	{
		int t=q.front();
		if(t==-1)
		{
			q.pop();
			q.push(-1);
			ans++;
		}
		else if(t==d)
			break;
		else
		{
			q.pop();
			int i;
			for(i=1;i<65;i++)
			{
				if(g[t][i] && !visited[i])
				{
					q.push(i);
					visited[i]=1;
				}
			}
		}
	}
	return ans;
}
int main()
{
	int t;
	scanf("%d",&t);
	int g[65][65]={},i,j;
	for(i=0;i<65;i++)
	{
		for(j=0;j<65;j++)
		{
			g[i][j]=0;
		}
	}
	construct_graph(g);
	while(t--)
	{
		char c;
		cin>>c;
		int s1=c-97,s2,d1,d2;
		cin>>s2;
		cin>>c;
		d1=c-97;
		cin>>d2;
		printf("%d\n",bfs(g,s1*8+s2,d1*8+d2));
	}
	return 0;
}