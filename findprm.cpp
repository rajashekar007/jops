#include <bits/stdc++.h>
using namespace std;
#define MAX 10000007
typedef long long ll;
int a[MAX];
int cnt[MAX];
void gen()
{
	int i,j;
	for(i=3;i<=3163;i+=2)
	{
		if(a[i]==0)
		{
			for(j=i*i;j<MAX;j+=i)
				a[j]=1;
		}
	}
	cnt[2]=1;
	for(i=3;i<MAX;i++)
	{
		if(i%2!=0 && a[i]==0)
			cnt[i]=cnt[i-1]+1;
		else
			cnt[i]=cnt[i-1];
	}
}
int main()
{
	int t;
	gen();
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		printf("%d\n",cnt[n]-cnt[n/2]);
	}
}