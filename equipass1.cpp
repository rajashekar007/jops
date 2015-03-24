#include <bits/stdc++.h>
using namespace std;
map<string,int> mp[6];
void chk_rem(string c,int *vis,int d,
	int k,int l,string r)
{
	if(k==l)
	{
		map<string,int>::iterator it;
		it=mp[l].find(r);
		if(it!=mp[l].end())
		{
			int j=it->second;
			// cout<<"j = "<<j<<",";
			vis[j]=1;
			mp[l].erase(it);
		}
	}
	else
	{
		char a=c[k];
		if(a+d<='9')
		{
			a=a+d;
			// cout<<" a+d:"<<r+a<<" ";
			chk_rem(c,vis,d,k+1,l,r+a);
			a=a-d;
		}
		if(a-d>='0')
		{
			a=a-d;
			// cout<<" a-d:"<<r+a<<" ";
			chk_rem(c,vis,d,k+1,l,r+a);
			a=a+d;
		}

	}

}

int main()
{
	int t,ti;
	scanf("%d",&t);
	for(ti=1;ti<=t;ti++)
	{
		int n,i,l,j;
		scanf("%d",&n);
		for(i=0;i<6;i++)
			mp[i].clear();
		string c[n];
		int vis[n];
		for(i=0;i<n;i++)
		{
			vis[i]=0;
			string tp;
			cin>>tp;
			l=tp.length();
			mp[l][tp]=i;
			c[i]=tp;
		}
		int ans=0;
		for(i=0;i<n;i++)
		{
			if(vis[i]==0)
			{
				ans++;
				l=c[i].length();
				map<string,int>::iterator it;
				it=mp[l].find(c[i]);
				mp[l].erase(it);
				for(j=1;j<=9;j++)
				chk_rem(c[i],vis,j,0,l,"");
			}
		}
		printf("Case %d: %d\n",ti, ans);
	}
	return 0;
}