#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
bool funx(pii a,pii b)
{
	return a.first<b.first;
}
bool funy(pii a,pii b)
{
	return a.second<b.second;
}
int min(int x,int y)
{
	return x<y?x:y;
}

float dist(pii a,pii b)
{
	int x=a.first-b.first,y=a.second-b.second;
	float r=sqrt((double)((ll)x*x)+((ll)y*y));cout<<r<<" ";
	return r;
}
float conq(vector<pii > a,int k,int *si,int *ei)
{
	float m=k,l;
	int i,j;
	sort(a.begin(),a.end(),funy);
	for(i=0;i<a.size()-1;i++)
	{
		for(j=i+1;j<a.size() && a[j].second-a[i].second<m;j++)
		{
			l=dist(a[i],a[j]);
			if(l<m)
			{	
				m=l;
				*si=i;
				*ei=j;
			}
		}
	}
	return m;
}
float div_conq(vector<pii > a,int s,int e,int* si,int *ei)
{
	if(e-s<3)
	{
		int i,j;
		float m=2000002,k;
		for(i=s;i<e;i++)
		{
			for(j=i+1;j<=e;j++)
			{
				k=dist(a[i],a[j]);
				if(k<m)
				{	
					m=k;
					*si=i;
					*ei=j;
				}
			}
		}
		return m;
	}
	else
	{
		int dl,dr,m=s+(e-s)/2,d,i,ti,tj,rd,rti,rtj;
		dl=div_conq(a,s,m,si,ei);
		ti=*si;
		tj=*ei;
		dr=div_conq(a,m+1,e,si,ei);
		if(dl<dr)
		{
			*si=ti;
			*ei=tj;
			d=dl;
		}
		else
			d=dr;
		vector<pii > strip;
		for(i=s;i<=e;i++)
		{
			if(abs(a[m].first-a[i].first)<d)
				strip.push_back(a[i]);
		}
		rd=conq(strip,d,&rti,&rtj);
		if(rd<d)
		{
			*si=rti;
			*ei=rtj;
		}
		return rd;
	}
}
int main()
{
	vector<pii > points;
	int n,i,x,y;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		points.push_back(make_pair(x,y));
	}
	sort(points.begin(),points.end(),funx);
	float ans=div_conq(points,0,n-1,&x,&y);
	printf("\n%d %d %.6f\n", x,y,ans);
	return 0;
}