#include <stdio.h>
int t,n,a[]={2,6,20,70,252,924,3432,12870,48620,184756,705432,2704156,10400600,40116600};
l="%d\n";
main()
{
	scanf(l,&t);
	while(t--)
	{	scanf(l,n);
		printf(l,a[n-1]);}
}