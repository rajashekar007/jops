#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
int root(int *a,int c)
{
	if(a[c]==-1)
		return c;
	else
		return root(a,a[c]);
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m,a[1007]={},ar[1007]={},i,j,c,d;
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++)
			a[i]=-1;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&ar[i]);
		}
		for(i=1;i<=m;i++)
		{
			scanf("%d%d",&c,&d);
			if(c>d)
				swap(c,d);
			a[root(a,d)]=root(a,c);
		}
		for(i=1;i<=n;i++)
		{
			int pj=i;
			for(j=i;j!=-1;)
			{
				if(ar[j]>ar[pj] && root(a,pj)==root(a,j))
				{
					swap(ar[j],ar[pj]);					
				}
				pj=j;
				j=a[j];
				cout<<j<<",";
			}
		}
		for(i=1;i<=n;i++)
			cout<<ar[i]<<" ";
		cout<<endl;
	}
	return 0;
}