#include <bits/stdc++.h>
using namespace std;
int bin_ceil(vector<int> a,int s)
{
	int l=0,h=a.size()-1;
	if(s>a[h])
		return -1;
	else if(s==a[h])
		return h;
	else if(s<=a[l])
		return a[0];
	int m;
	while(l<=h)
	{
		m=(l+h)/2;
		if(a[m]==s)
			return s;
		else if(a[m]>s && a[m-1]<s)
			return m;
		else if(a[m]<s && a[m+1]>=s)
			return m+1;
		else if(a[m]>s)
			h=m-1;
		else
			l=m+1;
	}
	return -1;

}
int lis(int *a,int n)
{
	int i;
	vector<int> ans;
	ans.push_back(a[0]);
	for(i=1;i<n;i++)
	{
		if(ans[0]>a[i])
			ans[0]=a[i];
		else if(ans.size()>0 && ans[ans.size()-1]<a[i])
			ans.push_back(a[i]);
		else
		{
			ans[bin_ceil(ans,a[i])]=a[i];
		}
	}
	return ans.size();
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,a[100009],i;
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		printf("%d\n", lis(a,n));
	}
	return 0;
}