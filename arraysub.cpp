#include <bits/stdc++.h>
using namespace std;
int max(int *a,int s,int e)
{
	int i,m=a[s];
	for(i=s;i<e;i++)
	{
		if(a[i]>m)
			m=a[i];
	}
	return m;
}
int main()
{
	int n,i,k,m,l;
	scanf("%d",&n);
	int ar[n+1];
	for(i=0;i<n;i++)
		scanf("%d",&ar[i]);
	scanf("%d",&k);
	m=max(ar,0,k);
	printf("%d ", m);
	for(i=k;i<n;i++)
	{
		l=i-k;
		if(ar[l]==m)
			m=max(ar,i-k+1,i+1);
		else if(ar[i]>m)
			m=ar[i];
		printf("%d ", m);
	}
	printf("\n");
}
