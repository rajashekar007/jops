#include <stdio.h>
#include <iostream>
using namespace std;
#define SZ 6145
// void add(int a[SZ][SZ],int i,int j,int n,int m)
// {
// 	if(i<n && i>=0 && j<m && j>=0 && a[i][j]!=-1)
// 		a[i][j]++;
// }
int a[SZ][SZ];
int main()
{
	int t,ind;
	scanf("%d",&t);
	for(ind=1;ind<=t;ind++)
	{
		int n,m,k;
		scanf("%d%d%d",&n,&m,&k);
		int i,j,l;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
				a[i][j]=0;
		}
		for(l=0;l<k;l++)
		{
			scanf("%d%d",&i,&j);
			int c,d;
			// add(a,i-1,j-1,n,m);
			// add(a,i-1,j,n,m);
			// add(a,i-1,j+1,n,m);
			// add(a,i,j-1,n,m);
			// a[i][j]=-1;
			// add(a,i,j+1,n,m);
			// add(a,i+1,j-1,n,m);
			// add(a,i+1,j,n,m);
			// add(a,i+1,j+1,n,m);
			a[i][j]=-1;
			c=i-1;d=j-1;
			if(c<n && c>=0 && d<m && d>=0 && a[c][d]!=-1)
				a[c][d]++;
			c=i-1;d=j;
			if(c<n && c>=0 && d<m && d>=0 && a[c][d]!=-1)
				a[c][d]++;
			c=i-1;d=j+1;
			if(c<n && c>=0 && d<m && d>=0 && a[c][d]!=-1)
				a[c][d]++;
			c=i;d=j-1;
			if(c<n && c>=0 && d<m && d>=0 && a[c][d]!=-1)
				a[c][d]++;
			c=i;d=j+1;
			if(c<n && c>=0 && d<m && d>=0 && a[c][d]!=-1)
				a[c][d]++;
			c=i+1;d=j-1;
			if(c<n && c>=0 && d<m && d>=0 && a[c][d]!=-1)
				a[c][d]++;
			c=i+1;d=j;
			if(c<n && c>=0 && d<m && d>=0 && a[c][d]!=-1)
				a[c][d]++;
			c=i+1;d=j+1;
			if(c<n && c>=0 && d<m && d>=0 && a[c][d]!=-1)
				a[c][d]++;
		}
		cout<<"Scenario #"<<ind<<":"<<endl<<endl;
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				if(a[i][j]==0)
					cout<<"-";
				else if(a[i][j]==-1)
					cout<<"*";
				else
					cout<<a[i][j];
			}
			cout<<endl<<endl;
		}
	}
	return 0;
}