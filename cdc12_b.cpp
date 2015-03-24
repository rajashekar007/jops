#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct pr
{
	char first[109];
	int second;
};
bool fun(pr a,pr b)
{
	if (a.second<b.second)
		return a.second<b.second;
	else if (a.second==b.second)
		return strcmp(a.first,b.first)<0;
}
bool fun1(pr a,pr b)
{
	return strcmp(a.first,b.first)<0;
}
pr ar[100009];
int main()
{
	int t,k;
	scanf("%d",&t);
	for(k=1;k<=t;k++)
	{
		int n,i,lim,le;
		ll p=0,e;
		scanf("%d%d",&n,&le);
		e=le;
		// memset(ar,0,100009*sizeof(pr));
		for(i=0;i<n;i++)
		{
			scanf("%s%d",ar[i].first,&ar[i].second);
		}
		sort(ar,ar+n,fun);
		for(i=0;i<n;i++)
		{
			if(ar[i].second>e)
				break;
			else
			{
				e-=ar[i].second;
				e+=(i+1);
			}
		}
		lim=i;
		printf("Scenario #%d: %d\n",k,lim );
		sort(ar,ar+lim,fun1);
		for(i=0;i<lim;i++)
			printf("%s ", ar[i].first);
		printf("\n");
	}
	return 0;
}