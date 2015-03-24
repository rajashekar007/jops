#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int isprime(ll a)
{
	ll i;
	if(a==1)
		return 0;
	for(i=2;i*i<=a;i++)
	{
		if(a%i==0)
			return 0;
	}
	return 1;
}
void printnp(int n)
{
	map<int,int> ans;
	map<int,int>::iterator it;
	ans[1]=1;
	if(!isprime(n))
	{
		ans[n]=1;
	}
	for(int i=2;i*i<=n;i++)
	{
		if(n%i==0)
		{
			if(!isprime(i))
			{
				ans[i]=1;
			}
			if(!isprime(n/i))
			{
				ans[n/i]=1;
			}
		}
	}
	for(it=ans.begin();it!=ans.end();it++)
	{
		printf("%d ", it->first);
	}
	printf("\n");
}
#define limit 10007
vector<int> primes;
int sieve[limit];
void gen_primes()
{
	int i,up_bound=(int)sqrt((double)limit),j;
	sieve[2]=2;
	for(i=3;i<=up_bound;i+=2)
	{
		if(sieve[i]==0)
		{
			sieve[i]=i;
			for(j=i*i;j<limit;j+=2*i)
			{
				if(sieve[j]==0)
					sieve[j]=i;
			}
		}
	}
}
int main()
{
	gen_primes();
	int t,i,j;
	map<int,int> ar[10001];
	map<int,int>::iterator it;
	for(i=2;i<10001;i++)
	{
		j=i;
		int p,cnt=0;
		while(j%2==0)
		{
			j=j/2;
			cnt++;
		}
		if(cnt!=0)
		ar[i][2]=cnt;
		for(p=sieve[j];p!=0 && p!=j;p=sieve[j])
		{
			cnt=0;
			for(;p!=0 && j%p==0;j=j/p)
				cnt++;
			if(cnt!=0)
			ar[i][p]=cnt;
		}
		if(p!=0)
		ar[i][p]=1;
	}
	for(i=20;i<100;i++)
	{
		cout<<i<<" - ";
		for(it=ar[i].begin();it!=ar[i].end();it++)
			cout<<it->first<<"-"<<it->second<<" ";
		cout<<endl;
	}
	cout<<"end";
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
//find prime factors using vector of arrays for each x <=10000
		char c[20]={};
		for(i=0;i<n;i++)
		{
			scanf("%s",c);
			if(c[0]=='U')
			{
				scanf("%s",c);
				if(c[0]=='A')
				{
					
				}
				else
				{

				}
			}
			else
			{
				
			}
		}

	}
}