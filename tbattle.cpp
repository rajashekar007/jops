#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int sz=-1,md;
int constsegtree(int *tr,int *ar,int l,int h,int i)
{
	if(l==h)
	{
		tr[i]=ar[l]%md;
		sz=max(i,sz);
		return tr[i];
	}
	int m=(l+h)/2;
	tr[i]=((ll)constsegtree(tr,ar,l,m,2*i+1)*constsegtree(tr,ar,m+1,h,2*i+2))%md;
	return tr[i];
}
int ansl,ansh,mn=INT_MAX;
void treetraverse(int *tr,int l,int h,int i)
{
	if(i<=sz && l<=h)
	{
		int m=(l+h)/2;
		treetraverse(tr,l,m,2*i+1);
		treetraverse(tr,m+1,h,2*i+2);
		if(tr[i]==0)
		{printf("i=%d tr[i]=%d, l=%d, h=%d\n",i, tr[i],l,h);
			if(h-l<mn)
			{
				mn=h-l;
				ansl=l;
				ansh=h;
			}
			// else if(h-l==mn)
			// {
			// 	ansl=min(ansl,l);
			// 	ansh=min(ansh,h);
			// }
		}
	}
}
int main()
{
	int n,a[100009],tr[300009]={},i;
	for(i=0;i<300009;i++)
		tr[i]=-1;
	scanf("%d",&n);
	md=n;
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	constsegtree(tr,a,0,n-1,0);
	treetraverse(tr,0,n-1,0);
	for(i=0;i<=sz;i++)
		printf("%d,", tr[i]);
	printf("\n");
	if(mn==INT_MAX)
		printf("-1\n");
	else
		printf("%d %d\n", ansl,ansh);
	return 0;
}