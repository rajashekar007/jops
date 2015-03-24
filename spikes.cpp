#include <bits/stdc++.h>
using namespace std;
int ans=INT_MAX,ans1;
void check(char a[43][43],int si,int sj,
	int pi,int pj,int ni,int nj,
	char t,int n,int m,int sp)
{
	// printf("ni = %d,nj=%d n=%d m=%d, pi=%d pj=%d\n", ni,nj,n,m,pi,pj);
	if(ni>=0 && ni<n && nj>=0 && nj<m && (pi!=ni || pj!=nj) 
		&& a[ni][nj]!='#' && (ni!=si || nj!=sj))
	{
		if(a[ni][nj]==t)
		{
			ans=min(ans,sp);
			// printf("sp = %d\n", sp);
			return;
		}
		else
		{
			char tc=a[ni][nj];
			int ts=sp;
			if(a[ni][nj]=='s')
				ts=sp+1;
			a[ni][nj]='#';
			check(a,si,sj,ni,nj,ni+1,nj,t,n,m,ts);
			check(a,si,sj,ni,nj,ni,nj+1,t,n,m,ts);
			check(a,si,sj,ni,nj,ni-1,nj,t,n,m,ts);
			check(a,si,sj,ni,nj,ni,nj-1,t,n,m,ts);
			a[ni][nj]=tc;
		}
	}
	// printf("inside check\n");
}
int main()
{
	char c[43][43];
	int n,m,j,i,k,si,sk,ti,tk;
	scanf("%d%d%d",&n,&m,&j);
	for(i=0;i<n;i++)
	{
		scanf("%s",c[i]);
		for(k=0;k<m;k++)
		{
			if(c[i][k]=='@')
			{
				si=i;
				sk=k;
			}
			if(c[i][k]=='x')
			{
				ti=i;
				tk=k;
			}
		}
	}
	// printf("si = %d,sk=%d\n", si,sk);
	check(c,si,sk,si,sk,si+1,sk,'x',n,m,0);
	check(c,si,sk,si,sk,si,sk+1,'x',n,m,0);
	check(c,si,sk,si,sk,si-1,sk,'x',n,m,0);
	check(c,si,sk,si,sk,si,sk-1,'x',n,m,0);
	// printf("ans = %d\n", ans);
	ans1=ans;
	ans=INT_MAX;
	check(c,ti,tk,ti,tk,ti+1,tk,'@',n,m,0);
	check(c,ti,tk,ti,tk,ti,tk+1,'@',n,m,0);
	check(c,ti,tk,ti,tk,ti-1,tk,'@',n,m,0);
	check(c,ti,tk,ti,tk,ti,tk-1,'@',n,m,0);
	// printf("ans = %d\n", ans);
	// for(i=0;i<n;i++)
	// {
	// 	for(k=0;k<m;k++)
	// 	{
	// 		printf("%c", c[i][k]);
	// 	}
	// 	printf("\n");
	// }
	if(ans1+ans<=j)
		printf("SUCCESS\n");
	else
		printf("IMPOSSIBLE\n");

}