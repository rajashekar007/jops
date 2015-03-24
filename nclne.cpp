#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int a,i,cj=1;
		for(i=0;i<n-1;i++)
		{
			scanf("%d",&a);
			cj-=a;
			cj=cj<<1;
		}
		scanf("%d",&a);
		if(cj==a)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}