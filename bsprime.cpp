#include <bits/stdc++.h>
using namespace std;
#define MAX 150000000
typedef long long ll;
int a[MAX],sb[MAX],nsbit[MAX],nbbit[MAX];
vector<int> prime;
void setbits()
{
	for(int i=2;i<MAX;i++)
		sb[i]=1+sb[i&(i-1)];
}
int ciel()
{
	// int l=0,r=MAX,mid=(l+r)/2;
	// while(l<r)
	// {
	// 	if(sb[])
	// }
}
int cnt1()
{

}
void gen()
{
	int i,j,k,l=2;
	prime.push_back(2);
	nsbit[0]=1;
	nbbit[0]=2;
	for(i=3;i<=(int)sqrt(MAX);i+=2)
	{
		if(a[i]==0)
		{
			k=prime.size();
			nbbit[k]=nbbit[k-1]+l;if(k<20)cout<<nbbit[k]<<",";
			nsbit[k]=nsbit[k-1]+sb[i];
			prime.push_back(i);
			for(j=i*i;j<MAX;j+=2*i)
				a[j]=1;	
		}
		if(((i+1)&i)==0)
			l++;
	}
	for(;i<MAX;i+=2)
	{
		if(a[i]==0)
		{
			k=prime.size();
			nbbit[k]=nbbit[k-1]+l;
			nsbit[k]=nsbit[k-1]+sb[i];
			prime.push_back(i);
		}
		if((i+1)&i==0)
			l++;		
	}
}
int main()
{
	gen();
	setbits();
	int i;
	cout<<nbbit[prime.size()-1]<<endl;
	// int t;
	// scanf("%d",&t);
	// while(t--)
	// {
	// 	int n;
	// 	scanf("%d",&n);
	// 	printf("%d\n", prime[n-1]);
	// }
}