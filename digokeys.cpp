#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int a[100009][11],i,j,vis[100009]={},frnt,
		ns=0,from[100009]={};
		from[1]=1;
		for(i=1;i<n;i++)
		{
			scanf("%d",&j);
			a[i][0]=j;
			for(j=1;j<=a[i][0];j++)
				scanf("%d",&a[i][j]);
			sort(a[i]+1,a[i]+a[i][0]+1);
		}
		queue<int> q;
		stack<int> ans;
		q.push(1);
		while(!q.empty())
		{
			frnt=q.front();
			if(frnt==n)
				break;
			else
			{
				q.pop();
				if(vis[frnt]==0)
				{
					vis[frnt]=1;
					for(j=1;j<=a[frnt][0];j++)
					{
						if(vis[a[frnt][j]]==0)
						{
							q.push(a[frnt][j]);
							if(from[a[frnt][j]]==0)
							from[a[frnt][j]]=frnt;
						}
					}
				}
			}
		}
		if(q.empty())
			printf("-1\n");
		else
		{
			j=n;
			while(j!=1)
			{
				ans.push(from[j]);
				// printf("%d ", from[j]);
				j=from[j];
			}
			printf("%lu\n", ans.size());
			while(!ans.empty())
			{
				printf("%d ", ans.top());
				ans.pop();
			}
		}
		printf("\n");
	}
	return 0;
}