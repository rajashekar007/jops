#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int ch[100000000];
#define e {{1,1},{1,0}}
int q,t,a,b,c,x;
void mul(int f[2][2],int m[2][2])
{
	x=f[1][0];
	f[1][0]=(f[1][0]+f[1][1])%q;
	f[1][1]=x;
	f[0][0]=(f[0][0]+f[0][1])%q;
	f[0][1]=f[1][0];
}
void p1(int f[2][2],int n)
{
	if(n>1)
	{
		int m[2][2]=e;
		p1(f,n/2);
		mul(f,f);
		if(n%2)
			mul(f,m);
	}
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d%d",&a,&b,&c,&q);
		int f[2][2]=e;
		p1(f,c);
		printf("%lld\n", (((ll)f[0][0]*b)%q+((ll)f[0][1]*a)%q-(b%q)+q)%q);
	}
}