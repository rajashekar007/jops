#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll getseg_sum(ll *st,int ss,int se,int qs,int qe,int si)
{
	if(qs<=ss && se<=qe)
		return st[si];
	if(qe<ss || qs>se)
		return 0;
	int mid=ss+(se-ss)/2;
	return getseg_sum(st,ss,mid,qs,qe,2*si+1)+getseg_sum(st,mid+1,se,qs,qe,2*si+2);
}
void update_seg(ll *st,int ss,int se,int i,int dif,int si)
{
	if(i<ss || i>se)
		return;
	st[si]=st[si]+dif;
	if(se!=ss)
	{
		int mid=(ss+se)/2;
		update_seg(st,ss,mid,i,dif,2*si+1);
		update_seg(st,mid+1,se,i,dif,2*si+2);
	}
}
ll stree[3000009]={};
int main()
{
	int n,q,i,k,m;
	scanf("%d%d",&n,&q);
	for(i=0;i<q;i++)
	{
		char c[15]={};
		scanf("%s%d%d",c,&m,&k);
		if(c[0]=='f')
		{
			printf("%lld\n",getseg_sum(stree,0,n-1,m,k,0) );
		}
		else
		{
			update_seg(stree,0,n-1,m,k,0);
		}
	}
	return 0;
}