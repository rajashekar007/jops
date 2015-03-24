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
		int upto,a,i,mx=-1,cnt=0;
		scanf("%d",&a);
		upto=a;
		mx=a;
		cnt=1;
		for(i=1;i<n;i++)
		{
			scanf("%d",&a);
			upto=max(upto+a,a);
			if(upto>mx)
			{
				mx=upto;
				cnt=1;
			}
			else if(upto==mx)
				cnt++;
		}
		printf("%d %d\n", mx,cnt);
	}
	return 0;
}