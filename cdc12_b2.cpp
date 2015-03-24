#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool fun (const char *a,const char *b)
{
	return strcmp(a,b)<0;
}
int main()
{
	int t,k;
	scanf("%d",&t);
	for(k=1;k<=t;k++)
	{
		int n,i,lim,le,v,j=1;
		int p=0,e;
		scanf("%d%d",&n,&le);
		e=le;
		vector<const char*> ar[101];
		for(i=0;i<n;i++)
		{
			char *ac=new char[109];
			scanf("%s%d",ac,&v);
			ar[v].push_back(ac);
		}j=0;
		for(i=1;i<=100;i++)
		{
			sort(ar[i].begin(),ar[i].end(),fun);
		}
		// printf("j=%d\n", j);
		j=0;
		vector<const char*> ans;
		for(i=1;i<=100;i++)
		{
			if(ar[i].size()>0)
			{
				for(int l=0;l<ar[i].size();l++)
				{
					if(e-i+j<0)
						break;
					else
					{
						ans.push_back(ar[i][l]);
						e=e-i+j;
						j++;
					}
				}
			}
		}
		printf("Scenario #%d: %d\n",k,ans.size() );
		sort(ans.begin(),ans.end(),fun);
		for(i=0;i<ans.size();i++)
			printf("%s ", ans[i]);
		printf("\n");
	}
	return 0;
}