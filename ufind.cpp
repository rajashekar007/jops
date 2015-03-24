#include <bits/stdc++.h>
using namespace std;
int findroot(int *a,int c)
{
	while(a[c]!=c)
	{
		a[c]=a[a[c]];
		c=a[c];
	}
	return c;
}
void union(int *a,int *rank,int c,int d)
{
	if(c>d)
		swap(c,d);
	int rc=findroot(a,c),rd=findroot(a,d);
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
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m,a[1007]={},ar[1007]={},i,j,c,d,op[1007],rank[1007]={};
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++)
			a[i]=i;
		for(i=1;i<=n;i++)
			scanf("%d",&ar[i]);
		for(i=1;i<=m;i++)
		{
			scanf("%d%d",&c,&d);
			union(a,rank,c,d);
		}
		map<int,vector<int> >mv,sv;
		for(i=1;i<=n;i++)
		{
			int rt=root(a,i);
			mv[rt].push_back(i);
			sv[rt].push_back(ar[i]);
		}
		for (map<int,vector<int> >::iterator it=sv.begin(); it!=sv.end(); ++it)
			sort((it->second).begin(),(it->second).end());
		for (map<int,vector<int> >::iterator it=mv.begin(),jt=sv.begin(); it!=mv.end(); ++it,++jt)
		{
			for(j=0;j<(it->second).size();j++)
				op[(it->second)[j]]=(jt->second)[j];
		}
		for(i=1;i<=n;i++)
			printf("%d ", op[i]);;
		cout<<endl;
	}
	return 0;
}