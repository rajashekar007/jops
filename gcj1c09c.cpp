#include <bits/stdc++.h>
using namespace std;
int mz[107][107],a[107];
int findmin(int li,int ri)
{
	if(ri-li<2)
		return 0;
	if(mz[li][ri]!=-1)
		return mz[li][ri];
	int r=INT_MAX,i;
	for(i=li+1;i<ri;i++)
	{
		int ans=a[ri]-a[li]-2+findmin(li,i)+findmin(i,ri);
		r=min(ans,r);
	}
	mz[li][ri]=r;
	return r;
}
int main()
{
	int t,ti;
	scanf("%d",&t);
	for(ti=1;ti<=t;ti++)
	{
		memset(mz,-1,sizeof(mz));
		int p,q,i;
		scanf("%d%d",&p,&q);
		a[0]=0;
		for(i=1;i<=q;i++)
			scanf("%d",&a[i]);
		a[q+1]=p+1;
		printf("Case #%d: %d\n", ti,findmin(0,q+1));
	}
	return 0;
}