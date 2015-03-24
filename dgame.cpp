#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;
int smallPow2(unsigned int v)
{	
	v-=1;
	v|=v>>1;
	v|=v>>2;
	v|=v>>4;
	v|=v>>8;
	v|=v>>16;
	v+=1;
	return v>>1;
}
int powmod(int b,int e)
{
	if(e==0)
		return 1;
	if(e==1)
		return b;
	int y=powmod(b,e/2),r;
	r=((ll)y*y)%MOD;
	if(e%2)
		return ((ll)r*b)%MOD;
	else
		return r;

}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		unsigned int n,r;
		scanf("%d",&n);
		int nw,ans;
		nw=powmod(2,n);
		if(n%4==0 || n%4==2)
		{
			// printf("%d\n", n&(n-1));
			if((n&(n-1))==0)
				ans=1;
			else
				ans=n-smallPow2(n)+1;
		}
		else if(n%4==1)
			ans=(n+1)/2;
		else
			ans=0;
		printf("%d %d\n", nw,ans);
	}
	return 0;
}