#include <stdio.h>
void merge(int *a,int l,int m,int h)
{
	int temp[h+1];
	int i=l,j=m+1,k=l;
	while (i<=m && j<=h)
	{
		if(a[i]<a[j])
		{
			temp[k++]=a[i++];
		}
		else
		{
			temp[k++]=a[j++];
		}
	}
	while(i<=m)
		temp[k++]=a[i++];
	while(j<=h)
		temp[k++]=a[j++];
	for(i=l;i<=h;i++)
		a[i]=temp[i];
}
void mergesort(int *a,int l,int h)
{
	if(h>l)
	{
		int m=(l+h)/2;
		mergesort(a,l,m);
		mergesort(a,m+1,h);
		merge(a,l,m,h);
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,i;
		scanf("%d",&n);
		int a[n+1];
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		mergesort(a,0,n-1);
		for(i=0;i<n;i++)
			printf("%d\n", a[i]);
		printf("\n");

	}
}