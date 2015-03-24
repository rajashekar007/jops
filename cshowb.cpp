#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,p,i,x,f;
	scanf("%d%d",&n,&p);
	vector<int> a[7];
	int len[7]={};
	long long ans=0;
	for(i=0;i<n;i++)
	{
		scanf("%d%d",&x,&f);
		if(len[x]==0 || a[x][len[x]-1]<f)
		{
			a[x].push_back(f);
			len[x]++;
			ans++;
		}
		else if(a[x][0]>f)
		{
			a[x][0]=f;
			ans+=len[x]+1;
			len[x]=1;
		}
		else
		{
			int l=0,h=len[x]-1,m;
			while (l<=h)
			{
				m=l+(h-l)/2;
				if(a[x][m]==f)
				{
					ans+=len[x]-1-m;
					len[x]=m+1;
					break;
				}
				else if(a[x][m]<f)
				{
					if(m+1<=h && a[x][m+1]>f)
					{
						ans+=len[x]-m;
						len[x]=m+2;
						a[x][m+1]=f;
						break;
					}
					l=m+1;
				}
				else
				{
					if(m-1>=l && a[x][m-1]<f)
					{
						ans+=len[x]-m+1;
						len[x]=m+1;
						a[x][m]=f;
						break;
					}
					h=m-1;
				}
			}

		}
	}
	printf("%lld\n", ans);
	return 0;
}