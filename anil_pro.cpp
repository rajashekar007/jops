#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define MX 1000009
typedef long long ll;
int fn[MX];
struct stnode
{
	int val,flag,s,e;
};
void printt(stnode *st)
{
	int i=0;
	while(st[i].val!=0)
		printf("%d ", st[i++].val);
	printf("\n");
}
void propagate(stnode *st,int i,int l,int h)
{
	st[i].flag=1;
	st[i].s=l;
	st[i].e=h;
}
void update(stnode *st,int ss,int se,int qs,int qe,int i)
{
	if(st[i].flag==1)
	{
		st[i].flag=0;
		int l,h;
		l=max(ss,st[i].s);
		h=min(se,st[i].e);
		l=l-st[i].s;
		h=h-st[i].s+1;
		st[i].val=((ll)st[i].val+fn[h+2]-fn[l+2])%MOD;
		if(ss!=se)
		{
			propagate(st,2*i,st[i].s,st[i].e);
			propagate(st,2*i+1,st[i].s,st[i].e);
		}
	}
	if(ss>se || qs>se || qe<ss)
		return;
	if(ss<=qs && qe<=se)
	{
		st[i].val=(st[i].val+fn[qe-qs+3]-1)%MOD;
		if(ss!=se)
		{
			propagate(st,2*i,qs,qe);
			propagate(st,2*i+1,qs,qe);
		}
		return;
	}
	int m=(ss+se)/2;
	update(st,ss,m,qs,qe,2*i);
	update(st,m+1,se,qs,qe,2*i+1);
}
int query(stnode *st,int ss,int se,int qs,int qe,int i)
{
	if(st[i].flag==1)
	{
		st[i].flag=0;
		int l,h;
		l=max(ss,st[i].s);
		h=min(se,st[i].e);
		l=l-st[i].s;
		h=h-st[i].s+1;
		st[i].val=((ll)st[i].val+fn[h+2]-fn[l+2])%MOD;
		if(ss!=se)
		{
			propagate(st,2*i,st[i].s,st[i].e);
			propagate(st,2*i+1,st[i].s,st[i].e);
		}
	}
	if(qe<qs || qs>se || qe<ss)
		return 0;
	if(ss<=qs && qe<=se)
	{
		return st[i].val;
	}
	int m=(ss+se)/2;
	return ((ll)query(st,ss,m,qs,qe,2*i)+
		query(st,m+1,se,qs,qe,2*i+1))%MOD;
}
stnode stree[4000009];
int main()
{
	int n,q,i,l,r,t;
	scanf("%d%d",&n,&q);
	int a[MX]={};
	fn[1]=1;fn[2]=1;
	for(i=3;i<MX;i++)
		fn[i]=((ll)fn[i-1]+fn[i-2])%MOD;
	for(i=0;i<q;i++)
	{
		scanf("%d%d%d",&t,&l,&r);
		if(t==0)
		{
			update(stree,1,n,l,r,0);
			printt(stree);
		}
		else
		{
			printf("%d\n", query(stree,1,n,l,r,0));
			printt(stree);
		}
	}
	return 0;
}