//this is for range sum application
#include <stdio.h>
#include <limits.h>
using namespace std;
typedef long long ll;
int min(int x,int y)
{
	return x<y?x:y;
}
int mcst(int *a,int *st,int l,int r,int si)
{
	if(l==r)
	{
		st[si]=a[l];
		return st[si];
	}
	int m=l+(r-l)/2;
	st[si]=min(mcst(a,st,l,m,2*si+1),mcst(a,st,m+1,r,2*si+2));
	return st[si];
}
int mgets(int *st,int ss,int se,int qs,int qe,int si)
{
	if(qs<=ss && se<=qe)
	{
		return st[si];
	}
	if(qe<ss || qs>se)
	{
		return INT_MAX;
	}
	int mid=ss+(se-ss)/2;
	return min(mgets(st,ss,mid,qs,qe,2*si+1),mgets(st,mid+1,se,qs,qe,2*si+2));
}
void mupdate(int *st,int ss,int se,int i,int d,int si)
{
	if(i>se || i<ss)
		return;
	if(ss!=se)
	{
		int m=ss+(se-ss)/2;
		mupdate(st,ss,m,i,d,2*si+1);
		mupdate(st,m+1,se,i,d,2*si+2);
		st[si]=min(st[2*si+1],st[2*si+2]);
	}
	// printf("ss=%lld se=%lld i=%lld\n", ss,se,i);
	if(se==ss && ss==i)
		st[si]=d;
}

ll cst(int *a,ll *st,int l,int r,int si)
{
	if(l==r)
	{
		st[si]=a[l];
		return st[si];
	}
	int m=l+(r-l)/2;
	st[si]=cst(a,st,l,m,2*si+1)+cst(a,st,m+1,r,2*si+2);
	return st[si];
}
ll sget(ll *st,int ss,int se,int qs,int qe,int si)
{
	if(qs<=ss && se<=qe)
	{
		return st[si];
	}
	if(qe<ss || qs>se)
	{
		return 0;
	}
	int mid=ss+(se-ss)/2;
	return sget(st,ss,mid,qs,qe,2*si+1)+sget(st,mid+1,se,qs,qe,2*si+2);
}
void update(ll *st,int ss,int se,int i,int d,int si)
{
	if(i>se || i<ss)
		return;
	st[si]+=d;
	if(ss!=se)
	{
		int m=ss+(se-ss)/2;
		update(st,ss,m,i,d,2*si+1);
		update(st,m+1,se,i,d,2*si+2);
	}
}
int main()
{
	int n,i,p;
	scanf("%d",&n);
	int a[100007],stm[300007];
	ll sts[300007];
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	mcst(a,stm,0,n-1,0);
	cst(a,sts,0,n-1,0);
	scanf("%d",&p);
	for(i=0;i<p;i++)
	{
		char c[20]={};
		int x,y;
		scanf("%s%d%d",c,&x,&y);
		// printf("%s\n", c);
		if(c[0]=='C')
		{
			printf("%lld\n", sget(sts,0,n-1,x,y,0)-mgets(stm,0,n-1,x,y,0));
		}
		else if(c[0]=='G')
		{
			a[y]+=x;
			update(sts,0,n-1,y,x,0);
			mupdate(stm,0,n-1,y,a[y],0);
		}
		else
		{
			a[y]-=x;
			update(sts,0,n-1,y,-x,0);
			mupdate(stm,0,n-1,y,a[y],0);
		}
	}
}