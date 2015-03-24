#include <bits/stdc++.h>
using namespace std;
int sumofdigits(int d)
{
	int r=0;
	while(d>0)
	{
		r+=d%10;
		d=d/10;
	}
	return r;
}
int main()
{
	int n=1000000,a[1000000]={},i,j,cnt=0;
	for(i=1;i<n;i++)
	{
		if(a[i]==0)
		{
			printf("%d\n", i);
			cnt++;
		}
		j=i+sumofdigits(i);
		if(j<n)
			a[j]=1;
	}
	printf("cnt = %d\n", cnt);
	return 0;
}