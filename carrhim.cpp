#include <bits/stdc++.h>
using namespace std;
int main()
{
	char c;
	while(scanf(" %c",&c)!=EOF)
	{
		int x,w,b,r,tw=0,tb=0,re=-1,p=0,y=0;
		if(c=='A' || c=='C')
			x=0;
		else if(c!='#')
			x=1;
		else
		{
			printf("Incomplete game.\n");
			continue;
		}
		scanf("%d%d%d",&w,&b,&r);
		tw+=w;
		tb+=b;
		if(r>0)
			re=x;
		y=x;
		while(1)
		{
			w=0;b=0;r=0;
			scanf(" %c",&c);
			if(c=='#')
				break;
			else
			{
				if(c=='A' || c=='C')
					y=0;
				else
					y=1;
				// y=(y+1)%2;
				scanf("%d%d%d",&w,&b,&r);
				// printf("%d %d %d\n", w,b,r);
				tw+=w;
				tb+=b;
				if(r>0)
					re=y;
			}
		}
		printf("%d %d %d\n", tw,tb,re);
		if(tw==9 && re==x)
		{

			printf("Team-%d win and the point is %d.\n",x+1,9-tb+5);
		}
		else if(tb==9 and re==(x+1)%2)
		{
			printf("Team-%d win and the point is %d.\n", (x+1)%2+1,9-tw+5);
		}
		else
			printf("Incomplete game.\n");
		// scanf("%c",&c);
	}
	return 0;
}