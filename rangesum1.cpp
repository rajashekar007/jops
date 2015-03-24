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
	// printf("l= %d,h=%d ,sq=%d eq=%d %lld\n",l,h,sq,eq, tr[i]);
	if(sq<=l && h<=eq)
	{	
		// printf("l= %d,h=%d %lld\n",l,h, tr[i]);
		return tr[i];
	}
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
ll tr[600009]={};
op qry[200009];
int main()
{
	int n,i,ar[300009],nq,tp,asiz=0,osiz=0;
	scanf("%d",&n);
	for(i=n-1;i>=0;i--)
		scanf("%d",&ar[i]);
	asiz=n;
	scanf("%d",&nq);
	
	for(i=0;i<nq;i++)
	{
		scanf("%d",&qry[i].typ);
		scanf("%d",&qry[i].s);
		if(qry[i].typ==1)
			scanf("%d",&qry[i].e);
		else
			ar[asiz++]=qry[i].s;
	}
	// printf("asiz= %d\n", asiz);
	ll ta;
	constsegtree(tr,ar,0,asiz-1,0);
	stack<ll> ans;
	osiz=asiz;
	for(i=nq-1;i>=0;i--)
	{
		if(qry[i].typ==1)
		{
			ta=rangesum(tr,0,osiz-1,asiz-qry[i].e,asiz-qry[i].s,0);
			// printf("asiz = %d,ta = %lld s= %d e= %d\n",osiz,ta,asiz-qry[i].e,asiz-qry[i].s );
			ans.push(ta);
		}
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