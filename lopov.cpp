#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <utility>
using namespace std;
struct node
{
	int data;
	node *l,*r;
	node(int d)
	{
		data=d;
		l=NULL;
		r=NULL;
	}
};
node* bst(int *a,int m,int n)
{
	if(m>n)
		return NULL;
	int mid=(m+n)/2;
	node *root=new node(a[mid]);
	root->l=bst(a,m,mid-1);
	root->r=bst(a,mid+1,n);
	return root;
}
int ciel(node *h,int key)
{
	if(h!=NULL)
	{
		if(h->data==key)
			return key;
		else if(h->data > key)
		{	
			int t=ciel(h->l,key);
			if(t>=key)
				return t;
			else
				return h->data;
		}
		else
		{
			return ciel(h->r,key);
		}
	}
	return -1;
}
struct node* del(node *h,int key)
{
	if (h==NULL)
		return NULL;
	if (h->data > key)
		h->l=del(h->l,key);
	else if(h->data < key)
		h->r = del(h->r,key);
	else
	{
		if(h->l==NULL)
		{
			node *t=h->r;
			free(h);
			return t;
		}
		else if(h->r==NULL)
		{
			node *t=h->l;
			free(h);
			return t;
		}
		node *t=h->r;
		while(t->l!=NULL)
			t=t->l;
		h->data=t->data;
		h->r=del(h->r,t->data);
	}
	return h;
}
bool fun(pair<int,int> p1,pair<int,int> p2)
{
	return p1.second>p2.second;
}

main()
{
	int n,k,i,j,a,b,c[300007],ci;
	scanf("%d%d",&n,&k);
	pair<int,int> mv[300007];
	for(i=0;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		mv[i]=make_pair(a,b);
	}
	for(i=0;i<k;i++)
		scanf("%d",&c[i]);
	sort(c,c+k);
	sort(mv,mv+n,fun);
	node *bintree=bst(c,0,k-1);
	long long ans=0;
	for(i=0;i<n && j<k;i++)
	{
		ci=ciel(bintree,mv[i].first);
		if(ci!=-1)
		{
			ans+=mv[i].second;
			bintree=del(bintree,ci);
			j++;
		}

	}
	printf("%lld\n", ans);
}