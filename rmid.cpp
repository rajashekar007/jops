#include <iostream>
#include <stdio.h>
using namespace std;
struct node
{
	int d;
	node *l,*r;
	node()
	{
		d=-1;
		l=NULL;
		r=NULL;
	}
	node(int a)
	{
		d=a;
		l=NULL;
		r=NULL;
	}
};
int main()
{
	int a,cnt=0;
	node *ar=new node();
	node *mid=ar;
	node *tail=ar;
	while(!feof(stdin) && scanf ( "%d", &a) ==1)
	{
		if(a>0)
		{
			node *temp=new node(a);
			tail->r=temp;
			temp->l=tail;
			tail=temp;
			cnt++;
			if(cnt%2==1)
			{
				mid=mid->r;
			}
		}
		else if(a==0)
		{
			ar=new node();
			mid=ar;
			tail=ar;
			cnt=0;
			printf("\n");
		}
		else
		{
			printf("%d\n", mid->d);
			if(cnt%2==0)
			{
				node *t=mid->l;
				t->r=mid->r;
				mid->r->l=t;
				mid=t->r;
			}
			else
			{
				node *t=mid->l;
				t->r=mid->r;
				mid->r->l=t;
				mid=t;
			}
			cnt--;
		}

	}
	return 0;
}