#include <stdio.h>
#include <math.h>
#define LT 100007
int p[LT]={0};
int S[LT];
int PS;
void gen_p()
{
	PS=0;
	int i,up=(int)sqrt((double)LT);
	for(i=2;i<LT;i++)
	{
		S[i]=1;
	}
	for(i=2;i<=up;i++)
	{
		if(S[i])
		{
			int j;
			for(j=i*i;j<=LT;j+=i)
			{
				S[j]=0;
			}
		}
	}
	for(i=2;i<LT;i++)
	{
		if(S[i]==1)
		{
			p[PS++]=i;
		}
	}
}
int max(int i,int j)
{
	return i>j?i:j;
}
int main()
{
	gen_p();
	int n;
	while(!feof(stdin) && (scanf("%d",&n)))
	{
		n--;
		if(p[n]==0)
		{

			int i;
			for(i=max(LT,p[PS-1]+1);PS!=n+1;i++)
			{
				int j,sn=(int)sqrt((double)1299827);
				for(j=0;j<PS && p[j]<=sn;j++)
				{
					if(i%p[j]==0)
						break;
				}
				if(p[j]>sn)
				{
					p[PS++]=i;
				}
			}
		}
		printf("%d\n", p[n]);
	}
	return 0;
}