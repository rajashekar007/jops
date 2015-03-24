#include <bits/stdc++.h>
using namespace std;
struct pr
{
	int f,s,v;
};
bool fun(pr a,pr b)
{
	return a.f<b.f;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		pr a[1009];
		int n,i,j;
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&a[i].f);
		for(i=0;i<n;i++)
			scanf("%d",&a[i].s);
		sort(a,a+n,fun);
		list<pr> b;
		for(i=0;i<n;i++)
		{
			pr tp;
			tp.f=a[i].f;
			tp.s=a[i].s;
			tp.v=0;
			b.push_back(tp);
		}
		list<pr>::iterator it,jt;
		it=b.end();
		it--;
		while(1)
		{
			if((*it).v==0)
			{
				(*it).v=1;
				j=(*it).s;
				for(jt=it;j>=0;j--)
				{
					jt++;
				}
				pr tp;
				tp.f=(*it).f;
				tp.s=(*it).s;
				tp.v=1;
				b.insert(jt,tp);
				it=b.erase(it);
				if(it==b.begin())
					break;
				else
					it--;
			}
			else if(it!=b.begin())
			{
				it--;
			}
			else
				break;
		}
		for(it=b.begin();it!=b.end();it++)
			printf("%d ",(*it).f);
		printf("\n");
	}
	return 0;
}