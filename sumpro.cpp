#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;
int msum(int a)
{
	int r=(((ll)a*(a+1))/2)%MOD;
	return r;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,ans=0,x=1,a,b,c;
		scanf("%d",&n);
		a=n/x;
		b=n/(x+1);
		c=(int)sqrt(n);
		while(a!=c)
		{
			ans=(ans+a*x+(ll)(msum(a)-msum(b))*x)%MOD;
			a=b;
			x++;
			b=n/(x+1);
		}
		if(a>=x)
			ans=(ans+(a*a)%MOD)%MOD;
		printf("%d\n", ans);
	}
	return 0;
}