#include <bits/stdc++.h>
using namespace std;
int ans=INT_MAX;
#define MX 8
void check(char a[MX][MX],int ni,int nj,
	char t,int n,int m,int sp)
{
	if(ni>=0 && ni<n && nj>=0 && nj<m && sp<8)
	{
		if(a[ni][nj]==t)
		{printf("ni=%d nj=%d sp=%d\n", ni,nj,sp);
			ans=min(ans,sp);
			return;
		}
		else
		{
			check(a,ni+1,nj+2,t,n,m,sp+1);
			check(a,ni-1,nj+2,t,n,m,sp+1);
			check(a,ni+1,nj-2,t,n,m,sp+1);
			check(a,ni-1,nj-2,t,n,m,sp+1);
			check(a,ni+2,nj-1,t,n,m,sp+1);
			check(a,ni+2,nj+1,t,n,m,sp+1);
			check(a,ni-2,nj-1,t,n,m,sp+1);
			check(a,ni-2,nj+1,t,n,m,sp+1);
		}
	}
}
int main()
{
	char c[MX][MX]={},c1,c2;
	int n1,n2,m1,m2;
	scanf(" %c%d %c%d",&c1,&m1,&c2,&m2);
	n1=c1-97;n2=c2-97;
	m1--;m2--;printf("n1=%d,m1=%d,n2=%d,m2=%d\n",n1,m1,n2,m2);
	c[n2][m2]='@';
	check(c,n1,m1,'@',8,8,0);
	printf("%d\n", ans);
}