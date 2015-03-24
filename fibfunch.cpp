#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int q,t,a,b,c;
void mul(int f[2][2],int m[2][2])
{
	int w=(((ll)f[0][0]*m[0][0])%q+((ll)f[0][1]*m[1][0])%q)%q,
	x=(((ll)f[0][0]*m[0][1])%q+((ll)f[0][1]*m[1][1])%q)%q,
	z=(((ll)f[1][0]*m[0][1])%q+((ll)f[1][1]*m[1][1])%q)%q;
	f[0][0]=w;
	f[0][1]=x;
	f[1][0]=x;
	f[1][1]=z;
}
void p1(int f[2][2],int n)
{
	if(n>1)
	{
		int m[2][2]={{1,1},{1,0}};
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
		int f[2][2]={{1,1},{1,0}};
		p1(f,c);
		printf("%lld\n", (((ll)f[0][0]*b)%q+((ll)f[0][1]*a)%q-(b%q)+q)%q);
	}
}