#include <stdio.h>
int a;
void ways(int x,int y,int m)
{
	if(x==m && y==m)
		a++;
	else if(x<=m && y<=m)
	{
		ways(x+1,y,m);
		ways(x,y+1,m);
	}
}
int main()
{
	int i;
	for(i=1;i<=20;i++)
	{
		a=0;
		ways(0,0,i);
		printf("%d\n", a);
	}
	return 0;
}