#include <bits/stdc++.h>
using namespace std;
#define limit 100007
vector<int> primes;
int sieve[limit];
int prime_size;
void gen_primes()
{
	prime_size=0;
	int i,up_bound=(int)sqrt((double)limit),j;
	primes.push_back(2);
	for(i=3;i<=up_bound;i+=2)
	{
		if(sieve[i]==0)
		{
			primes.push_back(i);
	        for(j=i*i;j<limit;j+=2*i)
                sieve[j]=1;
        }
    }
    for(;i<limit;i+=2)
    {
        if(sieve[i]==0)
            primes.push_back(i);
    }
}
void segmented_seive(int m,int n)
{
    int i;
    int a[100007]={};
    for(i=0;i<=n-m;i++)
		a[i]=1;
    int up_bound= (int)sqrt((double)n);
    for(i=0;(i<limit && primes[i]< up_bound );i++)
    {
        int temp=(m)/primes[i];
        temp=primes[i]*temp;
        int k=temp-m;
        if(k<0)
            k=k+primes[i];
        for(;k<=n-m && k>=0;k+=primes[i])
			a[k]=0;
    }
    for(i=0;i<=n-m;i++)
    {
        if(a[i])
            printf("%d\n",i+m );
    }
}
int main()
{
	gen_primes();
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int m,n;
		scanf("%d %d",&m,&n);
		if(n>100006)
			segmented_seive(m,n);
		else
		{
		    int i;
            for(i=0;i<100007;i++)
            {
                if(primes[i]>=m && primes[i]<=n)
                    printf("%d\n", primes[i]);
                else if(primes[i]>n)
                    break;
            }
        }
        printf("\n");
    }
    return 0;
} 