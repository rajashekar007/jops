#include <stdio.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int x,y;
		int ans=-1;
		scanf("%d %d",&x,&y);
		if(x==y)
		{
			if(x%2)
			{
				ans=x+x-1;
			}
			else
			{
				ans=x+x;
			}
		}
		else if(x-y==2)
		{
			if(x%2)
			{
				ans=x+y-1;
			}
			else
			{
				ans=x+y;
			}
		}
		if(ans==-1)
		{
			printf("No Number\n");
		}
		else
		{
			printf("%d\n", ans);
		}
	}
}