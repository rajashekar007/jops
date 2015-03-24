#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstdlib>
#include <climits>
#include <cstring>
#include <stdint.h>
#include <unistd.h>
using namespace std;
typedef long long ll;
ll merge(int *a,int l,int m,int h,int temp[])
{
	ll cnt=0;
	int i=l,j=m+1,k=l;
	while(i<=m && j<=h)
	{
		if(a[i]<a[j])
			temp[k++]=a[i++];
		else
		{
			temp[k++]=a[j++];
			cnt=cnt+(m-i)+1;
		}
	}
	while(i<=m)
		temp[k++]=a[i++];
	while(j<=h)
		temp[k++]=a[j++];
	for(k=l;k<=h;k++)
		a[k]=temp[k];
	return cnt;

}
ll mergesort(int a[],int l,int h,int temp[])
{
	if(l==h)
		return 0;
	int m=(l+h)/2;
	ll lc,hc,mc;
	lc=mergesort(a,l,m,temp);
	hc=mergesort(a,m+1,h,temp);
	mc=merge(a,l,m,h,temp);
	return lc+hc+mc;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		map<string,int> mmap;
		int a[200007],i,temp[200007];
		// char c[25]={};
		string c;
		for(i=0;i<n;i++)
		{
			// scanf("%*s",c);//printf("%s\n", c);
			cin>>c;
			mmap[c]=i;
		}
		for(i=0;i<n;i++)
		{
			// scanf("%*s",c);//printf("%s\n", c);
			cin>>c;
			a[i]=mmap[c];//printf("%d\n", a[i]);
		}	
		printf("%lld\n", mergesort(a,0,n-1,temp));

	}
	return 0;
}