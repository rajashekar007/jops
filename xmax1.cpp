#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
#define MAX 100007
struct heap
{
	ll *a;
	int size;
	heap(int MSIZE)
	{
		a=new ll[MSIZE];
		size=0;
	}
	void ins(ll d)
	{
		a[size++]=d;
		int i=size-1,p=(i-1)/2;
		while(p!=i && a[p]<a[i])
		{
			swap(a[p],a[i]);
			i=p;
			p=(i-1)/2;
		}
	}
	ll del()
	{
		ll r=a[0];
		a[0]=a[size-1];
		size--;
		int p=0,c1=1,c2=2;
		while((c1<size && a[p]<a[c1]) || (c2<size && a[p]<a[c2]))
		{
			if(c1<size && a[p]<a[c1])
			{
				if((c2<size && a[c1]>a[c2]) || c2>=size)
				{
					swap(a[p],a[c1]);
					p=c1;
				}
				else
				{
					swap(a[p],a[c2]);
					p=c2;
				}
			}
			else if(c2<size && a[p]<a[c2])
			{
				if((c1<size && a[c2]>a[c1]) || c1>=size)
				{
					swap(a[p],a[c2]);
					p=c2;
				}
				else
				{
					swap(a[p],a[c1]);
					p=c1;
				}
			}
			c1=2*p+1;
			c2=2*p+2;
		}
		return r;
	}
	void print()
	{
		int i;
		for(i=0;i<size;i++)
			printf("%lld,", a[i]);
		printf("\n");
	}
};
ll p2[65];
// int msb(ll a)
// {
// 	if(a==0)
// 		return 0;
// 	int r=1;
// 	ll p=2;
// 	while(a/p)
// 	{
// 		p=p*2;
// 		r++;
// 	}
// 	return r;
// }
int msb(ll a)
{
	int l=0,r=61,m;
	while(l!=r)
	{
		m=(l+r)/2;
		if(p2[m]==a)
			return m;
		else if(p2[m]>a)
		{
			if(p2[m-1]<=a)
				return m-1;
			r=m-1;
		}
		else
		{
			if(p2[m+1]>a)
				return m;
			l=m+1;
		}
	}
	return m;
}
int main()
{
	int n,i;
	p2[1]=1;
	for(i=2;i<65;i++)
		p2[i]=p2[i-1]*2;
	ll k;
	heap h(MAX);
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		h.ins(k);
	}
	vector<ll> rv;
	while(h.size>0 && h.a[0]!=0)
	{
		ll arv=h.a[0];
		rv.push_back(h.a[0]);
		int mb=msb(h.del());
		while(msb(h.a[0])==mb)
		{
			ll b=h.del();
			h.ins(b^arv);
		}
	}
	ll ans=0;
	for(i=0;i<rv.size();i++)
	{
		if(ans<(ans^rv[i]))
		{
			ans=ans^rv[i];
		}
	}
	printf("%lld\n", ans);
	return 0;
}