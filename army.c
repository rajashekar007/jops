#include <stdio.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t-->0)
	{
		int m,n;
		scanf("%d%d",&m,&n);
		int i,j,maxm,maxn,a;
		scanf("%d",&maxm);
		for(i=1;i<m;i++)
		{
			scanf("%d",&a);
			if(a>maxm)
				maxm=a;
		}
		scanf("%d",&maxn);
		for(i=1;i<n;i++)
		{
			scanf("%d",&a);
			if(a>maxn)
				maxn=a;
		}
		if(maxn>maxm)
			printf("MechaGodzilla\n");
		else
			printf("Godzilla\n");
	}
	return 0;
}