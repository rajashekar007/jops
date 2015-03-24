#include <bits/stdc++.h>
using namespace std;
#define MX 1000009
int main()
{
	int n,k,a[MX]={},sum=0;
	scanf("%d%d",&n,&k);
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		sum+=a[i];
	}	
	int j,temp,mn=INT_MAX;
	for(i=0;i<k;i++)
	{
		temp=a[i];
		for(j=i+k;j<n;j+=k)
		{
			temp+=a[j];
		}
		if(mn>temp)
			mn=temp;
	}
	printf("%d\n", sum-mn);
	return 0;
}