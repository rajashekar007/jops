#include <bits/stdc++.h>
using namespace std;
int zfun(char s[],int n)
{
	int z[1000007]={},l=0,r=0,i=1,cnt=0;
	memset(z,0,1000007);
	z[0]=n;
	
	for(i=1;i<n;i++)
	{
		if(i<=r)
			z[i]=min(r-i+1,z[i-l]);
		while ((i+z[i])<n && (s[z[i]]==s[i+z[i]]))
			z[i]++;
		if((i+z[i]-1)>r)
		{
			l=i;
			r=i+z[i]-1;
		}
		if(z[i]==n-i)
			cnt++;
	}
	return cnt;
}
int main()
{
	int t,i;
	char s[1000007]={};
	scanf("%d ",&t);
	for(i=1;i<=t;i++)
	{
		gets(s);
		// scanf("%s",s);
		int ln=strlen(s);
		printf("Case %d: %d\n",i,zfun(s,ln));
	}
	return 0;
}