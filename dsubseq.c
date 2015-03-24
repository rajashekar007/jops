#include <stdio.h>
#include <string.h>
int m=1000000007;
int mod(int x)
{
	return (x%m +m)%m;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t-->0)
	{
		char s[100001]={};
		scanf("%s",s);
		int sd[100001]={0};
		sd[0]=1;
		int i,l[256]={-1},n=strlen(s);
		// printf("%d\n", n);
		for(i=1;i<=n;i++)
		{
			if(l[s[i-1]]>0)
			{
				sd[i]=mod(2*sd[i-1]-sd[l[s[i-1]]-1]);
			}
			else
			{
				sd[i]=mod(2*sd[i-1]);
			}
			l[s[i-1]]=i;
		}
		printf("%d\n",sd[n]);
	}
	return 0;
}
