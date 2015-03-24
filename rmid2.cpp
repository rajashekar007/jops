#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
#define SIZE 100007

void maxheapify(long long *a,long long s)
{
	if(s>0)
	{
		long long parent=(s-1)/2;
		if(a[parent]<a[s])
		{
			swap(a[parent],a[s]);
			maxheapify(a,parent);
		}
	}
}
void addtomaxheap(long long *a,long long *size,long long data)
{
	long long t=*size;
	a[t]=data;
	maxheapify(a,t);
	*size=(*size)+1;
}
void maxdown(long long *a,long long p,long long s)
{
	long long l=2*p+1,r=2*p+2;
	if(r<s && (a[p]<a[l] || a[p]<a[r]))
	{
		if(a[l]<a[r] && a[p]<a[r])
		{
			swap(a[r],a[p]);
			maxdown(a,r,s);
		}
		else if(a[p]<a[l])
		{
			swap(a[l],a[p]);
			maxdown(a,l,s);
		}
	}
	else if(l<s && a[p]<a[l])
	{
		swap(a[l],a[p]);
		maxdown(a,l,s);
	}
}
long long delmax(long long *a,long long *s)
{
	long long t=*s-1,r=a[0];
	a[0]=a[t];
	*s=t;
	maxdown(a,0,t);
	return r;
}

void minheapify(long long *a,long long s)
{
	if(s>0)
	{
		long long parent=(s-1)/2;
		if(a[parent]>a[s])
		{
			swap(a[parent],a[s]);
			minheapify(a,parent);
		}
	}
}
void addtominheap(long long *a,long long *size,long long data)
{
	long long t=*size;
	a[t]=data;
	minheapify(a,t);
	*size=(*size)+1;
}
void mindown(long long *a,long long p,long long s)
{
	long long l=2*p+1,r=2*p+2;
	if(r<s && (a[p]>a[l] || a[p]>a[r]))
	{
		if(a[l]>a[r] && a[p]>a[r])
		{
			swap(a[r],a[p]);
			mindown(a,r,s);
		}
		else if(a[p]>a[l])
		{
			swap(a[l],a[p]);
			mindown(a,l,s);
		}
	}
	else if(l<s && a[p]>a[l])
	{
		swap(a[l],a[p]);
		mindown(a,l,s);
	}
}
long long delmin(long long *a,long long *s)
{
	long long t=*s-1,r=a[0];
	a[0]=a[t];
	*s=t;
	mindown(a,0,t);
	return r;
}


int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long h1[SIZE],h2[SIZE],s1=0,s2=0;
		long long n;
		scanf("%lld",&n);
		addtomaxheap(h1,&s1,n);
		while(1)
		{
			scanf("%lld",&n);
			if(n>0)
			{
				if(n<h1[0])
					addtomaxheap(h1,&s1,n);
				else
					addtominheap(h2,&s2,n);
				if(s1-s2>1)
				{
					addtominheap(h2,&s2,delmax(h1,&s1));
				}
				if(s2-s1>1)
				{
					addtomaxheap(h1,&s1,delmin(h2,&s2));
				}
			}
			else if(n<0)
			{
				if(s1>=s2)
					printf("%lld\n", delmax(h1,&s1));
				else
					printf("%lld\n",delmin(h2,&s2));
			}
			else
			{
				break;
			}
		}
	}
	return 0;
}