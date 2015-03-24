#include <stdio.h>
#include <math.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int a,b,a1,b1,nd,xor,i;
		scanf("%d%d",&a,&b);
		a1=(int)sqrt((float)a);
		b1=(int)sqrt((float)b);
		nd=(a1+1)*(a1+1)-a;
		xor=nd;
		for(i=a1+1;i<b1;i++)
		{
			int j=(i+1)*(i+1)-i*i;
			nd=nd&j;
			xor=xor^j;
		}
		printf("%d\n", nd&xor);
	}
	return 0;
}