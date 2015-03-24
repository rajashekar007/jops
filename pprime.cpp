#include <stdio.h>
#include <math.h>
#define LT 1390007
int p[LT]={};
int PS;
void gen_p()
{
	int S[LT]={};
	int i,up=(int)sqrt((double)LT);
	for(i=1;i<LT;i++)
		S[i]=1;
	for(i=2;i<=up;i++)
	{
		if(S[i])
		{
			int j;
			for(j=i+i;j<=LT;j+=i)
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
	gen_p();int i;
	int cnt=0;
	for(i=0;p[i]<PS;i++)
	{
		printf("%d ",p[p[i]-1]);
		cnt++;
		if(cnt==10000)
			break;
	}
	return 0;
}