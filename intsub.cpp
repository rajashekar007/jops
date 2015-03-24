#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int mpow(int b,int e,int m)
{
	if(e==0)
		return 1;
	int r=mpow(b,e/2,m),t;
	t=((ll)r*r)%m;
	if (e%2)
		t=((ll)t*b)%m;
	return t;
}
int main()
{
	int t,i,md=1000000007;
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		int n,n2,ans=0,j,k;
		scanf("%d",&n);
		n2=2*n;
		for(j=1;j<=n2;j++)
		{
			k=n2-j-n2/j+2;
			ans=((ll)ans+mpow(2,k-1,md))%md;
		}
		ans=((ll)mpow(2,n2,md)-ans+md)%md;
		printf("Case %d: %d\n", i,ans-1);
	}
	return 0;
}

// t=input()
// m=1000000007
// for j in range(1,t+1):
// 	n=input()
// 	n2=2*n
// 	ans=0
// 	i=1
// 	while i<=n2:
// 		k=n2-i-n2/i+2
// 		ans=(ans+(2**(k-1))%m)%m
// 		i+=1
// 	ans=((2**n2)%m-(ans)%m+m)%m
// 	print 'Case %d: %d' %(j,ans-1)
// 	print ''