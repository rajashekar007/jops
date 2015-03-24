#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
// int msb(ull a)
// {
// 	int r=1;
// 	ull p=2;
// 	while(a/p!=0)
// 	{
// 		p=p*2;
// 		r++;
// 	}
// 	return r;
// }
ll p2[65];
int msb(ll a)
{
	int l=0,r=61,m;
	while(l!=r)
	{
		m=(l+r)/2;
		if(p2[m]==a)
			return m;
		else if(p2[m]>a)
		{
			if(p2[m-1]<=a)
				return m-1;
			r=m-1;
		}
		else
		{
			if(p2[m+1]>a)
				return m;
			l=m+1;
		}
	}
	return m;
}
int main()
{
	int n,i;
	p2[1]=1;
	for(i=2;i<65;i++)
		p2[i]=p2[i-1]*2;
	ll a;
	// a=(1<<60);
	// printf("%lld\n", a);
	scanf("%lld",&a);

	printf("%d\n", msb(a));
	return 0;
}