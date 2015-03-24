#include <bits/stdc++.h>
using namespace std;
// typedef pair<double,double> pdd;
struct pdd
{
	double first,second;
};
double dist(pdd a,pdd b)
{
	return (sqrt((a.first-b.first)*(a.first-b.first)+
		(a.second-b.second)*(a.second-b.second)));
}
bool color2(int c[15][15],int n,int i,int *color)
{
	if(i==n)
	{
		int j,k;
		for(j=0;j<n;j++)
		{
			for(k=j+1;k<n;k++)
			{
				if(c[j][k] && color[j]==color[k])
					return false;
			}
		}
		return true;
	}
	color[i]=0;
	bool x=color2(c,n,i+1,color);
	color[i]=1;
	bool y=color2(c,n,i+1,color);
	return x||y;
}
bool color3(int c[15][15],int n,int i,int *color)
{
	if(i==n)
	{
		int j,k;
		for(j=0;j<n;j++)
		{
			for(k=j+1;k<n;k++)
			{
				if(c[j][k] && color[j]==color[k])
					return false;
			}
		}
		return true;
	}
	color[i]=0;
	bool x=color3(c,n,i+1,color);
	color[i]=1;
	bool y=color3(c,n,i+1,color);
	color[i]=2;
	bool z=color3(c,n,i+1,color);
	return x||y||z;
}
int main()
{
	int n,i,j,t=1;
	scanf("%d",&n);
	while(n!=0)
	{
		pdd cord[15];
		for(i=0;i<n;i++)
			scanf("%lf%lf",&(cord[i].first),&(cord[i].second));
		int close[15][15]={},flag=1,ans=0,color[15];
		for(i=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)
			{
				if(dist(cord[i],cord[j])-20<=0)
				{
					close[i][j]=1;
					flag=0;
				}
			}
		}
		if(flag)
			ans=1;
		else
		{
			if(color2(close,n,0,color))
				ans=2;
			else if(color3(close,n,0,color))
				ans=3;
			else
				ans=4;
		}
		printf("The towers in case %d can be covered in %d frequencies.\n",t,ans );
		t++;
		scanf("%d",&n);
	}
	return 0;
}