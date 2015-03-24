#include <stdio.h>
#define limit 100000
int primes[limit];
int sieve[limit];
int prime_size;
void gen_primes()
{
    prime_size=0;
    int i,up_bound=(int)sqrt((double)limit);
    for(i=2;i<limit;i++)
    {
        sieve[i]=1;
    }
    for(i=2;i<=up_bound;i++)
    {
        if(sieve[i])
        {
            int j;
            for(j=i*i;j<=limit;j+=i)
            {
                sieve[j]=0;
            }
        }
    }
    for(i=2;i<limit;i++)
    {
        if(sieve[i]==1 && i>999 && i<10000)
        {
            primes[prime_size++]=i;
        }
    }
}

int main()
{
	gen_primes();
	int n;
	scanf("%d",&n);
	while(n--)
	{
		int x,y;
		scanf("%d %d",&x,&y);

	}
	return 0;
}