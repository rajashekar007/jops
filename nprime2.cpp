#include <stdio.h>
#include <math.h>
#define LT 1000007
int p[LT]={0};
int PS;
void gen_p()
{
	PS=0;
	int S[LT]={1};
	int i,up=(int)sqrt((double)LT);
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
int main()
{
	gen_p();
	int n;
	while(!feof(stdin) && (scanf("%d",&n)))
	{
		n--;
		printf("%d\n", p[n]);
	}
	return 0;
}