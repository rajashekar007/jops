#include <stdio.h>
#include <math.h>
int main()
{
int a,b,c,n,i,d;
while(!feof(stdin) && scanf("%d",&n)==1)
{
i=0;
for(a=0;a<(int)(sqrt(n));a++)
{
b=n-(a*a);
d=(int)sqrt(b);
if(d>=a)
{
if(b==d*d)
i++;
}
else
break;
}
printf("%d\n", i);
}
return 0;
}