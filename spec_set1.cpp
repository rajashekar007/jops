#include <bits/stdc++.h>
using namespace std;
int a[100000001];
int main()
{
	int t,n,k,i,ans;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		ans=k-1;
		for(i=1;i<=n;i++)
			a[i]=1;
		a[k]=0;
		for(i=k;i<=n;i++)
		{
			if (i%k==0 && a[i/k]==1)
				a[i]=0;
			else
				ans+=1;
		}
		cout<<ans<<endl;
	}
	return 0;
}
