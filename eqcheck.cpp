#include <bits/stdc++.h>
using namespace std;
int a,b,c,t,r,p;
int gcd()
{	r=a%b;
	while(r)
	{
		a=b;
		b=r;
		r=a%b;
	}
	return b;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		char d;
		scanf("%d%c%c%d%c%c%d",&a,&d,&d,&b,&d,&d,&c);
		if(a<b)
		{
			p=a;a=b;b=p;
		}
		if(c%gcd())
			printf("no\n");
		else
			printf("yes\n");
	}
	return 0;
}