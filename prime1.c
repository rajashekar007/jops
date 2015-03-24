#include <stdio.h>
#include <math.h>
#define limit 100007
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
        if(sieve[i]==1)
        {
            primes[prime_size++]=i;
        }
    }
}

void segmented_seive(int m,int n)
{
    // printf("inside seg seive\n");
    int i;
    int a[100007]={};
    for(i=0;i<n;i++)
    {
        a[i]=1;
    }
    int up_bound= (int)sqrt((double)n);
    for(i=0;(i<limit && primes[i]< up_bound );i++)
    {
        int temp=(m)/primes[i];
        // printf("%d,", primes[i]);
        temp=primes[i]*temp;
        int k=temp-m;
        if(k<0)
            k=k+primes[i];//printf("k=%d, n-m=%d , primes[i]=%d\n", k,n-m,primes[i]);
        for(;k<=n-m && k>=0;k+=primes[i])
        {
            a[k]=0;
        }
    }
    // printf("The primes are\n");
    for(i=0;i<=n-m;i++)
    {
        // printf("%d\n", i);
        if(a[i])
        {
            printf("%d\n",i+m );
        }
    }
    // printf("exiting seg\n");
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
        {
            segmented_seive(m,n);
            printf("after function call\n");
        }
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
    }
	return 0;
} 