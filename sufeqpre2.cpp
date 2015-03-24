#include <bits/stdc++.h>
using namespace std;
#define MX 1000009
int zfun(char *s,int n)
{
	int z[MX]={},cnt=0,l=0,r=0;
	z[0]=n;
	for(int i=1;i<n;i++)
	{
		if(i<=r)
			z[i]=min(r-i+1,z[i-l]);
		while((i+z[i])<n && s[z[i]]==s[i+z[i]])
			z[i]++;
		if((i+z[i]-1)>r)
		{
			l=i;
			r=i+z[i]-1;
		}
		if(z[i]==(n-i))
			cnt++;
	}
	return cnt;
}
int main()
{
	int t,i,n;
	scanf("%d",&t);
	char s[MX];
	for(i=1;i<=t;i++)
	{
		scanf("%s",s);
		printf("Case %d: %d\n", i,zfun(s,strlen(s)));
	}
}