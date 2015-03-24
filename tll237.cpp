#include <bits/stdc++.h>
using namespace std;
typedef int ll;
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
			printf("%d,", a[i]);
		printf("\n");
	}
};
int main()
{
	int n;
	scanf("%d",&n);
	heap h(n+1);
	int i,val1,val2;
	for(i=0;i<n;i++)
		h.ins(0);
	char s[100009]={};
	scanf("%s",s);
	for(i=0;i<strlen(s);i++)
	{
		if(s[i]=='1')
		{
			val1=h.del();
			val1++;
			h.ins(val1);
		}
		else
		{
			val1=h.del();
			val2=h.del();
			val2++;
			h.ins(val1);
			h.ins(val2);
		}
	}
	val1=h.del();
	val2=h.del();
	printf("%d %d\n", val1,val2);
	return 0;
}