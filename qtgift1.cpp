#include <bits/stdc++.h>
using namespace std;
int mx=-1;
void gift(int *a,int j,int i,int n,int s,int k)
{
	if(i==n)
	{
		if(s>mx)
			mx=s;
	}
	else if(j==k)
	{
		gift(a,1,i+1,n,s,k);
	}
	else
	{
		gift(a,j+1,i+1,n,s+a[i],k);
		gift(a,j+1,i+1,n,s,k);
	}
}
int main()
{
	int n,k,a[1000009]={};
	scanf("%d%d",&n,&k);
	int i;
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	gift(a,1,0,n,0,k);
	printf("%d\n", mx);
	return 0;
}