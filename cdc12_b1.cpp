#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct char_cmp { 
bool operator () (const char *a,const char *b) const 
{
	return strcmp(a,b)<0;
} 
};
int main()
{
	int t,k;
	scanf("%d",&t);
	for(k=1;k<=t;k++)
	{
		int n,i,lim,le,v,j=1;
		ll p=0,e;
		scanf("%d%d",&n,&le);
		e=le;
		map<const char*,int,char_cmp> ar[101];
		for(i=0;i<n;i++)
		{
			char *ac=new char[109];
			scanf("%s%d",ac,&v);
			ar[v][ac]=1;
		}
		map<const char*,int,char_cmp> ans;
		map<const char*,int>::iterator it;
		for(i=1;i<=100;i++)
		{
			if(ar[i].size()>0)
			{
				for(it=ar[i].begin();it!=ar[i].end();it++)
				{
					if(e-i+j<0)
						break;
					else
					{
						ans[it->first]=1;
						e=e-i+j;
						j++;
					}
				}
			}
		}
		lim=j-1;
		printf("Scenario #%d: %d\n",k,lim );
		for(it=ans.begin();it!=ans.end();it++)
			printf("%s ", it->first);
		printf("\n");
	}
	return 0;
}