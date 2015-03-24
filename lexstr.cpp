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
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m,a[100007]={},ar[100007]={},i,j,c,d,rank[100007]={};
		char ch[100007]={},op[100007]={};
		scanf("%s%d",ch,&m);
		n=strlen(ch);
		for(i=0;i<n;i++)
			ar[i+1]=ch[i];
		for(i=1;i<=n;i++)
			a[i]=i;
		for(i=1;i<=m;i++)
		{
			scanf("%d%d",&c,&d);
			c++;d++;
			if(c!=d)
			{
				if(c>d)
					swap(c,d);
				int rc=root(a,c),rd=root(a,d);
				if(rc!=rd)
				{
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
			}

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
			printf("%c",op[i] );;
		cout<<endl;
	}
	return 0;
}