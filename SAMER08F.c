#include <stdio.h>
int main()
{
	while(1)
	{
		int n;
		scanf("%d",&n);
		if(n==0)
			break;
		printf("%d\n", (n*(n+1)*(2*n+1))/6);
	}
	return 0;
}