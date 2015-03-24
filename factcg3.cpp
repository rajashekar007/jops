#include <bits/stdc++.h>
using namespace std;
#define MAX 10000007
typedef long long ll;
int a[MAX];
vector<int> prime;
void gen()
{
	int i,j;
	for(i=2;i<=3163;)
	{
		if(a[i]==0)
		{
			a[i]=i;
			for(j=i*i;j<MAX;j+=i)
			{
				if(a[j]==0)
					a[j]=i;
			}	
		}
		if(i==2)
			i++;
		else
			i+=2;
	}
	for(i=3165;i<MAX;i+=2)
	{
		if(a[i]==0)
		{
			a[i]=i;
		}	
	}
}
int main()
{
	int n;
	gen();
	// printf("%d\n", prime.size());
	while(scanf("%d",&n)!=EOF)
	{
		if(n==1)
			printf("1\n");
		else
		{
			printf("1");
			int i;
			// printf("%d\n", a[n]);
			for(i=a[n];n>1;i=a[n])
			{
				int tp=i;
				while(n%tp==0)
				{
					printf(" x %d", tp);
					n=n/tp;
				}

			}
			if(n>1)
				printf(" x %d", n);
			printf("\n");
		}
	}
}