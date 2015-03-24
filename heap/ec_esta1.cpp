#include <bits/stdc++.h>
using namespace std;
typedef priority_queue<int> mxpq;
typedef priority_queue<int,vector<int>,greater<int> > mnpq;
typedef long long ll;
mxpq l;
mnpq r;
void printmedian(double& cm,int e)
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
		ll rt=(ll)l.top()+r.top();
		if(rt%2==1)
		{
			cm=rt/2+.5;
			printf("%d.5\n",rt/2 );
		}
		else
		{
			cm=rt/2;
			printf("%d\n",rt/2 );			
		}
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
		ll rt=(ll)l.top()+r.top();
		if(rt%2==1)
		{
			cm=rt/2+.5;
			printf("%d.5\n",rt/2 );
		}
		else
		{
			cm=rt/2;
			printf("%d\n",rt/2 );			
		}

	}
	else
	{
		if(e>cm)
		{
			r.push(e);
			cm=r.top();
			printf("%d\n", r.top());
		}
		else
		{
			l.push(e);
			cm=l.top();
			printf("%d\n", l.top());
		}
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,i,a[100009];
		double cm=0;
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		for(i=0;i<n;i++)
		{
			printmedian(cm,a[i]);
			// printf("%lf\n", cm);
			// cout<<std::noshowpoint<<cm<<endl;
		}
		l=mxpq();
		r=mnpq();
	}
	return 0;
}