#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 1000009
ll e[MAX]={};
int main()
{
	int b[MAX]={},a[MAX]={},n,i,l;
	ll m,v=0;
	scanf("%d%lld ",&n,&m);
	// char tp[2];
	// gets(tp);
	for(i=1;i<=n;i++)
	{
		char c[20]={};
		// scanf("%s",c);
		gets(c);
		if(c[0]=='c')
			b[i]=0;
		else if(c[0]=='g')
		{
			b[i]=atoi(c+5);
		}
		else
		{
			b[i]=-1;
			a[atoi(c)]=i;
		}
	}
	// for(i=1;i<=n;i++)
	// 	cout<<b[i]<<",";
	for(i=1;i<=n;i++)
		e[i]=-1;
	i=1;
	while(1)
	{
		if(b[i]==0)
		{
			v++;
			if(v==m)
			{
				printf("%d\n", i);
				return 0;
			}	
			i++;
		}
		else if(b[i]==-1)
		{

			if(e[i]==v)
			{
				printf("TLE\n");
				return 0;
			}
			else if(e[i]!=-1)
			{
				ll rv=v-e[i],quo;
				quo=(m-v)/rv;
				if((m-v)%rv==0)
					v+=(quo*rv)-rv;
				else
					v+=(quo*rv);
			}
			e[i]=v;
			i++;
		}
		else
		{
			i=a[b[i]];
		}
		if(i>n)
		{
			printf("WA\n");
			return 0;
		}
	}
	return 0;
}