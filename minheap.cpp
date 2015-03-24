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
		while(p!=i && a[p]>a[i])
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
		while((c1<size && a[p]>a[c1]) || (c2<size && a[p]>a[c2]))
		{
			if(c1<size && a[p]>a[c1])
			{
				if((c2<size && a[c1]<a[c2]) || c2>=size)
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
			else if(c2<size && a[p]>a[c2])
			{
				if((c1<size && a[c2]<a[c1]) || c1>=size)
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
int main()
{
	heap h(10);
	h.ins(4);
	h.ins(2);
	h.ins(6);
	h.ins(7);
	h.ins(3);
	h.print();
	h.del();
	h.print();
	h.del();
	h.print();
	h.del();
	h.print();
	
	return 0;
}