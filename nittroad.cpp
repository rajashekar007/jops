#include <bits/stdc++.h>
using namespace std;
int findroot(int *a,int c)
{
	while(a[c]>0)
	{
		if(a[a[c]]>0)
		{
			a[c]=a[a[c]];
			c=a[c];
		}
		else
			c=a[c];
	}
	return c;
}
int cnt;
void munion(int *a,int *rank,int c,int d)
{
	if(c>d)
		swap(c,d);
	int rc=findroot(a,c),rd=findroot(a,d);
	cnt=cnt-a[rc]*a[rd];
	if(rank[rc]>rank[rd])
	{
		a[rc]=a[rc]+a[rd];
		a[rd]=rc;
	}
	else if(rank[rc]<rank[rd])
	{
		a[rd]=a[rd]+a[rc];
		a[rc]=rd;
	}
	else
	{
		a[rd]=a[rd]+a[rc];
		a[rc]=rd;
		rank[rd]++;
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		cnt=0;
		int n,nq,i,m[20009]={},tp,c,d;
		pair<char,int> q[20009];
		pair<int,int> e[20009];
		scanf("%d",&n);
		for(i=1;i<n;i++)
		{
			scanf("%d%d",&e[i].first,&e[i].second);
		}
		scanf("%d",&nq);
		char b;
		for(i=1;i<=nq;i++)
		{
			scanf(" %c",&b);
			if(b=='R')
			{
				scanf("%d",&tp);
				m[tp]=1;
				q[i].second=tp;
			}
			q[i].first=b;
		}
		cnt=(n*(n-1))/2;
		int a[20009],rank[20009]={};
		for(i=1;i<=n;i++)
		{
			a[i]=-1;
		}
		for(i=1;i<n;i++)
		{
			if(m[i]==0)
			{
				munion(a,rank,e[i].first,e[i].second);
			}
		}
		stack<int> ans;
		for(i=nq;i>=1;i--)
		{
			if(q[i].first=='Q')
				ans.push(cnt);
			else
			{
				tp=q[i].second;
				munion(a,rank,e[tp].first,e[tp].second);
			}

		}
		while(!ans.empty())
		{
			printf("%d\n", ans.top());
			ans.pop();
		}
		printf("\n");
	}
	return 0;
}