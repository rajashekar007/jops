#include <stdio.h>
int main()
{
	long long n;
	scanf("%lld",&n);
	if(((n-1)&n) ==0)
		printf("TAK\n");
	else
		printf("NIE\n");
	return 0;
}