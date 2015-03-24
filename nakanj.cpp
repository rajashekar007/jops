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
void make_edges(int g[65][65],int i,int j)
{
	int u=i*j;
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
void construct_graph(int g[65][65],int n)
{
	int i=1;
	for(i=1;i<=n;i++)
	{
		int j;
		for(j=1;j<=n;j++)
		{
			make_edges(g,i,j);
		}
	}
}

int bfs(int g[65][65],int s,int d)
{
	queue<int> q;
	q.push(s);
	int r=s,ans=0,visited[65]={};
	// int j,k;
	// for(j=0;j<65;j++)
	// {
	// 	visited[j]=0;
	// }
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
		// ans++;
		else
		{
			q.pop();
			int i;
			for(i=1;i<65;i++)
			{
				if(g[t][i] && !visited[i])
				{
					q.push(i);cout<<i<<",";
					visited[i]=1;
				}
			}
		}cout<<endl;
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
	construct_graph(g,8);
	while(t--)
	{
		char c;
		cin>>c;
		int s1=c-97,s2,d1,d2;
		cin>>s2;
		cin>>c;
		d1=c-97;
		cin>>d2;//cout<<"start is "<<s1*s2<<" destination is "<<d1*d2<<" ";
		printf("ans = %d\n",bfs(g,s1*8+s2,d1*8+d2));
	}
	return 0;
}