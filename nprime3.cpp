#include <stdio.h>
#include <math.h>
#define LT 1299827
#define SZ 100007
int main()
{
	int a[LT]={1},p[SZ]={-1},s=0,n,i,j;
	for(i=0;i<LT;i++)
		a[i]=1;
	for(i=2;i<LT;i++)
		if(a[i]==1)
			for(j=i+i;j<LT;j+=i)
				a[j]=0;
	for(i=2;i<LT;i++)
		if(a[i]==1 && s<SZ-1)
			p[s++]=i;
	while(!feof(stdin) && (scanf("%d",&n)==1))
	{
		n--;
		printf("%d\n", p[n]);
	}
	return 0;	
}