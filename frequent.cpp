//this is for range sum application
#include <stdio.h>
#include <limits.h>
using namespace std;
typedef long long ll;
int max(int x,int y)
{
	return x>y?x:y;
}
int mcst(int *a,int *st,int l,int r,int si)
{
	if(l==r)
	{
		st[si]=a[l];
		return st[si];
	}
	int m=l+(r-l)/2;
	st[si]=max(mcst(a,st,l,m,2*si+1),mcst(a,st,m+1,r,2*si+2));
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
		return INT_MIN;
	}
	int mid=ss+(se-ss)/2;
	return max(mgets(st,ss,mid,qs,qe,2*si+1),mgets(st,mid+1,se,qs,qe,2*si+2));
}

int main()
{
	while(1)
	{	int n,q,i,p,l,j=0,f=1,k;
		scanf("%d",&n);
		if(n==0)
			break;
		scanf("%d",&q);
		int a[100007],b[100007],e[100007],s[100007],start;
		scanf("%d",&p);
		start=0;
		for(i=1;;i++)
		{
			if(i<n)
			{
				scanf("%d",&l);
				b[i]=l;
			}
			if(l!=p || i==n)
			{
				for(k=0;k<f;k++)
				{
					a[j+k]=f;
					e[j+k]=i-1;
					s[j+k]=start;
				}
				j=j+f;
				p=l;
				f=1;
				start=i;
				if(i==n)
					break;
			}
			else
			{
				f++;
			}
		}
		for(i=0;i<n;i++)
			printf("%d,", a[i]);printf("\n");
		// for(i=0;i<n;i++)
		// 	printf("%d,", s[i]);printf("\n");
		// for(i=0;i<n;i++)
		// 	printf("%d,", e[i]);printf("\n");
		int st[300007]={};
		mcst(a,st,0,n-1,0);
		for(i=0;i<q;i++)
		{
			int x,y,m1=INT_MIN,m2=INT_MIN,m3=INT_MIN,m4=INT_MIN;
			scanf("%d %d",&x,&y);
			x--;y--;
			if(x!=y)
			{	
				if(s[x]!=x)
				{
					if(e[x]<=y)
					{
						m1=e[x]-x+1;
						x=e[x]+1;
					}
					else
					{
						m1=y-x+1;
					}
				}
				if(e[y]!=y)
				{
					if(s[y]>=x)
					{
						m2=y-s[y]+1;
						y=s[y]-1;
					}
					else
					{
						m2=y-x+1;
					}
				}
				m3=max(m1,m2);//printf("m3=%d\n", m3);
				if(x<y)
					m4=mgets(st,0,n-1,x,y,0);
				else 
					m4=1;
				printf("%d\n",max(m3,m4));
			}
			else
				printf("1\n");
		}
	}
}