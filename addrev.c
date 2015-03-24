#include <stdio.h>
int reverse_int(int n)
{
	int ans=0;
	while(n>0)
	{
		ans=10*ans+n%10;
		n=n/10;
	}
	return ans;
}
int reverse_sum(int x,int y)
{
	return reverse_int(reverse_int(x)+reverse_int(y));
}
int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		printf("%d\n", reverse_sum(x,y));
	}
	return 0;
}