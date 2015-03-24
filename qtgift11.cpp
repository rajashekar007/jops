#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,k,a[1000009]={};
	scanf("%d%d",&n,&k);
	int i;
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);

	int lki=a[0],lkni=0,temp;
	for(i=1;i<k-1;i++)
	{
		lki+=a[i];
		lkni+=a[i];
	}
	for(;i<n;i++)
	{
		temp=max(lki,lkni);
		lki=lkni+a[i];
		lkni=temp;
	}
	printf("%d\n", max(lki,lkni));
	return 0;
}