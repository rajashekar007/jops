#include <stdio.h>
#include <algorithm>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,i,j,flag=0;
		scanf("%d",&n);
		double a[n],s;
		for(i=0;i<n;i++)
			scanf("%lf",&a[i]);
		sort(a,a+n);
		j=n-1;
		for(i=0;i<j;)
		{
			if(a[i]+a[j]<=1)
				i++;
			else if(a[i]+a[j]>=2)
				j--;
			else
			{
				flag=1;
				break;
			}
		}
		if(flag==1)
			printf("found\n");
		else
			printf("not found\n");
	}
	return 0;
}