#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>
using namespace std;
int root(int *a,int c)
{
	if(a[c]==-1)
		return c;
	else
		return root(a,a[c]);
}
int a[1007];
struct snode{
	int data,ind;
};
bool fun(snode *c,snode *d)
{
	if (c->data<d->data && root(a,c->ind)==root(a,d->ind))
	{
		cout<<"c->ind ="<<c->ind<<c->data<<", d->ind = "<<d->ind<<d->data;
		swap(c->ind,d->ind);
		cout<<"c->ind ="<<c->ind<<c->data<<", d->ind = "<<d->ind<<d->data;
		return 1;
	}
	return 0;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m,i,j,c,d;
		snode *ar[1007];
		scanf("%d%d",&n,&m);
		for(i=0;i<1007;i++)
		{
			a[i]=-1;
			ar[i]=new snode();
		}
		for(i=1;i<=n;i++)
		{
			ar[i]->ind=i;
			scanf("%d",&ar[i]->data);
		}
		for(i=1;i<=m;i++)
		{
			scanf("%d%d",&c,&d);
			if(c>d)
				swap(c,d);
			a[root(a,d)]=root(a,c);
		}
		sort(ar+1,ar+n+1,fun);
		for(i=1;i<=n;i++)
		{
			cout<<ar[i]->data<<", "<<ar[i]->ind<<"   ";
		}	
		cout<<endl;
	}
	return 0;
}