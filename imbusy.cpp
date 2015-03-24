#include <bits/stdc++.h>
using namespace std;
struct activity
{
	int s,f;
};
bool fun(activity a,activity b)
{
	return a.f<b.f;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,i,lf,cnt=1;
		scanf("%d",&n);
		activity a[n];
		for(i=0;i<n;i++)
			scanf("%d%d",&a[i].s,&a[i].f);
		sort(a,a+n,fun);
		lf=a[0].f;
		for(i=1;i<n;i++)
		{
			if(a[i].s>=lf)
			{
				cnt++;
				lf=a[i].f;
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}