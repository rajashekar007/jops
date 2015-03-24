#include <bits/stdc++.h>
using namespace std;
struct box
{
	char b[3];
};
int main()
{
	int t;
	scanf("%d",&t);
	int i,j,bi,bj;
	box b[8][8];
	for(int k=1;k<=t;k++)
	{
		for(i=0;i<8;i++)
		{
			for(j=0;j<8;j++)
			{
				scanf("%s",b[i][j].b);
				if(strcmp(b[i][j].b,"BK")==0)
				{
					bi=i;bj=j;
				}
			}
		}
		// char c[20];
		// // scanf("%s",c);
		// gets(c);
		// printf("c is %s\n", c);
		int check=0;
		for(i=0;i<8;i++)
		{
			for(j=0;j<8;j++)
			{
				if(strcmp(b[i][j].b,"WP")==0)
				{
					// printf("%d %d white pawn\n",i,j);printf("%d %d black king\n",bi,bj);
					if((i-1==bi && j-1==bj) || (i-1==bi && bj==j+1))
					check=1; 
				}
				else if(strcmp(b[i][j].b,"WK")==0)
				{
					if((bi==i-1 && bj==j) || (bi==i-1 && bj==j-1) || (bi==i && bj==j-1) 
						|| (bi==i-1 && bj==j+1) || (bi==i && bj==j+1) || (bi==i+1 && bj==j+1) 
						||(bi==i+1 && bj==j) || (bi==i+1 && bj==j-1))
					check=1;
				}
				else if(strcmp(b[i][j].b,"WH")==0)
				{
					if((bi==i-2 && bj==j+1)||(bi==i-1 && bj==j+2)||(bi==i+1 && bj==j+2)||
						(bi==i+2 && bj==j+1)||(bi==i+2 && bj==j-1)||(bi==i+1 && bj==j-2)||
						(bi==i-1 && bj==j-2)||(bi==i-2 && bj==j-1))
						check=1;
				}
				if(check==1)
					break;
			}
			if(check==1)
				break;
		}
		if(check==1)
			printf("Case #%d: Check\n",k);
		else
			printf("Case #%d: Not Check\n",k);
	}
	// char a[20],b[20];
	// // scanf("%s %s\n",a,b);
	// gets(a);
	// gets(b);
	// printf("%s %s\n", a,b);
	return 0;
}