#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int dis[9][9][9][9];
int dx[8] = {2,1,-1,-2,-2,-1,1,2};
int dy[8] = {1,2,2,1,-1,-2,-2,-1};
int main()
{
	int t,x1,y1,x2,y2,a1,b1;
	for(int i=0;i<=7;i++)
	{
		for(int j=0;j<=7;j++)
		{
			for(int k=0;k<=7;k++)
			{
				for(int l=0;l<=7;l++)
				{
					if(i==k && j==l)
						dis[i][j][k][l]=0;
					else
						dis[i][j][k][l]=INT_MAX;
				}
			}
			for(int p=0;p<8;p++)
			{
				a1=i+dx[p];
				b1=j+dy[p];
				if(0<=a1 && a1<=7 && 0<=b1 && b1<=7)
				{
					dis[i][j][a1][b1]=1;
				}
			}
		}
	}
	for(int ki=0;ki<=7;ki++)
	{
		for(int kj=0;kj<=7;kj++)
		{
			for(int i=0;i<=7;i++)
			{
				for(int j=0;j<=7;j++)
				{
					for(int k=0;k<=7;k++)
					{
						for(int l=0;l<=7;l++)
						{
							if(dis[i][j][k][l]>(ll)dis[i][j][ki][kj]+dis[ki][kj][k][l])
								dis[i][j][k][l]=dis[i][j][ki][kj]+dis[ki][kj][k][l];
						}
					}
				}
			}
		}
	}

	scanf("%d",&t);
	while(t--)
	{
		char c1,c2;
		int x1,y1,x2,y2;
		scanf(" %c%d %c%d",&c1,&y1,&c2,&y2);
		x1=c1-97;x2=c2-97;y1--;y2--;
		printf("%d\n", dis[x1][y1][x2][y2]);
	}
	return 0;
}