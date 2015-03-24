#include <bits/stdc++.h>
using namespace std;
#define MAX 86028122
typedef long long ll;
int a[MAX];
vector<int> prime;
void gen()
{
	int i,j;
	prime.push_back(2);
	for(i=3;i<=(int)sqrt(MAX);i+=2)
	{
		if(a[i]==0)
		{
			prime.push_back(i);
			for(j=i*i;j<MAX;j+=2*i)
				a[j]=1;	
		}
	}
	for(;i<MAX;i+=2)
	{
		if(a[i]==0)
			prime.push_back(i);	
	}
}
int main()
{
	gen();
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		printf("%d\n", prime[n-1]);
	}
}