#include <bits/stdc++.h>
using namespace std;
typedef priority_queue<int> mxpq;
typedef priority_queue<int,vector<int>,greater<int> > mnpq;
typedef long long ll;
mxpq l;
mnpq r;
double printmedian(double cm,int e)
{
	if(l.size()>r.size())
	{
		if(e<cm)
		{
			r.push(l.top());
			l.pop();
			l.push(e);
		}
		else
		{
			r.push(e);
		}
		return ((double)l.top()+r.top())/2;
	}
	else if(r.size()>l.size())
	{
		if(e>cm)
		{
			l.push(r.top());
			r.pop();
			r.push(e);
		}
		else
			l.push(e);
		return ((double)l.top()+r.top())/2;
	}
	else
	{
		if(e>cm)
		{
			r.push(e);
			return r.top();
		}
		else
		{
			l.push(e);
			return l.top();
		}
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,i,a;
		double cm=0;
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&a);
			cm=printmedian(cm,a);
			printf("%g\n", cm);
			// cout<<std::noshowpoint<<cm<<endl;
		}
		l=mxpq();
		r=mnpq();
	}
	return 0;
}