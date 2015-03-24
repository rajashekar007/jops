#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll constsegtree(ll *tr,int *ar,int l,int h,int i)
{
	if(l==h)
	{
		tr[i]=ar[l];
		return tr[i];
	}
	int m=(l+h)/2;
	tr[i]=constsegtree(tr,ar,l,m,2*i+1)+constsegtree(tr,ar,m+1,h,2*i+2);
	return tr[i];
}
ll rangesum(ll *tr,int l,int h,int sq,int eq,int i)
{
	if(l<=sq && eq<=h)
		return tr[i];
	else if(eq<l || h<sq)
		return 0;
	else
	{
		int m=(l+h)/2;
		return rangesum(tr,l,m,sq,eq,2*i+1)+rangesum(tr,m+1,h,sq,eq,2*i+2);
	}
}
struct op
{
	int typ,s,e;
};
int main()
{
	int n,i,ar[200009],nq,tp,asiz=0;
	scanf("%d",&n);
	for(i=n-1;i>=0;i--)
		scanf("%d",&ar[i]);
	asiz=n;
	scanf("%d",&nq);
	op qry[100009];
	for(i=0;i<nq;i++)
	{
		scanf("%d",&qry[i].typ);
		scanf("%d",&qry[i].s);
		if(qry[i].typ==1)
			scanf("%d",&qry[i].e);
		else
			ar[asiz++]=qry[i].s;
	}printf("asiz= %d\n", asiz);
	ll tr[400009]={};
	constsegtree(tr,ar,0,asiz-1,0);
	stack<ll> ans;
	for(i=nq-1;i>=0;i--)
	{
		if(qry[i].typ==1)
			ans.push(rangesum(tr,0,asiz-1,asiz-qry[i].e,asiz-qry[i].s,0));
		else
			asiz--;
	}
	while(!ans.empty())
	{
		printf("%lld\n",ans.top());
		ans.pop();
	}
	return 0;
}