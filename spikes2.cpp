#include <bits/stdc++.h>
using namespace std;
int ans=INT_MAX,ans1;
#define MX 100
void check(char a[MX][MX],int ni,int nj,
	char t,int n,int m,int sp)
{
	if(ni>=0 && ni<n && nj>=0 && nj<m && a[ni][nj]!='#' )
	{
		if(a[ni][nj]==t)
		{
			ans=min(ans,sp);
			return;
		}
		else
		{
			char tc=a[ni][nj];
			int ts=sp;
			if(a[ni][nj]=='s')
				ts=sp+1;
			a[ni][nj]='#';
			check(a,ni+1,nj,t,n,m,ts);
			check(a,ni,nj+1,t,n,m,ts);
			check(a,ni-1,nj,t,n,m,ts);
			check(a,ni,nj-1,t,n,m,ts);
			a[ni][nj]=tc;
		}
	}
}
int main()
{
	char c[MX][MX];
	int n,m,j,i,k,ti,tk,flag=0;
	scanf("%d%d%d",&n,&m,&j);
	for(i=0;i<n;i++)
	{
		scanf("%s",c[i]);
		for(k=0;k<m;k++)
		{
			if(c[i][k]=='x')
			{
				ti=i;
				tk=k;
			}
		}
	}
	check(c,ti,tk,'@',n,m,0);
	if(ans!=INT_MAX && 2*ans<=j)
		printf("SUCCESS\n");
	else
		printf("IMPOSSIBLE\n");

}