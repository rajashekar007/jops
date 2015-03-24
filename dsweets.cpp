#include <bits/stdc++.h>
using namespace std;
#define MAX 1000007
typedef long long ll;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m,i,tm,flag=1,allzero=1,marks[MAX],ts=0;
		ll sm=0,k;
		scanf("%d%d",&n,&m);
		for(i=0;i<m;i++)
		{
			scanf("%d",&tm);
			marks[i]=tm;
			if(tm==0)
				flag=0;
			else
				allzero=0;
			sm+=tm;
		}
		if((n==0 && m!=0) || (m==0 && n!=0))
			printf("NO\n");
		else if(n==0 && m==0)
			printf("YES\n");
		else
		{
			if(m>n)
				printf("NO\n");
			else
			{
				if(allzero)
					printf("YES\n");
				else if(flag==0)
					printf("NO\n");
				else
				{
					int fg=0;
					for(i=0;i<m;i++)
					{
						if(((ll)marks[i]*n)%sm==0)
						{
							k=((ll)marks[i]*n)/sm;
							if(k==0)
							{
								fg=1;
								break;
							}
							ts+=k;
						}
						else
						{
							fg=1;
							break;
						}
					}
					if(fg==1 || ts!=n)
						printf("NO\n");
					else
						printf("YES\n");
				}
			}
		}

	}
	return 0;
}