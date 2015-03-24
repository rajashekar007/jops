#include <bits/stdc++.h>
using namespace std;
int root(int *a,int c)
{
	while(a[c]!=c)
	{
		a[c]=a[a[c]];
		c=a[c];
	}
	return c;
}
int cnt=0;
void possi(vector<int> a,int* b,int i,int cw,int w)
{
	if(cw==w)
		cnt++;
	else if(i<a.size())
	{
		possi(a,b,i+1,cw+b[a[i]],w);//cout<<i<<","<<cw+b[a[i]]<<","<<w<<endl;
		possi(a,b,i+1,cw,w);
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m,a[1007]={},ar[1007]={},i,j,c,d,rank[1007]={},w;
		scanf("%d%d%d",&n,&w,&m);
		for(i=1;i<=n;i++)
			a[i]=i;
		for(i=1;i<=n;i++)
			scanf("%d",&ar[i]);
		for(i=1;i<=m;i++)
		{
			scanf("%d%d",&c,&d);
			if(c>d)
				swap(c,d);
			int rc=root(a,c),rd=root(a,d);
			if(rank[rc]>rank[rd])
				a[rd]=rc;
			else if(rank[rc]<rank[rd])
				a[rc]=rd;
			else
			{
				a[rc]=rd;
				rank[rd]++;
			}

		}
		map<int,vector<int> >mv;
		for(i=1;i<=n;i++)
		{
			int rt=root(a,i);
			mv[rt].push_back(i);
		}
		cnt=0;
		for (map<int,vector<int> >::iterator it=mv.begin(); it!=mv.end(); ++it)
		{
			// for(i=0;i<(it->second).size();i++)
			// 	cout<<(it->second)[i]<<",";
			// cout<<endl;
			possi((it->second),ar,0,0,w);
		}
		printf("%d\n", cnt);
	}
	return 0;
}