#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> pos;
void combinations(ll *a,int i,int n,ll sum)
{
	if(i==n)
	{
		pos.push_back(sum);
		return;
	}
	// if(a[i]!=0)
	combinations(a,i+1,n,sum+a[i]);
	combinations(a,i+1,n,sum);
}
int flor(ll f)
{
	int l=0,h=pos.size()-1;
	if(f>=pos[h])
		return h;
	else if(f==pos[l])
		return l;
	else if(f<pos[l])
		return -1;
	int m;
	while(l<=h)
	{
		m=(l+h)/2;
		if(m>0 && pos[m-1]<=f && pos[m]>f)
			return m-1;
		else if(m+1<pos.size() && pos[m]<=f && pos[m+1]>f)
			return m;
		else if(m>=0 && pos[m]>f)
			h=m-1;
		else
			l=m+1;
	}
	return -1;
}
int main()
{
	int n,m,i;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		pos.clear();
		ll a[n+m+1],temp,d;
		for(i=0;i<n;i++)
			scanf("%lld",&a[i]);
		for(;i<n+m;i++)
		{
			scanf("%lld",&temp);
			a[i]=-temp;
		}
		scanf("%lld",&d);
		combinations(a,0,n+m,0);
		sort(pos.begin(),pos.end());
		ll s,t;
		int f,e=-1;
		for(i=0;i<pos.size();i++)
		{
			// printf("%lld ",pos[i] );
			f=flor(pos[i]+d-1);
			// printf(" %d ,", f);
			if(f-i+1>e)
			{
				e=f-i+1;
				s=pos[i];
				t=pos[i]+d-1;
			}
		}
		printf("%lld %lld %d\n", s,t,e);
	}
	return 0;
}